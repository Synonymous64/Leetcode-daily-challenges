var countSubarrays = function (nums, minK, maxK) {
    let minFound = 0, maxFound = 0, start = 0, res = 0;
    let isMin = false, isMax = false;

    for (let i = 0; i < nums.length; ++i) {
        let num = nums[i];
        if (num < minK || num > maxK) {
            isMin = false;
            isMax = false;
            start = i + 1;
        }
        if (num == minK) {
            isMin = true;
            minFound = i;
        }
        if (num == maxK) {
            isMax = true;
            maxFound = i;
        }
        if (isMin && isMax) {
            res += (Math.min(minFound, maxFound) - start + 1);
        }
    }
    return res;
};

let nums = [1,3,5,2,7,5], minK = 1, maxK = 5;
console.log(countSubarrays(nums, minK, maxK));