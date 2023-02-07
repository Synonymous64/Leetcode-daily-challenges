var totalFruit = function (fruits) {
    let basket = new Array(2).fill(0);
    let type1 = -1, type2 = -1, res = 0;
    for (let i = 0; i < fruits.length; ++i) {
        if (type1 === -1 || fruits[i] === type1) {
            type1 = fruits[i];
            basket[0]++;
        } else if (type2 === -1 || fruits[i] === type2) {
            type2 = fruits[i];
            basket[1]++;
        } else {
            res = Math.max(res, basket[0] + basket[1]);
            let prev = i - 1;
            while(prev >= 0  && fruits[prev] === fruits[i - 1]){
                prev--;
            }
            type1 = fruits[i - 1], type2 = fruits[i];
            basket[0] = i - prev - 1;
            basket[1] = 1;
        }
    }
    return res = Math.max(res, basket[0] + basket[1]);
};
let fruits = [1,2,1];
console.log(totalFruit(fruits));