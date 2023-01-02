var combinationSum4 = function (nums, target) {
  let res = {};
  return combination(nums, target, res);
  function combination(nums, target, res){
    if (target < 0) return 0;
    if (target === 0) return 1;
    if (target in res) return res[target];
    let ans = 0;
    for (let num of nums) {
      ans += combination(nums, target - num, res);
    }
    res[target] = ans;
    return ans;
  };
};
let nums = [1, 2, 3],
  target = 4;
console.log(combinationSum4(nums, target));
