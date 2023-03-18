var BrowserHistory = function (homepage) {
    this.history = [homepage];
    this.curr = 0;
};


BrowserHistory.prototype.visit = function (url) {
    this.history.splice(this.curr + 1, this.history.length - this.curr + 1);
    this.history.push(url);
    this.curr++;
};


BrowserHistory.prototype.back = function (steps) {
    this.curr = Math.max(0, this.curr - steps);
    return this.history[this.curr];
};


BrowserHistory.prototype.forward = function (steps) {
    this.curr = Math.min(this.history.length - 1, this.curr + steps);
    return this.history[this.curr];
};
