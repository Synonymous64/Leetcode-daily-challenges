var MyCalendarThree = function() {
    this.map = {};
};

/** 
 * @param {number} start 
 * @param {number} end
 * @return {number}
 */
MyCalendarThree.prototype.book = function(start, end) {
    let maxCount = 0;
    this.map[start] = (this.map[start] || 0) + 1;
    this.map[end] = (this.map[end] || 0) - 1;
    let count = 0;
    for(let it in this.map){
        count += map[it];
        maxCount = Math.max(maxCount, count);
    }
    return maxCount;
};

/** 
 * Your MyCalendarThree object will be instantiated and called as such:
 * var obj = new MyCalendarThree()
 * var param_1 = obj.book(start,end)
 */