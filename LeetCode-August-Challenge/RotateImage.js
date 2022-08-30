var rotate = function(matrix) {
    let rows = matrix.length;
    for(let row = 0; row < rows; ++row){
        for(let col = 0; col < row; ++col){
            let temp = matrix[row][col];
            matrix[row][col] = matrix[col][row];
            matrix[col][row] = temp;
        }
    }
    for(let row = 0; row < rows; ++ row){
        for(let col = 0; col < rows/2; ++col){
            let temp = matrix[row][col];
            matrix[row][col] = matrix[row][rows - col - 1];
            matrix[row][rows - col - 1] = temp;
        }
    }
};
let matrix = [[1,2,3],[4,5,6],[7,8,9]];
rotate(matrix);
console.table(matrix);