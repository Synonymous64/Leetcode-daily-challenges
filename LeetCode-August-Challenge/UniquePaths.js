var uniquePaths = function(m, n) {
    let res = Array(m).fill().map(() => Array(n));
    for(let row = 0; row < m; ++row) res[row][0] = 1;
    for(let col = 0; col < n; ++col) res[0][col] = 1;
    for(let row = 1; row < m; ++row)
        for(let col = 1; col < n; ++col)
            res[row][col] = res[row - 1][col] + res[row][col - 1];
    return res[m - 1][n - 1];
};
console.table(uniquePaths(3,7));
