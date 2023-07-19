var eraseOverlapIntervals = function (intervals) {
    intervals.sort((a, b) => a[1] - b[1]);

    let prev = intervals[0];
    let res = -1;

    for (let x of intervals) {
        if (x[0] < prev[1] && x[1] <= prev[1]) {
            res++;
            prev = x;
        } else if (x[0] < prev[1] && x[1] > prev[1]) res++;
        else prev = x;
    }
    return res;
};

let intervals = [[1,2],[2,3],[3,4],[1,3]];
console.log(eraseOverlapIntervals(intervals));