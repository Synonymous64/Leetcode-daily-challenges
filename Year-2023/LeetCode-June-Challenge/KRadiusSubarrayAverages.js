var getAverages = function(nums, k) {
    if(k === 0) return nums;
    let n = nums.length;
    let averages = new Array(n).fill(-1);

    if(2 * k + 1 > n) return averages;
    let windowSum = 0;

    for(let i = 0; i < (2 * k + 1); ++i)
        windowSum += nums[i];
    averages[k] = Math.trunc(windowSum / (2 * k + 1));

    for(let i = (k * 2 + 1); i < n; ++i){
        let deductElement = nums[i - (2 * k + 1)];
        let insertElement = nums[i];
        windowSum = windowSum - deductElement + insertElement;
        averages[i - k] = Math.trunc(windowSum / (2 * k + 1));
    }
    return averages;
};

let nums = [7,4,3,9,1,8,5,2,6], k = 3;
console.log(getAverages(nums, k));