var isAlienSorted = function (words, order) {
    let mp = {};
    const helper = (s1, s2) => {
        let s1Size = s1.length, s2Size = s2.length;
        let minSize = Math.min(s1Size, s2Size);
        for (let i = 0; i < minSize; ++i) {
            if (mp[s1[i]] < mp[s2[i]]) return true;
            else if (mp[s1[i]] > mp[s2[i]]) return false;
        }
        return s2Size >= s1Size;
    }
    for (let i = 0; i < order.length; ++i) mp[order[i]] = i;
    let n = words.length;
    for(let i = 0; i < n - 1; ++i){
        if(!helper(words[i], words[i + 1])) return false;
    }
    return true;
};
let words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz";
console.log(isAlienSorted(words, order));