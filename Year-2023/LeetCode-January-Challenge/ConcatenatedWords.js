var findAllConcatenatedWordsInADict = function (words) {
    let mp = {};
    const DFS = (word, mp, idx) => {
        if (idx === word.length) return true;
        let temp = "";
        for (let i = idx; i < word.length; ++i) {
            temp += word[i];
            if (!mp[temp]) continue;
            if (mp[temp] > 0 && DFS(word, mp, i + 1)) return true;
        }
        return false;
    }
    for (let word of words) mp[word] ? mp[word]++ : mp[word] = 1;

    let res = [];

    for (let word of words) {
        mp[word]--;
        if (DFS(word, mp, 0)) res.push(word);
        mp[word]++;
    }
    return res;
};
let words = ["cat","dog","catdog"];
console.log(findAllConcatenatedWordsInADict(words));