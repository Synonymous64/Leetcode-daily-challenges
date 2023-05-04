var predictPartyVictory = function (senate) {
    let n = senate.length;
    let radiant = [], dire = [];
    for (let i = 0; i < n; ++i) {
        if (senate[i] === 'R') radiant.push(i);
        else dire.push(i);
    }
    if (radiant.length === 0) return "Dire";
    else if (dire.length === 0) return "Radiant";
    let i = n;
    while (radiant.length && dire.length) {
        let rad = radiant.shift(), dir = dire.shift();
        if (rad < dir) radiant.push(i++);
        else dire.push(i++);
    }
    return radiant.length ? "Radiant" : "Dire";
};

let senate = "RD";
console.log(predictPartyVictory(senate));