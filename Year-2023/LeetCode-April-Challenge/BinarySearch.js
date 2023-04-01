var search = function (nums, target) {
    let n = nums.length;
    if ((n === 0) || (n === 1 && nums[0] !== target)) return -1;
    let low = 0, high = n - 1;
    while (low <= high) {
        let mid = low + Math.trunc(high - low / 2);
        if (nums[mid] === target) return mid;
        else if (nums[mid] > target) high = mid - 1;
        else low = mid + 1;
    }
    return -1;
};

let nums = [-1,0,3,5,9,12], target = 9;
console.log(search(nums, target));