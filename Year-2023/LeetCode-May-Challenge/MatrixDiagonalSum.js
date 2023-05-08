var diagonalSum = function (mat) {
    let n = mat.length, res = 0;
    for (let i = 0; i < n; ++i) res += mat[i][i];
    let j = n - 1;
    for (let i = 0; i < n; ++i, j--)
        if (i !== j) res += mat[i][j];
    return res;
};

let mat = [[1, 2, 3],
        [4, 5, 6],
        [7, 8, 9]];
console.log(diagonalSum(mat));