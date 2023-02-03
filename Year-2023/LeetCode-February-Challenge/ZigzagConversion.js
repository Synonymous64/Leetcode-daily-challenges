var convert = function (s, numRows) {
    if (numRows === 1) return s;
    let steps = (numRows - 1) * 2;
    let res = "";
    for (let i = 0; i < numRows; ++i) {
        for (let j = i; j < s.length; j += steps) {
            res += s[j];
            if(i > 0 && i < numRows - 1 && (j + steps - 2 * i) < s.length){
                res += s[j + steps - 2 * i];
            }
        }
    }
    return res;
};
let s = "PAYPALISHIRING", numRows = 4;

console.log(convert(s, numRows));
