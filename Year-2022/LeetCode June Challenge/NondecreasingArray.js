var checkPossibility = function(nums) {
    let pos = -1;
    for(let i = 0; i < nums.length - 1; ++i){
        if(nums[i] > nums[ i + 1]){
            if(pos != -1) return false;
            pos = i;
        }
    }
    return (pos == -1 || pos == 0 || pos == nums.length - 2 || nums[pos - 1] <= nums[pos + 1] || nums[pos] <= nums[pos + 2]);
};
let nums = [4,2,3];
console.log(checkPossibility(nums));