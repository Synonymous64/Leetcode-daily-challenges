var allPathsSourceTarget = function(graph) {
    let size = graph.length - 1;
    let temp = [], res = [];
    const DFS = (graph, currNode = 0) => {
        temp.push(currNode);
        if(currNode === size) res.push(Array.from(temp));
        for(let child of graph[currNode]){
            DFS(graph, child);
        }
        temp.pop();
    }
    DFS(graph);
    return res;
};