var findBall = function(grid) {
    let cols = grid[0].length;
    const DFS = (row, col, grid) => {
        if(row >= grid.length) return col;
        if(grid[row][col] === 1 && col + 1 < grid[0].length && grid[row][col + 1] === 1)
            return DFS(row + 1, col + 1, grid);
        else if(grid[row][col] === -1 && col - 1 >= 0 && grid[row][col - 1] === -1)
            return DFS(row + 1, col - 1, grid);
        else return -1;
    }
    let res = new Array(cols);
    for(let col = 0; col < cols; ++col) res[col] = DFS(0, col, grid);
    return res;
};
let grid = [[1,1,1,-1,-1],[1,1,1,-1,-1],[-1,-1,-1,1,1],[1,1,1,1,-1],[-1,-1,-1,-1,-1]];
console.log(findBall(grid));