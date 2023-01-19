var subarraysDivByK = function (nums, k) {
    let currSum = 0, count = 0, mp = {};
    mp[0] = 1;
    for (let x of nums) {
        currSum = ((((x + currSum) % k) + k) % k);
        mp[currSum] ? mp[currSum]++: mp[currSum] = 1;
        if(mp[currSum] > 1){
            count += mp[currSum] - 1;
        }
    }
    return count;
};
let nums = [4,5,0,-2,-3,1], k = 5;
console.log(subarraysDivByK(nums, k));