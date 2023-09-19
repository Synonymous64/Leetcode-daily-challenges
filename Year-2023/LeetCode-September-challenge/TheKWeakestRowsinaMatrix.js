var kWeakestRows = function (mat, k) {
    let n = mat[0].length;

    for (let i = 0; i < mat.length; ++i) mat[i].push(i);

    mat.sort((a, b) => a - b);
    let res = new Array(k);
    for (let i = 0; i < k; ++i) res[i] = mat[i][n];
    return res;
};

let mat =
    [[1, 1, 0, 0, 0],
    [1, 1, 1, 1, 0],
    [1, 0, 0, 0, 0],
    [1, 1, 0, 0, 0],
    [1, 1, 1, 1, 1]],
    k = 3;
console.log(kWeakestRows(mat, k));