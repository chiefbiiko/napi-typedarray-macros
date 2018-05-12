#ifndef NAPI_TYPEDARRAY_MACROS
#define NAPI_TYPEDARRAY_MACROS

#define NAPI_GET_INT8_ARRAY(typedarray, arr, byte_len, arr_len) \
  NAPI_GET_TYPEDARRAY(typedarray, arr, byte_len, arr_len);

#define NAPI_CREATE_INT8_ARRAY(arr, byte_len, arr_len, typedarray) \
  NAPI_CREATE_TYPEDARRAY(int8_t*, arr, byte_len, arr_len, napi_int8_array, typedarray);

#define NAPI_GET_INT32_ARRAY(typedarray, arr, byte_len, arr_len) \
  NAPI_GET_TYPEDARRAY(typedarray, arr, byte_len, arr_len);

#define NAPI_CREATE_INT32_ARRAY(arr, byte_len, arr_len, typedarray) \
  NAPI_CREATE_TYPEDARRAY(int32_t*, arr, byte_len, arr_len, napi_int32_array, typedarray);


/*
  get any type of napi typedarray as a C pointer

  NAPI_GET_TYPEDARRAY(napi_value typedarray, ?_t* arr, size_t* byte_len, size_t* arr_len);

  [in] typedarray: napi_value
  [out] arr: C arr pointer
  [out] byte_len: the length of the created C array in bytes
  [out] arr_len: the number of items of the created C array
  NOTE: assuming that byte_offset is 0
*/
#define NAPI_GET_TYPEDARRAY(typedarray, arr, byte_len, arr_len) \
  ({ \
  napi_status in_status; \
  napi_typedarray_type type; \
  napi_value in_arr_buf; \
  size_t offset; \
  in_status = napi_get_typedarray_info(env, typedarray, &type, arr_len, NULL, &in_arr_buf, &offset); \
  in_status = napi_get_arraybuffer_info(env, in_arr_buf, (void**) &arr, byte_len); \
  in_status; \
  })

/*
  create any type of napi typedarray from a C pointer

  NAPI_CREATE_TYPEDARRAY(c_type, ?_t* arr, size_t byte_len, size_t arr_len, napi_typedarray_type typedarray_type, napi_value* typedarray);

  [in] c_type: type of the c pointer
  [in] arr: C arr pointer
  [in] byte_len: the length of the C array in bytes
  [in] arr_len: the number of items of the C array
  [in] typedarray_type: napi_typedarray_type
  [out] typedarray: napi_value for the new typed array
  NOTE: assuming that byte_offset is 0
*/
#define NAPI_CREATE_TYPEDARRAY(c_type, arr, byte_len, arr_len, typedarray_type, typedarray) \
  ({ \
  napi_status out_status; \
  napi_value out_arr_buf; \
  void* out_arr_ptr = NULL; \
  out_status = napi_create_arraybuffer(env, byte_len, &out_arr_ptr, &out_arr_buf); \
  out_status = napi_create_typedarray(env, typedarray_type, arr_len, out_arr_buf, 0, typedarray); \
  c_type typed_arr_ptr = (c_type) (out_arr_ptr); \
  for (size_t i = 0; i < arr_len; i++) typed_arr_ptr[i] = arr[i]; \
  out_status; \
  })

#endif
