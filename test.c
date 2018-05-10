#include <node_api.h>
#include "napi-macros.h"
#include "napi_typedarray_macros.h"

NAPI_METHOD(int8_array_test) {
  NAPI_ARGV(1);

  size_t c_byte_len, c_arr_len;
  NAPI_GET_INT8_ARRAY(argv[0], inbound, &c_byte_len, &c_arr_len);

  NAPI_CREATE_INT8_ARRAY(inbound, c_byte_len, c_arr_len, outbound);

  return outbound;
}

NAPI_INIT() {
  NAPI_EXPORT_FUNCTION(int8_array_test);
}
