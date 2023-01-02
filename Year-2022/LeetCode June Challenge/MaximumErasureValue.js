var maximumUniqueSubarray = function(nums) {
    let n = nums.length, res = 0, currSum = 0, left = 0, right = 0;
    let mySet = new Set();
    while(right < n){
        while(mySet.has(nums[right])){
            currSum -= nums[left];
            mySet.delete(nums[left++]);
        }
        currSum += nums[right];
        mySet.add(nums[right++]);
        res = Math.max(res, currSum);
    }
    return res;
};

let nums = [5,2,1,2,5,2,1,2,5];
console.log(maximumUniqueSubarray(nums));