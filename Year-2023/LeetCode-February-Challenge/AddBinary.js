var addBinary = function(a, b) {
    return (BigInt("0b"+a) + BigInt("0b"+b)).toString(2);
}
let a = "11", b = "1";
console.log(addBinary(a, b));