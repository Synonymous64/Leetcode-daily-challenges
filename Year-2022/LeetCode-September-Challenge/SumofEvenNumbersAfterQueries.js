var sumEvenAfterQueries = function (nums, queries) {
  let sum = 0;
  let res = new Array();
  nums.forEach((ele) => {
    if (!(ele & 1)) sum += ele;
  });
  for (let [val, idx] of queries) {
    let index = idx;
    let value = val;
    if (nums[index] % 2 === 0) {
      sum -= nums[index];
    }
    nums[index] += value;
    if (nums[index] % 2 == 0) {
      sum += nums[index];
    }
    res.push(sum);
  }
  return res;
};
let nums = [1,2,3,4], queries = [[1,0],[-3,1],[-4,0],[2,3]];
console.log(sumEvenAfterQueries(nums, queries));
