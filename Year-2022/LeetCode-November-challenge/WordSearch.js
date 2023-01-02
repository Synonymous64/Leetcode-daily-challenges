var exist = function (board, word) {
    let rows = board.length, cols = board[0].length;
    let idx = 0;
    const DFS = (idx, row, col, board, word) => {
        if (idx === word.length) return true;
        if (row < 0 || col < 0 || row >= board.length || col >= board[0].length) return false;
        let res = false;
        if (word[idx] === board[row][col]) {
            board[row][col] = '.';
            res = DFS(idx + 1, row + 1, col, board, word) || DFS(idx + 1, row - 1, col, board, word) || DFS(idx + 1, row, col - 1, board, word) || DFS(idx + 1, row, col + 1, board, word);
            board[row][col] = word[idx];
        }
        return res;
    }
    for (let row = 0; row < rows; ++row) {
        for (let col = 0; col < cols; ++col) {
            if (word[idx] === board[row][col]) {
                if (DFS(idx, row, col, board, word)) return true;
            }
        }
    }
    return false;
};
let board = [["A", "B", "C", "E"], ["S", "F", "C", "S"], ["A", "D", "E", "E"]], word = "ABCCED";
console.log(exist(board, word));