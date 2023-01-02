var longestConsecutive = function(nums) {
    let mySet = new Set();
    nums.forEach((element) =>{
        mySet.add(element);
    })
    let ans = 0;
    for(let i = 0; i < nums.length; ++i){
        if(!mySet.has(nums[i])) continue;
        let prev = nums[i] - 1, next = nums[i] + 1;
        while(mySet.has(prev)) prev--;
        while(mySet.has(next)) next++;
        ans = Math.max(ans, next - prev - 1);
        mySet.delete(nums[i]);
    }
    return ans;
};
let nums = [100,4,200,1,3,2];
console.log(longestConsecutive(nums));