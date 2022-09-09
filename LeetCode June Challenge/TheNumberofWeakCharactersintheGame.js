var numberOfWeakCharacters = function(properties) {
    let count = 0, maxVal = Number.MIN_VALUE, n = properties.length;
    properties.sort((a, b) => a[0] == b[0] ? b[1] - a[1] : a[0] - b[0]);
    for(let i = n - 1; i >= 0; --i){
        if(properties[i][1] < maxVal) count++;
        if(properties[i][1] > maxVal) maxVal = properties[i][1];
    }
    return count;
};
let properties = [[7,9],[10,7],[6,9],[10,4],[7,5],[7,10]];
console.log(numberOfWeakCharacters(properties));