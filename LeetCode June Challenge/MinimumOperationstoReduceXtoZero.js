var minOperations = function(nums, x) {
    let target = -x, res = -1, sum = 0, left = 0;
    nums.forEach(element => {
        target += element;
    }); 
    if(target === 0) return nums.length;
    if(target < 0) return -1;
    nums.forEach(function(element, index){
        sum += element;
        while(sum > target){
            sum -= nums[left++];
        }
        if(sum === target){
            res = Math.max(res, index - left + 1);
        }
    })
    if(res === -1) return -1;
    else return nums.length - res;
};
var nums = [1,1,4,2,3];
var x = 5;
var ans = minOperations(nums, x);
console.log(ans);