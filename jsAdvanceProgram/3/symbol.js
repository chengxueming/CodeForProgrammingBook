let s1 = Symbol("foo")
let s2 = Symbol("bar")
let s3 = Symbol("baz")

let o = {
    [s1]: 'foo val'
}

Object.defineProperty(o, s2, {value:'bar val'})
o['foo'] = 'foo'
o['bar'] = 'bar'

console.log(Object.getOwnPropertyNames(o))
console.log(Object.getOwnPropertySymbols(o))
console.log(Object.getOwnPropertyDescriptor(o))

// Symbol.asyncIterator
class Emitter {
    constructor(max) {
        this.asyncIndex = 0
        this.max = max
    }

    async *[Symbol.asyncIterator]() {
        while(this.asyncIndex < this.max) {
            yield new Promise((resolve, reject) => {resolve(this.asyncIndex++)})
        }
    }
}

let emitter = new Emitter(5)
for await (const x of emitter) {
    console.log(x)
}

// Symbol.hasInstance
class Bar{}

class Baz extends Bar{
    // static [Symbol.hasInstance]() {
    //     return false
    // }
}

b = new Baz()
console.log(b instanceof Bar)
console.log(b instanceof Baz)

// Symbol.isConcatSpreadable
let initial = ['foo']
let array = ['bar']
console.log(initial.concat(array))
array[Symbol.isConcatSpreadable] = false
console.log(initial.concat(array))
