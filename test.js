var tape = require('tape')

var {
  int8_array_test,
  uint8_array_test,
  int16_array_test,
  uint16_array_test,
  int32_array_test,
  uint32_array_test,
  float32_array_test,
  float64_array_test
} = require('node-gyp-build')(__dirname)

tape('int8array', function (t) {
  var inbound = new Int8Array([ 1, 2, 3, 4 ])
  var outbound = int8_array_test(inbound)
  t.is(outbound.constructor, inbound.constructor, 'same type')
  t.same(outbound, inbound, 'identity')
  t.end()
})

tape('uint8array', function (t) {
  var inbound = new Uint8Array([ 1, 2, 3, 4 ])
  var outbound = uint8_array_test(inbound)
  t.is(outbound.constructor, inbound.constructor, 'same type')
  t.same(outbound, inbound, 'identity')
  t.end()
})

tape('int16array', function (t) {
  var inbound = new Int16Array([ 1, 2, 3, 4 ])
  var outbound = int16_array_test(inbound)
  t.is(outbound.constructor, inbound.constructor, 'same type')
  t.same(outbound, inbound, 'identity')
  t.end()
})

tape('uint16array', function (t) {
  var inbound = new Uint16Array([ 1, 2, 3, 4 ])
  var outbound = uint16_array_test(inbound)
  t.is(outbound.constructor, inbound.constructor, 'same type')
  t.same(outbound, inbound, 'identity')
  t.end()
})

tape('int32array', function (t) {
  var inbound = new Int32Array([ 1, 2, 3, 4 ])
  var outbound = int32_array_test(inbound)
  t.is(outbound.constructor, inbound.constructor, 'same type')
  t.same(outbound, inbound, 'identity')
  t.end()
})

tape('uint32array', function (t) {
  var inbound = new Uint32Array([ 1, 2, 3, 4 ])
  var outbound = uint32_array_test(inbound)
  t.is(outbound.constructor, inbound.constructor, 'same type')
  t.same(outbound, inbound, 'identity')
  t.end()
})

tape('float32array', function (t) {
  var inbound = new Float32Array([ 1, 2, 3, 4 ])
  var outbound = float32_array_test(inbound)
  t.is(outbound.constructor, inbound.constructor, 'same type')
  t.same(outbound, inbound, 'identity')
  t.end()
})

tape('float64array', function (t) {
  var inbound = new Float64Array([ 1, 2, 3, 4 ])
  var outbound = float64_array_test(inbound)
  t.is(outbound.constructor, inbound.constructor, 'same type')
  t.same(outbound, inbound, 'identity')
  t.end()
})
