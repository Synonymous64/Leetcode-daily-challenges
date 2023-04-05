var minimizeArrayValue = function (nums) {
    let sum = nums[0], avg = nums[0];
    for (let i = 1; i < nums.length; ++i) {
        sum += nums[i];
        if (nums[i] > avg) {
            let x = Math.trunc(sum / (i + 1));
            if (x >= avg) {
                if (Math.trunc(sum % (i + 1))) avg = x + 1;
                else avg = x;
            }
        }
    }
    return avg;
};
let nums = [13, 13, 20, 0, 8, 9, 9];
console.log(minimizeArrayValue(nums));