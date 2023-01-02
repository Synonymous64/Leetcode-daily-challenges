var removeStones = function (stones) {
    let visited = new Array(stones);
    visited.fill(false);
    const DFS = (idx, size, stones) => {
        visited[idx] = true;
        for (let i = 0; i < size; ++i) {
            if (visited[i]) continue;
            if (stones[idx][0] === stones[i][0] || stones[idx][1] === stones[i][1]) DFS(i, size, stones);
        }
        return;
    }
    let size = stones.length, count = 0;
    for (let i = 0; i < size; ++i) {
        if (visited[i]) continue;
        count++;
        DFS(i, size, stones);
    }
    return size - count;
};
let stones = [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]];
console.log(removeStones(stones));