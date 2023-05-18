var findSmallestSetOfVertices = function (n, edges) {
    let visited = new Array(n).fill(false);
    for (let edge of edges)
        visited[edge[1]] = true;
    let res = [];
    for (let i = 0; i < n; ++i)
        if (!visited[i]) res.push(i);
    return res;
};

let n = 5, edges = [[0,1],[2,1],[3,1],[1,4],[2,4]];
console.log(findSmallestSetOfVertices(n, edges));