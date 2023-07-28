var PredictTheWinner = function (nums) {
    let n = nums.length;
    let choose = true;

    const validate = (nums, i, j, choose) => {
        if (i > j) return 0;
        let res = 0;
        if (choose) res = Math.max(nums[i] + validate(nums, i + 1, j, false), nums[j] + validate(nums, i, j - 1, false));
        else res = Math.min(-nums[i] + validate(nums, i + 1, j, true), -nums[j] + validate(nums, i, j - 1, true));
        return res;
    }

    let maxScore = validate(nums, 0, n - 1, choose);
    return maxScore >= 0;
};

let nums = [1, 5, 233, 7];
console.log(PredictTheWinner(nums));