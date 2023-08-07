var searchMatrix = function(matrix, target) {
    let rows = matrix.length, cols = matrix[0].length;
    for(let i = rows - 1, j = 0; i >= 0 && j < cols;){
        if(target === matrix[i][j]) return true;
        else if(target > matrix[i][j]) j++;
        else i--;
    }
    return false;
};

let matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3;

console.log(searchMatrix(matrix, target));