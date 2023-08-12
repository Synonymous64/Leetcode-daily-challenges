var uniquePathsWithObstacles = function (obstacleGrid) {
    let rows = obstacleGrid.length, cols = obstacleGrid[0].length;

    if (obstacleGrid[0][0] === 1 || obstacleGrid[rows - 1][cols - 1] === 1) return 0;

    let dp = new Array(rows);

    for (let i = 0; i < dp.length; ++i)
        dp[i] = new Array(cols).fill(0);

    for (let row = 0; row < rows; ++row) {
        if (obstacleGrid[row][0] === 0) dp[row][0] = 1;
        else break;
    }

    for (let col = 0; col < cols; ++col) {
        if (obstacleGrid[0][col] === 0) dp[0][col] = 1;
        else break;
    }

    for (let row = 1; row < rows; ++row) {
        for (let col = 1; col < cols; ++col) {
            if (obstacleGrid[row][col] === 1) dp[row][col] = 0;
            else dp[row][col] = dp[row - 1][col] + dp[row][col - 1];
        }
    }

    return dp[rows - 1][cols - 1];
};

let obstacleGrid = [[0,1],[0,0]];
console.log(uniquePathsWithObstacles(obstacleGrid));