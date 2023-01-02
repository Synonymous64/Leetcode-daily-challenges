var searchRange = function(nums, target) {
    let res = new Array(2);
    res.fill(-1);
    if(nums.length === 0) return res;
    let start = 0, end = nums.length - 1;
    while(start < end){
        let mid = Math.floor((start+end)/2);
        if(nums[mid] >= target) end = mid;
        else start = mid + 1;
    }
    if(nums[start] !== target) return res;
    res[0] = start;
    end = nums.length;
    while(start < end){
        let mid = Math.floor((start+end)/2);
        if(nums[mid] > target) end = mid;
        else start = mid + 1;
    }
    res[1] = start - 1;
    return res;
};
let nums = [5,7,7,8,8,10], target = 8;
console.log(searchRange(nums, target));