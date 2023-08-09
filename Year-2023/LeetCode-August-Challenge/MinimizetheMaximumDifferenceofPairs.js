var minimizeMax = function (nums, p) {

    nums.sort((a, b) => a - b);

    const isPair = (nums, mid, p) => {
        let count = 0;
        for (let i = 0; i < nums.length - 1 && count < p; ++i) {
            if (nums[i + 1] - nums[i] <= mid) {
                count++;
                i++;
            }
        }

        return count >= p;
    }

    let low = 0, high = nums[nums.length - 1] - nums[0];

    while (low < high) {
        let mid = low + Math.trunc((high - low) / 2);
        if (isPair(nums, mid, p)) high = mid;
        else low = mid + 1;
    }

    return low;
};

let nums = [10,1,2,7,1,3], p = 2;
console.log(minimizeMax(nums, p));