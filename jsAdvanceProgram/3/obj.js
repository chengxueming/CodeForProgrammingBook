class Test {
    constructor() {
        this[Symbol.toStringTag] = 'Testing'
    }
    toString() {
        return 'test to string'
    }
    valueOf() {
        return 'test value of'
    }
}
let t = new Test()
console.log(String(t))