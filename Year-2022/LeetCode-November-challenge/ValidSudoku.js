var isValidSudoku = function (board) {
    for (let i = 0; i < 9; i++) {
        let row = new Set(), col = new Set(), sqr = new Set();
        for (let j = 0; j < 9; j++) {
            let rowc = board[i][j];
            let colc = board[j][i];
            let sqrc = board[Math.floor(i / 3) * 3 + Math.floor(j / 3)][(i % 3) * 3 + j % 3];
            if (row.has(rowc) || col.has(colc) || sqr.has(sqrc)) return false;
            if (rowc !== ".") row.add(rowc);
            if (colc !== ".") col.add(colc);
            if (sqrc !== ".") sqr.add(sqrc);
        }
    }
    return true;
};


let board =
    [["5", "3", ".", ".", "7", ".", ".", ".", "."]
        , ["6", ".", ".", "1", "9", "5", ".", ".", "."]
        , [".", "9", "8", ".", ".", ".", ".", "6", "."]
        , ["8", ".", ".", ".", "6", ".", ".", ".", "3"]
        , ["4", ".", ".", "8", ".", "3", ".", ".", "1"]
        , ["7", ".", ".", ".", "2", ".", ".", ".", "6"]
        , [".", "6", ".", ".", ".", ".", "2", "8", "."]
        , [".", ".", ".", "4", "1", "9", ".", ".", "5"]
        , [".", ".", ".", ".", "8", ".", ".", "7", "9"]];
console.log(isValidSudoku(board));
