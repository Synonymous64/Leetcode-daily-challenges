var bestClosingTime = function (customers) {
    let n = customers.length;
    let penality = 0;

    for (let x of customers)
        if (x === 'N') penality++;

    let res = n;
    let mini = penality;

    for (let i = n - 1; i >= 0; --i) {
        if (customers[i] === 'Y') penality++;
        else penality--;
        if (penality <= mini) {
            mini = penality;
            res = i;
        }
    }

    return res;
};

let customers = "YYNY";
console.log(bestClosingTime(customers));