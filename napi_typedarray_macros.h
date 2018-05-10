#ifndef NAPI_TYPEDARRAY_MACROS
#define NAPI_TYPEDARRAY_MACROS

#define NAPI_GET_INT8_ARRAY(typedarray, c_pointer, c_byte_len, c_arr_len) \
  NAPI_GET_TYPEDARRAY(typedarray, c_pointer, c_byte_len, c_arr_len);

#define NAPI_CREATE_INT8_ARRAY(c_pointer, c_byte_len, c_arr_len, typedarray) \
  NAPI_CREATE_TYPEDARRAY(int8_t *, c_pointer, c_byte_len, c_arr_len, napi_int8_array, typedarray);

/*
  get any type of napi typedarray as a C pointer

  NAPI_GET_TYPEDARRAY(napi_value typedarray, ?_t* c_pointer, size_t* c_byte_len, size_t* c_arr_len);

  [in] typedarray: napi_value
  [out] c_pointer: C arr pointer
  [out] c_byte_len: the length of the created C array in bytes
  [out] c_arr_len: the number of items of the created C array
  NOTE: assuming that byte_offset is 0
*/
#define NAPI_GET_TYPEDARRAY(typedarray, c_pointer, c_byte_len, c_arr_len) \
  napi_status in_status; \
  napi_typedarray_type type; \
  napi_value in_arr_buf; \
  size_t offset; \
  in_status = napi_get_typedarray_info(env, typedarray, &type, c_arr_len, NULL, &in_arr_buf, &offset); \
  if (in_status != napi_ok) napi_throw_error(env, NULL, "napi_get_typedarray_info failed"); \
  in_status = napi_get_arraybuffer_info(env, in_arr_buf, (void**) &c_pointer, c_byte_len); \
  if (in_status != napi_ok) napi_throw_error(env, NULL, "napi_get_arraybuffer_info failed");

/*
  create any type of napi typedarray from a C pointer

  NAPI_CREATE_TYPEDARRAY(c_type, ?_t* c_pointer, size_t c_byte_len, size_t c_arr_len, napi_typedarray_type typedarray_type, napi_value* typedarray);

  [in] c_type: type of the c pointer
  [in] c_pointer: C arr pointer
  [in] c_byte_len: the length of the C array in bytes
  [in] c_arr_len: the number of items of the C array
  [in] typedarray_type: napi_typedarray_type
  [out] typedarray: napi_value for the new typed array
  NOTE: assuming that byte_offset is 0
*/
#define NAPI_CREATE_TYPEDARRAY(c_type, c_pointer, c_byte_len, c_arr_len, typedarray_type, typedarray) \
  napi_status out_status; \
  napi_value out_arr_buf; \
  void* arr_ptr = NULL; \
  out_status = napi_create_arraybuffer(env, c_byte_len, &arr_ptr, &out_arr_buf); \
  if (out_status != napi_ok) napi_throw_error(env, NULL, "napi_create_arraybuffer failed"); \
  out_status = napi_create_typedarray(env, typedarray_type, c_arr_len, out_arr_buf, 0, typedarray); \
  if (out_status != napi_ok) napi_throw_error(env, NULL, "napi_create_typedarray failed"); \
  c_type typed_arr_ptr = (c_type) (arr_ptr); \
  for (size_t i = 0; i < c_arr_len; i++) typed_arr_ptr[i] = c_pointer[i];

#endif
