var partitionString = function (s) {
    let mp = {};
    let countUnique = 0;
    for(let x of s){
        if(!mp[x]){
            mp[x] ? mp[x]++: mp[x] = 1;
        } else{
            countUnique++;
            mp = {};
            mp[x] = 1;
        }
    }
    return ++countUnique;
};

let s = "abacaba";
console.log(partitionString(s));