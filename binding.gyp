{
  "targets": [ {
    "target_name": "napi_typedarray_macros_test",
    "include_dirs": [
      "<!(node -e \"require('napi-macros')\")",
      "<!(node -e \"require('./index')\")"
    ],
    "libraries": [
      "-lmsvcrt.lib"
    ],
    "sources": [ "./test.c" ]
  } ]
}
