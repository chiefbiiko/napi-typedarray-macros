#include <node_api.h>
#include "napi-macros.h"
#include "napi_typedarray_macros.h"

NAPI_METHOD(int8_array_test) {
  NAPI_ARGV(1);

  int8_t* inbound;
  size_t byte_len, arr_len;
  NAPI_GET_INT8_ARRAY(argv[0], inbound, &byte_len, &arr_len);

  napi_value outbound;
  NAPI_CREATE_INT8_ARRAY(inbound, byte_len, arr_len, &outbound);

  return outbound;
}

NAPI_INIT() {
  NAPI_EXPORT_FUNCTION(int8_array_test);
}
