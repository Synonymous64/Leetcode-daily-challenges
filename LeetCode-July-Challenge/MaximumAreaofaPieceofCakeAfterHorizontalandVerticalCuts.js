var maxArea = function(h, w, horizontalCuts, verticalCuts) {
    horizontalCuts.sort();
    verticalCuts.sort();

    let lenH = horizontalCuts.length;
    let lenV = verticalCuts.length;

    let maxHor = Math.max(horizontalCuts[0], h - horizontalCuts[lenH - 1]);
    for(let i = 1; i < lenH; ++i){
        maxHor = Math.max(maxHor, horizontalCuts[i] - horizontalCuts[i - 1]);
    }

    let maxVec = Math.max(verticalCuts[0], w - verticalCuts[lenV - 1]);
    for(let i = 1; i < lenV; ++i){
        maxVec = Math.max(maxVec, verticalCuts[i] - verticalCuts[i - 1]);
    }
    return BigInt(maxVec) * BigInt(maxHor) % 1000000007n
};
let h = 1000000000, w = 1000000000, horizontalCuts = [2], verticalCuts = [2];
console.log(maxArea(h, w, horizontalCuts, verticalCuts));