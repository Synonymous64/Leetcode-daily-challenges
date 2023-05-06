var numSubseq = function (nums, target) {
    let n = nums.length;
    nums.sort((a, b) => a - b);
    let low = 0, high = n - 1, mod = 1000000007;
    let pow = new Array(n).fill(1);
    for (let i = 1; i < n; ++i) {
        pow[i] = ((pow[i - 1] * 2) % mod);
    }
    let res = 0;
    while (low <= high) {
        if (nums[low] + nums[high] > target) high--;
        else {
            res = (res + pow[high - low]) % mod;
            low++;
        }
    }
    return res;
};

let nums = [3, 5, 6, 7], target = 9;
console.log(numSubseq(nums, target));