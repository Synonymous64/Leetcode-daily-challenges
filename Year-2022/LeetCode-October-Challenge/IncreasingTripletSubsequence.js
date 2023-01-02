var increasingTriplet = function(nums) {
    let first = Number.MAX_VALUE, second = Number.MAX_VALUE;
    for(let x of nums){
        if(x <= first){
            first = x;
        } else if(x <= second){
            second = x;
        } else return true;
    }
    return false;
};
let nums = [1,2,3,4,5];
console.log(increasingTriplet(nums));