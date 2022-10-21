// var containsNearbyDuplicate = function(nums, k) {
//     let mp = new Map();
//     for(let i = 0; i < nums.length; ++i){
//         if(i - mp.get(nums[i]) <= k) return true;
//         mp.set(nums[i], i);
//     }
//     return false;
// };
var containsNearbyDuplicate = function(nums, k) {
    let mp = {};
    for(let i = 0; i < nums.length; ++i){
        if(i - mp[nums[i]] <= k) return true;
        mp[nums[i]] = i;
    }
    return false;
};
let nums = [1,0,1,1], k = 1;
console.log(containsNearbyDuplicate(nums, k));
