var maxRunTime = function (n, batteries) {
    let low = 1, high = 0;
    for (let x of batteries)
        high += x;

    const validate = (time, batteries, n) => {
        let total = 0;

        for (let x of batteries)
            total += Math.min(time, x);

        return total >= time * n;
    }

    let res = 0;

    while (low <= high) {
        let mid = low + Math.trunc((high - low) / 2);
        if (validate(mid, batteries, n)) {
            low = mid + 1;
            res = mid;
        } else high = mid - 1;
    }

    return res;
};

let n = 2, batteries = [3,3,3];
console.log(maxRunTime(n, batteries));