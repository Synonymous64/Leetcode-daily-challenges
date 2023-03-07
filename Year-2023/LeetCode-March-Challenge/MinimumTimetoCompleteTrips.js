var minimumTime = function (time, totalTrips) {
    const check = (time, mid, totalTrips) => {
        let trips = 0;
        for (let x of time) {
            trips += Math.trunc(mid / x);
            if (trips >= totalTrips) return true;
        }
        return false;
    }
    let n = time.length;
    time.sort((a, b) => a - b);
    let low = time[0], high = time[n - 1] * totalTrips;

    while (low < high) {
        let mid = low + Math.trunc((high - low) / 2);
        if (check(time, mid, totalTrips)) high = mid;
        else low = mid + 1;
    }
    return low;
};

let time = [1,2,3], totalTrips = 5;
console.log(minimumTime(time, totalTrips));