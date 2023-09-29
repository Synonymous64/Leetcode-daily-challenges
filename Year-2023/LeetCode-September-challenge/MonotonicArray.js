var isMonotonic = function (nums) {
    let increase = false, decrease = false;

    for (let i = 1; i < nums.length; ++i) {
        if (nums[i] > nums[i - 1]) increase = true;
        else if (nums[i] < nums[i - 1]) decrease = true;
        if (increase && decrease) return false;
    }
    return true;
};

let nums = [1,2,2,3];
console.log(isMonotonic(nums));