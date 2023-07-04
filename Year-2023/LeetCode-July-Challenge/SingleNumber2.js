var singleNumber = function (nums) {
    if (nums.length < 3) return nums[0];

    nums.sort((a, b) => a - b);

    if (nums[0] !== nums[1]) return nums[0];

    for (let i = 1; i < nums.length - 1; ++i)
        if (nums[i - 1] !== nums[i] && nums[i] !== nums[i + 1])
            return nums[i];

    return nums[nums.length - 1];
};

let nums = [0,1,0,1,0,1,99];
console.log(singleNumber(nums));