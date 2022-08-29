var numIslands = function(grid) {
    const DFS = (grid, row, col) => {
        grid[row][col] = '0';
        if(row + 1 < grid.length && grid[row + 1][col] === '1') DFS(grid, row + 1, col);
        if(row - 1 >= 0 && grid[row - 1][col] === '1') DFS(grid, row - 1, col);
        if(col + 1 < grid[0].length && grid[row][col + 1] === '1') DFS(grid, row, col + 1);
        if(col - 1 >= 0 && grid[row][col - 1] === '1') DFS(grid, row, col - 1);
    }
    let rows = grid.length, cols = grid[0].length, count = 0;
    for(let row = 0; row < rows; ++row){
        for(let col = 0; col < cols; ++col){
            if(grid[row][col] === '1'){
                count++;
                DFS(grid, row, col);
            }
        }
    }
    return count;
};

let grid = [
        ["1","1","1","1","0"],
        ["1","1","0","1","0"],
        ["1","1","0","0","0"],
        ["0","0","0","0","0"]
    ];
console.log(numIslands(grid));