var candy = function(ratings) {
    let n = ratings.length, totalCandies = 0;
    if(n <= 1) return 1;
    let candies = new Array(n);
    candies.fill(1);
    for(let i = 1; i < n; ++i){
        if(ratings[i] > ratings[i - 1] && candies[i] <= candies[i - 1]){
            candies[i] = candies[i - 1] + 1;
        }
    }
    for(let i = n - 2; i >= 0; --i){
        if(ratings[i] > ratings[i + 1] && candies[i] <= candies[i + 1]){
            candies[i] = candies[i + 1] + 1;
        }
    }
    for(let i = 0; i < candies.length; ++i){
        totalCandies += candies[i];
    }
    return totalCandies;
};
let ratings = [1,0,2];
console.log(candy(ratings));