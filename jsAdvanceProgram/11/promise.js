

ppending = Promise.all([new Promise(()=>{})])
// console.log(ppending)
Promise.all([Promise.resolve(1), Promise.resolve(), Promise.resolve(3)]).then((values) => {
    setTimeout(console.log, 0, values)
})

Promise.all([Promise.resolve(1), Promise.reject(3333), new Promise((resolve, reject) => setTimeout(reject, 1000, 0))]).catch((values) => {
    setTimeout(console.log, 0, values)
}).catch((values) => {
    setTimeout(console.log, 0, values)
})

p = Promise.all([Promise.resolve(1), Promise.reject(3333), new Promise((resolve, reject) => setTimeout(reject, 1000, 0))]).catch((values) => {
    setTimeout(console.log, 0, values)
})

Promise.race([
    new Promise((resolve, reject) => setTimeout(resolve, 1000, 1000)),
    new Promise((resolve, reject) => setTimeout(resolve, 3000, 3000)),
]).then(value => {
    return value + 1
}).then(value => {
    return value + 2
}).then(console.log)

console.log(p)