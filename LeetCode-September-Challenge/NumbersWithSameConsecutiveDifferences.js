var numsSameConsecDiff = function(n, k) {
    const DFS = (n, k, curr, i, prev, res) => {
        if(i == n - 1){
            res.push(curr);
            return;
        }
        let next = prev + k;
        if(next < 10) DFS(n, k, (curr * 10) + next, i + 1, next, res);
        next = prev - k;
        if(k !== 0 && next >= 0) DFS(n, k, (curr * 10) + next, i + 1, next, res);
    }
    if(n == 1) return [0, 1, 2, 3, 4, 5, 6, 7, 8, 9];
    let res = new Array();
    for(let i = 1; i <= 9; ++i) DFS(n, k, i, 0, i, res);
    return res;
};