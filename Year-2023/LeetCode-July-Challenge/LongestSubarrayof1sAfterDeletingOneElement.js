var longestSubarray = function (nums) {
    let start = 0, end = 0, skip = 0, res = 0;

    while (end < nums.length) {
        if (nums[end] === 0) skip++;
        if (skip > 1) {
            skip -= nums[start] === 0;
            start++;
        }
        res = Math.max(res, end - start);
        end++;
    }
    return res;
};

let nums = [1,1,0,1];
console.log(longestSubarray(nums));