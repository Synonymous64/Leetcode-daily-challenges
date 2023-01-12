var countSubTrees = function (n, edges, labels) {
    const DFS = (start, parent, labels) => {
        let ans = new Array(26);
        ans.fill(0);
        ans[labels.charCodeAt(start) - 'a'.charCodeAt(0)]++;
        for (let x of graph[start]) {
            if (x === parent) continue;
            let hsh = DFS(x, start, labels);
            for (let i = 0; i < 26; ++i) {
                ans[i] += hsh[i];
            }
        }
        res[start] = ans[labels.charCodeAt(start) - 'a'.charCodeAt(0)];
        return ans;
    }
    let res = new Array(n);
    let graph = new Array(n);
    for (let i = 0; i < n; ++i) graph[i] = [];
    for (let x of edges) {
        graph[x[0]].push(x[1]);
        graph[x[1]].push(x[0]);
    }
    DFS(0, -1, labels);
    return res;
};
let n = 7, edges = [[0, 1], [0, 2], [1, 4], [1, 5], [2, 3], [2, 6]], labels = "abaedcd";
console.log(countSubTrees(n, edges, labels));