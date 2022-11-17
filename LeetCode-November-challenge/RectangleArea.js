var computeArea = function(ax1, ay1, ax2, ay2, bx1, by1, bx2, by2) {
    let rectArea1 = (ax2 - ax1) * (ay2 - ay1);
    let rectArea2 = (bx2 - bx1) * (by2 - by1);
    
    let x1 = Math.max(ax1, bx1);
    let x2 = Math.min(ax2, bx2);
    let y1 = Math.max(ay1, by1);
    let y2 = Math.min(ay2, by2);

    let overlapX = x2 - x1;
    let overlapY = y2 - y1;

    let commonArea = 0;
    if(overlapX > 0 && overlapY > 0){
        commonArea = overlapX * overlapY;
    }
    return rectArea1 + rectArea2 - commonArea;
};
let ax1 = -3, ay1 = 0, ax2 = 3, ay2 = 4, bx1 = 0, by1 = -1, bx2 = 9, by2 = 2;
console.log(computeArea(ax1, ay1, ax2, ay2, bx1, by1, bx2, by2));