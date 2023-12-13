var numSpecial = function (mat) {
    let totalRows = mat.length, totalColumns = mat[0].length;
    let rows = new Array(totalRows).fill(0), cols = new Array(totalColumns).fill(0);

    for (let i = 0; i < totalRows; ++i) {
        for (let j = 0; j < totalColumns; ++j) {
            if (mat[i][j] === 1) {
                rows[i]++, cols[j]++;
            }
        }
    }

    let count = 0;
    for (let i = 0; i < totalRows; ++i) {
        for (let j = 0; j < totalColumns; ++j) {
            if (mat[i][j] === 1 && rows[i] === 1 && cols[j] === 1) count++;
        }
    }

    return count;
};

let mat = [[1, 0, 0], [0, 0, 1], [1, 0, 0]];
console.log(numSpecial(mat));