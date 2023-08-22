var convertToTitle = function (columnNumber) {
    let res = ''
    while (columnNumber) {
        let ch = (--columnNumber) % 26;
        res = String.fromCharCode(ch + 65) + res;
        columnNumber = (columnNumber - ch) / 26;
    }

    return res
};
let columnNumber = 28;
console.log(convertToTitle(columnNumber));