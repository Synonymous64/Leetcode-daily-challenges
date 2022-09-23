var concatenatedBinary = function (n) {
  return [...Array(n)]
    .map((_, idx) => ++idx)
    .reduce((acc, num) => {
      return (acc = (acc * (1 << num.toString(2).length) + num) % 1000000007);
    }, 0);
};
console.log(concatenatedBinary(3));
