var minimumLengthEncoding = function(words) {
    let mySet = new Set(words);
    for(let Word of words){
        size = Word.length;
        for(let i = 1; i < size; ++i){
            let str = Word.slice(i, size);
            if(mySet.has(str)){
                mySet.delete(str);
            }
        }
    }
    let ans = 0;
    for(let newSet of mySet){
        ans += newSet.length + 1;
    }
    return ans;
};
let words = ["k"];
console.log(minimumLengthEncoding(words));