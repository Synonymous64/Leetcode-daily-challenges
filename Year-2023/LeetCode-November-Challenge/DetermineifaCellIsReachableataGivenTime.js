var isReachableAtTime = function (sx, sy, fx, fy, t) {
    let xDff = Math.abs(fx - sx), yDiff = Math.abs(fy - sy);
    if (xDff === 0 && yDiff === 0 && t === 1) return false;
    return Math.min(xDff, yDiff) + Math.abs(xDff - yDiff) <= t;
};

let sx = 2, sy = 4, fx = 7, fy = 7, t = 6;
console.log(isReachableAtTime(sx, sy, fx, fy, t));