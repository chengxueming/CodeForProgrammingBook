function simpleTag(strings, ...expressions) {
    console.log(strings)
    for(const expression of expressions) {
        console.log(expression)
    }
    return strings[0] + expressions.map((e, i) => {
        return `${e}${strings[i + 1]}`
    }).join(" ")
}
let a = 11, b =2
console.log(simpleTag`${a} + ${b} = ${a + b}`)