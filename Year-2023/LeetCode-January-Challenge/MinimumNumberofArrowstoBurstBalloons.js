var findMinArrowShots = function(points) {
    if(points.length === 0) return 0;
    points.sort((a, b) => a[1] - b[1]);
    let arrows = 1, last = points[0][1];
    for(let i = 1; i < points.length; ++i){
        if(points[i][0] > last){
            arrows++;
            last = points[i][1];
        }
    }
    return arrows;
};
let points = [[-2147483646,-2147483645],[2147483646,2147483647]];
console.log(findMinArrowShots(points));