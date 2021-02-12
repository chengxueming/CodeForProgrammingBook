function double(value, success, failure) {
    setTimeout(() => {
        try {
            if (typeof value !== 'number') {
                throw 'Must provide number as first argument'
            }
            success(2 * value)
        } catch (e) {
            failure(e)
        }
    }, 1000)
}

const successCallBack = (x) => {
    double(x, (y) => console.log(`success: ${y}`))
}
const failureCallBack = (e) => console.log(`Failure: ${e}`)

double(3, successCallBack, failureCallBack)