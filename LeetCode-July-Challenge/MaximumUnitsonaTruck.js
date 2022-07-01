var maximumUnits = function(boxTypes, truckSize) {
    boxTypes.sort((a, b) => b[1] - a[1]);
    let ans = 0, nBoxes = 0, takenBoxes = 0, i = 0;
    for(; i < boxTypes.length; ++i){
        nBoxes += boxTypes[i][0];
        if(nBoxes <= truckSize){
            takenBoxes += boxTypes[i][0];
            ans += boxTypes[i][0] * boxTypes[i][1];
        } else break
    }
    if(takenBoxes < truckSize && i < boxTypes.length){
        ans += (truckSize - takenBoxes) * boxTypes[i][1];
    }
    return ans;
};
let boxTypes = [[1,3],[2,2],[3,1]];
let truckSize = 4;
console.log(maximumUnits(boxTypes, truckSize));