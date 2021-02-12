let p1 = new Promise((resove, reject) => resove())
setTimeout(console.log, 0, p1)
let p2 = new Promise((resove, reject) => reject())
setTimeout(console.log, 0, p2)
let p = new Promise((resove, reject) => setTimeout(resove, 1000))
setTimeout(console.log, 0, p)

function delayPrintNumbers(start) {
    new Promise((resolve, reject) => {
        console.log(start)
        setTimeout(resolve, 1000, start + 1)    
    }).then((value) => new Promise((resolve, reject) => {
        console.log(value)
        setTimeout(resolve, 1000, value + 1)    
    })).then((value) => new Promise((resolve, reject) => {
        console.log(value)
        setTimeout(resolve, 1000)    
    })).finally(() => {
        console.log("finish promise")
    })
}


p3 = new Promise((resolve, reject) => resolve())
console.log("1")
p3.then(() => console.log("3"))
console.log("2")

