var reconstructQueue = function(people) {
    people.sort((a, b) => a[0] == b[0] ? a[1] - b[1] : b[0] - a[0]);
    let res = new Array();
    for (let p of people) {
        res.splice(p[1], 0, p); // insert person at index k
    }
    return res;
};
let people = [[9,0],[7,0],[1,9],[3,0],[2,7],[5,3],[6,0],[3,4],[6,2],[5,2]];
console.log(reconstructQueue(people));
