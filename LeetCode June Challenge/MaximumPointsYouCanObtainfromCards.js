var maxScore = function(cardPoints, k) {
    let sum = 0, maxSum = 0, n = cardPoints.length;
    for(let i  = 0; i < k; ++i){
        sum += cardPoints[i];
    }
    maxSum = sum;
    for(let i = k - 1; i >= 0; --i){
        sum -= cardPoints[i];
        sum += cardPoints[n - k + i];
        maxSum = Math.max(sum, maxSum);
    }
    return maxSum;
};
let cardPoints = [1,2,3,4,5,6,1], k = 3;
console.log(maxScore(cardPoints, k));