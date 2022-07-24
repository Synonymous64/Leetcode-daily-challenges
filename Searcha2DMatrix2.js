var searchMatrix = function(matrix, target) {
    let m = matrix.length, n = matrix[0].length;
    for(let i = m - 1, j = 0; i >= 0 && j < n;){
        if(target === matrix[i][j]) return true;
        else if(target > matrix[i][j]) j++;
        else i--;
    }
    return false;
};
let matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
console.log(searchMatrix(matrix, target));