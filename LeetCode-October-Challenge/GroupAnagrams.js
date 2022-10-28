var groupAnagrams = function(strs) {
    let res = {};
    for(let str of strs){
        let ch = str.split("").sort().join("");
        res[ch] ? res[ch].push(str) : res[ch] = [str];
    }
    return Object.values(res);
};
let strs = ["eat","tea","tan","ate","nat","bat"];
console.log(groupAnagrams(strs));