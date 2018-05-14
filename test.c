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

NAPI_METHOD(uint8_array_test) {
  NAPI_ARGV(1);

  uint8_t* inbound;
  size_t byte_len, arr_len;
  NAPI_GET_UINT8_ARRAY(argv[0], inbound, &byte_len, &arr_len);

  napi_value outbound;
  NAPI_CREATE_UINT8_ARRAY(inbound, byte_len, arr_len, &outbound);

  return outbound;
}

NAPI_METHOD(int16_array_test) {
  NAPI_ARGV(1);

  int16_t* inbound;
  size_t byte_len, arr_len;
  NAPI_GET_INT16_ARRAY(argv[0], inbound, &byte_len, &arr_len);

  napi_value outbound;
  NAPI_CREATE_INT16_ARRAY(inbound, byte_len, arr_len, &outbound);

  return outbound;
}

NAPI_METHOD(uint16_array_test) {
  NAPI_ARGV(1);

  uint16_t* inbound;
  size_t byte_len, arr_len;
  NAPI_GET_UINT16_ARRAY(argv[0], inbound, &byte_len, &arr_len);

  napi_value outbound;
  NAPI_CREATE_UINT16_ARRAY(inbound, byte_len, arr_len, &outbound);

  return outbound;
}

NAPI_METHOD(int32_array_test) {
  NAPI_ARGV(1);

  int32_t* inbound;
  size_t byte_len, arr_len;
  NAPI_GET_INT32_ARRAY(argv[0], inbound, &byte_len, &arr_len);

  napi_value outbound;
  NAPI_CREATE_INT32_ARRAY(inbound, byte_len, arr_len, &outbound);

  return outbound;
}

NAPI_METHOD(uint32_array_test) {
  NAPI_ARGV(1);

  uint32_t* inbound;
  size_t byte_len, arr_len;
  NAPI_GET_UINT32_ARRAY(argv[0], inbound, &byte_len, &arr_len);

  napi_value outbound;
  NAPI_CREATE_UINT32_ARRAY(inbound, byte_len, arr_len, &outbound);

  return outbound;
}

NAPI_METHOD(float32_array_test) {
  NAPI_ARGV(1);

  float* inbound;
  size_t byte_len, arr_len;
  NAPI_GET_FLOAT32_ARRAY(argv[0], inbound, &byte_len, &arr_len);

  napi_value outbound;
  NAPI_CREATE_FLOAT32_ARRAY(inbound, byte_len, arr_len, &outbound);

  return outbound;
}

NAPI_METHOD(float64_array_test) {
  NAPI_ARGV(1);

  double* inbound;
  size_t byte_len, arr_len;
  NAPI_GET_FLOAT64_ARRAY(argv[0], inbound, &byte_len, &arr_len);

  napi_value outbound;
  NAPI_CREATE_FLOAT64_ARRAY(inbound, byte_len, arr_len, &outbound);

  return outbound;
}

NAPI_INIT() {
  NAPI_EXPORT_FUNCTION(int8_array_test);
  NAPI_EXPORT_FUNCTION(uint8_array_test);
  NAPI_EXPORT_FUNCTION(int16_array_test);
  NAPI_EXPORT_FUNCTION(uint16_array_test);
  NAPI_EXPORT_FUNCTION(int32_array_test);
  NAPI_EXPORT_FUNCTION(uint32_array_test);
  NAPI_EXPORT_FUNCTION(float32_array_test);
  NAPI_EXPORT_FUNCTION(float64_array_test);
}
