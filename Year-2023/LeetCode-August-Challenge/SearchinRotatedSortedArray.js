var search = function(nums, target) {
    let n = nums.length;
    let low = 0, high = n - 1;

    while(low < high){
        let mid = low + Math.trunc((high - low)/2);
        if(nums[mid] > nums[high]) low = mid + 1;
        else high = mid;
    }

    let temp = low;
    low = 0, high = n - 1;

    while(low <= high){
        let mid = low + Math.trunc((high - low)/2);
        let newMid = Math.trunc((mid + temp) % n);
        if(nums[newMid] === target) return newMid;
        else if(nums[newMid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
};

let nums = [4,5,6,7,0,1,2], target = 0;
console.log(search(nums, target));