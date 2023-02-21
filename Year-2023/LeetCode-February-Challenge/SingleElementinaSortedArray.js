var singleNonDuplicate = function(nums) {
    let low = 0, high = nums.length - 1;
    while(low < high){
        let mid = low + Math.trunc((high - low)/2);
        if((mid % 2 === 0 && nums[mid] === nums[mid + 1]) || (mid % 2 !== 0 && nums[mid] === nums[mid - 1])) low = mid + 1;
        else high = mid;
    }
    return nums[low];
};
let nums = [1,1,2,3,3,4,4,8,8];
console.log(singleNonDuplicate(nums));