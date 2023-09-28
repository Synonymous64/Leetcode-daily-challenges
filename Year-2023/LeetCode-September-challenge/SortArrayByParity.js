var sortArrayByParity = function (nums) {
    let i = 0, j = nums.length - 1;
    while (i < j) {
        if (!(nums[j] & 1)) {
            if (nums[i] & 1) {
                nums[i] = nums[i] + nums[j];
                nums[j] = nums[i] - nums[j];
                nums[i] = nums[i] - nums[j];
            } else i++;
        } else j--;
    }

    return nums;
};

let nums = [3,1,2,4];
console.log(sortArrayByParity(nums));