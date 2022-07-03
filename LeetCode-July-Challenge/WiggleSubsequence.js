var wiggleMaxLength = function(nums) {
    let n = nums.length, maxLen = 0;
    if(n == 1) return 1;
    let prevDiff = nums[1] - nums[0];
    maxLen = prevDiff == 0 ? 1 : 2;
    for(let i = 2; i < n; ++i){
        let currDiff = nums[i] - nums[i - 1];
        if((currDiff > 0 && prevDiff <= 0) || (currDiff < 0 && prevDiff >= 0)){
            maxLen++;
            prevDiff = currDiff;
        }
    }
    return maxLen;
};
let nums = [1,17,5,10,13,15,10,5,16,8];
console.log(wiggleMaxLength(nums));