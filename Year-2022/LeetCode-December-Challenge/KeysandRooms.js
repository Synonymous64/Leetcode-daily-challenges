var canVisitAllRooms = function (rooms) {
    let q = [], visited = { '0': true };
    q.push(0), visited[0] = true;
    while (q.length) {
        let curr = q.pop();
        for (let x of rooms[curr]) {
            if (!visited[x]) {
                visited[x] = true;
                q.push(x);
            }
        }
    }
    return Object.keys(visited).length === rooms.length;
};
let rooms = [[1, 3], [3, 0, 1], [2], [0]];
console.log(canVisitAllRooms(rooms));