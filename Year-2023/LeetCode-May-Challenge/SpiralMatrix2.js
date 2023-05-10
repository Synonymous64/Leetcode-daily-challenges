var generateMatrix = function (n) {
    let res = new Array(n);
    for (let i = 0; i < n; ++i) res[i] = new Array(n);
    let startRow = 0, endRow = n - 1;
    let startCol = 0, endCol = n - 1;
    let total = n * n, counter = 1;
    while (counter <= total) {
        for (let i = startCol; i <= endCol && counter <= total; ++i)
            res[startRow][i] = counter++;
        startRow++;
        for (let i = startRow; i <= endRow && counter <= total; ++i)
            res[i][endCol] = counter++;
        endCol--;
        for (let i = endCol; i >= startCol && counter <= total; --i)
            res[endRow][i] = counter++;
        endRow--;
        for (let i = endRow; i >= startRow && counter <= total; --i)
            res[i][startCol] = counter++;
        startCol++;
    }
    return res;
};

let n = 3;
console.log(generateMatrix(n));