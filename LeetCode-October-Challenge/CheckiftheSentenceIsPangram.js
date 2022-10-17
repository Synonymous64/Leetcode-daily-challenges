var checkIfPangram = function(sentence) {
    let res = 0;
    for(let x of sentence){
        let ch = x.charCodeAt(0) - 97;
        let bits = 1 << ch;
        res |= bits;
    }
    return res === (1 << 26) -1;
};
let sentence = "thequickbrownfoxjumpsoverthelazydog";
console.log(checkIfPangram(sentence));