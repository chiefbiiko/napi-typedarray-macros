var tape = require('tape')

var {
  int8_array_test,
  int32_array_test
} = require('node-gyp-build')(__dirname)

tape('int8array', function (t) {
  var inbound = new Int8Array([ 1, 2, 3, 4 ])
  var outbound = int8_array_test(inbound)
  t.same(outbound, inbound, 'round trip identity')
  t.end()
})

tape('int32array', function (t) {
  var inbound = new Int32Array([ 1, 2, 3, 4 ])
  var outbound = int32_array_test(inbound)
  t.same(outbound, inbound, 'round trip identity')
  t.end()
})
