var isBipartite = function (graph) {
    let n = graph.length;
    let color = new Array(n).fill(-1);
    const DFS = (graph, color, idx) => {
        for (let x of graph[idx]) {
            if (color[x] === -1) {
                color[x] = 1 - color[idx];
                if (!DFS(graph, color, x)) return false;
            }
            else if (color[x] === color[idx]) return false;
        }
        return true;
    }
    for (let i = 0; i < n; ++i) {
        if (color[i] === -1) {
            color[i] = 1;
            if (!DFS(graph, color, i)) return false;
        }
    }
    return true;
};

let graph = [[],[2,4,6],[1,4,8,9],[7,8],[1,2,8,9],[6,9],[1,5,7,8,9],[3,6,9],[2,3,4,6,9],[2,4,5,6,7,8]];
console.log(isBipartite(graph));