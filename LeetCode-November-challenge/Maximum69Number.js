var maximum69Number  = function(num) {
    let res = new String(num).split('');
    for(let i = 0; i < res.length; ++i){
        if(res[i] === '6'){
            res[i] = '9';
            break;
        }
    }
    return Number.parseInt(res.join(''));
};
let num = 9669;
console.log(maximum69Number(num));