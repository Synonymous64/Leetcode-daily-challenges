var shipWithinDays = function (weights, days) {

    const isValid = (weights, days, capacity) => {
        let requiredDays = 1;
        let currWeight = 0;

        for (let x of weights) {
            if (currWeight + x > capacity) {
                currWeight = 0;
                requiredDays++;
            }
            currWeight += x;
        }
        if (requiredDays > days) return false;
        else return true;
    }
    let low = 0, high = 0;
    for (let x of weights) {
        low = Math.max(low, x);
        high += x;
    }
    let res = high;
    while (low <= high) {
        let mid = low + Math.trunc((high - low) / 2);
        if (isValid(weights, days, mid)) {
            res = mid;
            high = mid - 1;
        } else low = mid + 1;
    }
    return res;
};
let weights = [3,2,2,4,1,4], days = 3;
console.log(shipWithinDays(weights, days));