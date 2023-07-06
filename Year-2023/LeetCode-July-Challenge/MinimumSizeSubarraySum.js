var minSubArrayLen = function (target, nums) {
    let res = Infinity, sum = 0, left = 0, right = 0;

    for (right = 0; right < nums.length; ++right) {
        sum += nums[right];
        while (sum >= target) {
            res = Math.min(res, right - left + 1);
            sum -= nums[left];
            left++;
        }
    }
    return res == Infinity ? 0 : res;
};

let target = 7, nums = [2,3,1,2,4,3];
console.log(minSubArrayLen(target, nums));