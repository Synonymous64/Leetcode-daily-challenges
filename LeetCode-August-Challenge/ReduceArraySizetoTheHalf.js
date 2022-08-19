var minSetSize = function(arr) {
    let freq = {};
    for(let i of arr) freq[i] ? freq[i]++ : freq[i] = 1;
    const sortedFreq = Object.values(freq).sort((a,b) => b - a);
    let count = 0;
    for(let i = 0; i < sortedFreq.length; ++i){
        count += sortedFreq[i];
        if(count >= arr.length/2) return i + 1;
    }
};
let arr = [3,3,3,3,5,5,5,2,2,7];
console.log(minSetSize(arr));