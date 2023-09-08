var generate = function(numRows) {
    let ans = [];
    for(let i = 0; i < numRows; ++i){
        ans[i] = [];
        ans[i][0] = 1;
        for(let j = 1; j < i; ++j){
            ans[i][j] = ans[i - 1][j] + ans[i - 1][j - 1];
        }
        ans[i][i] = 1;
    }
    return ans;
};

let numRows = 5;
console.log(generate(numRows));