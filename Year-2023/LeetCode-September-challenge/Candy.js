var candy = function (ratings) {
    let n = ratings.length;
    let candies = new Array(n).fill(1);

    for (let i = 1; i < n; ++i)
        if (ratings[i] > ratings[i - 1] && candies[i] <= candies[i - 1])
            candies[i] = candies[i - 1] + 1;

    for (let i = n - 2; i >= 0; --i)
        if (ratings[i] > ratings[i + 1] && candies[i] <= candies[i + 1])
            candies[i] = candies[i + 1] + 1;

    let totalCandies = 0;
    for (let i = 0; i < n; ++i)
        totalCandies += candies[i];

    return totalCandies;
};

let ratings = [1,0,2];
console.log(candy(ratings));