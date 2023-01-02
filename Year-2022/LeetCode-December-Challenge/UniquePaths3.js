var uniquePathsIII = function(grid) {
    row = 0, col = 0, count = 0;
    const helper = (grid, count, row, col) =>{
        if(row < 0 || col < 0 || row >= grid.length || col >= grid[0].length || grid[row][col] == -1) return 0;
        if(grid[row][col] === 2) return count == -1 ? 1: 0;
        grid[row][col] = -1;
        count--;
        let res =  helper(grid, count, row + 1, col) +  helper(grid, count, row - 1, col) 
        + helper(grid, count, row, col + 1) + helper(grid, count, row, col - 1);
        grid[row][col] = 0;
        count++;
        return res;
    }
    for(let i = 0; i < grid.length; ++i){
        for(let j = 0; j < grid[0].length; ++j){
            if(grid[i][j] === 1){
                row = i;
                col = j;
            }
            if(grid[i][j] === 0) count++;
        }
    }
    return helper(Array.from(grid), count, row, col);
};
let grid = [[1,0,0,0],[0,0,0,0],[0,0,2,-1]];
console.log(uniquePathsIII(grid));