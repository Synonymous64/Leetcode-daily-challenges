var reorderedPowerOf2 = function(n) {
    let res1 = n.toString().split("").sort().join("");
    for(let i = 0; i < 30; ++i)
        if((1 << i).toString().split("").sort().join("") === res1) return true;
    return false;
};

console.log(reorderedPowerOf2(16));