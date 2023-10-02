var winnerOfGame = function(colors) {
    let aliceCount = 0, bobCount = 0;

    for(let i = 1; i < colors.length - 1; ++i){
        if(colors[i - 1] == 'A' && colors[i] == 'A' && colors[i + 1] == 'A') aliceCount++;
        if(colors[i - 1] == 'B' && colors[i] == 'B' && colors[i + 1] == 'B') bobCount++;
    }
    return aliceCount > bobCount;
};

let colors = "AAABABB";
console.log(winnerOfGame(colors));