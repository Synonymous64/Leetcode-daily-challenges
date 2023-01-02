var minFallingPathSum = function (matrix) {
    for (let i = matrix.length - 2; i >= 0; --i)
        for (let j = 0; j < matrix[0].length; ++j)
            if (j > 0 && j < matrix[0].length - 1) matrix[i][j] += Math.min(matrix[i + 1][j], Math.min(matrix[i + 1][j + 1], matrix[i + 1][j - 1]));
            else if (j == 0) matrix[i][j] += Math.min(matrix[i + 1][j], matrix[i + 1][j + 1]);
            else matrix[i][j] += Math.min(matrix[i + 1][j], matrix[i + 1][j - 1]);
    let res = matrix[0][0];
    for (let i = 0; i < matrix[0].length; ++i)
        if (matrix[0][i] < res) res = matrix[0][i];
    return res;
};
let matrix = [[2,1,3],[6,5,4],[7,8,9]];
console.log(minFallingPathSum(matrix));