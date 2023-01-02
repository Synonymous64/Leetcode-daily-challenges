var removeDuplicates = function(nums) {
    let curr = 0;
    for(let i = 1; i < nums.length; ++i){
        if(nums[curr] !== nums[i]){
            curr++;
            nums[curr] = nums[i];
        }
    }
    return curr + 1;
};
let nums = [0,0,1,1,1,2,2,3,3,4];
console.log(removeDuplicates(nums));