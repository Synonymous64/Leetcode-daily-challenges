var searchInsert = function(nums, target) {
    let low = 0, high = nums.length - 1;
    while(low <= high){
        let mid = low + Math.trunc((high - low)/2);
        if(nums[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return low;
};
let nums = [1,3,5,6], target = 5;
console.log(searchInsert(nums, target));