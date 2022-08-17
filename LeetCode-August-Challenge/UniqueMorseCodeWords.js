var uniqueMorseRepresentations = function(words) {
    let morse = [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."];
    let mySet = new Set();
    for(let word of words){
        let tempStr = "";
        for(let char of word){
            let letters = char.charCodeAt(0) - 97;
            tempStr += morse[letters];
        }
        mySet.add(tempStr);
    }
    return mySet.size;
};
var uniqueMorseRepresentations1 = function(words) {
    let morse = {a : ".-", b: "-...", c: "-.-.",d: "-..", e: ".", f:"..-.", g:"--.", h:"....", i:"..", j:".---",k:"-.-",l:".-..",m:"--",n:"-.",o:"---",p:".--.",q:"--.-",r:".-.",s:"...",t:"-",u:"..-",v:"...-",w:".--",x:"-..-",y:"-.--",z:"--.."};
    return new Set(words.map(word => word.split('').map(letter => morse[letter]).join(''))).size;
};
let words = ["gin","zen","gig","msg"];
console.log(uniqueMorseRepresentations(words));
console.log(uniqueMorseRepresentations1(words));