var spiralOrder = function (matrix) {
    let rows = matrix.length, cols = matrix[0].length;
    let top = 0, bottom = rows - 1;
    let left = 0, right = cols - 1;
    let res = [];
    while (top <= bottom && left <= right) {
        for (let i = left; i <= right; ++i)
            res.push(matrix[top][i]);
        top++;
        for (let i = top; i <= bottom; ++i)
            res.push(matrix[i][right]);
        right--;
        if (top <= bottom) {
            for (let i = right; i >= left; --i)
                res.push(matrix[bottom][i]);
            bottom--;
        }
        if (left <= right) {
            for (let i = bottom; i >= top; --i)
                res.push(matrix[i][left]);
            left++;
        }
    }
    return res;
};

let matrix = [[1, 2, 3], [4, 5, 6], [7, 8, 9]];
console.table(spiralOrder(matrix));