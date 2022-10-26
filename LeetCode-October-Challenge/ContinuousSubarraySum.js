var checkSubarraySum = function(nums, k) {
    let n = nums.length;
    for(let i = 1; i < n; ++i)
        if(!nums[i] && nums[i - 1]) return true;
    for(let i = 1; i < n; ++i){
        nums[i] += nums[i - 1];
        if(Math.floor(nums[i] % k) === 0) return true;
        let j = i;
        while(j > 1 && nums[j] > k){
            if(Math.floor((nums[i] - nums[j - 2])) % k === 0) return true;
            j--;
        }
    }
    return false;
};
let nums = [1,0], k = 2;
console.log(checkSubarraySum(nums, k));