var minimumAverageDifference = function (nums) {
    let total = 0, sum = 0;
    for (let x of nums) total += x;
    let mini = Number.MAX_VALUE, res = 0;
    for (let i = 0; i < nums.length; ++i) {
        sum += nums[i];
        let backSum = (total - sum);
        let backSize = (nums.length - i - 1);
        let avg = 0;
        if (backSize == 0) avg = Math.abs(sum / (i + 1));
        else avg = (Math.abs(parseInt(sum / (i + 1)) - parseInt((backSum / backSize))));
        if(mini > avg){
            mini = avg;
            res = i;
        }
    }
    return res;
};
let nums = [0,1,0,1,0,1];
console.log(minimumAverageDifference(nums));