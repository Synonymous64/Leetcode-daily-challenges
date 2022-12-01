var halvesAreAlike = function(s) {
    let vowels = ['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'];
    let half = 0;
    for(let i = 0; i < s.length / 2; ++i) if(vowels.indexOf(s[i]) > -1)half++;
    for(let i = s.length / 2; i < s.length; ++i) if(vowels.indexOf(s[i]) > -1)half--;
    return half === 0;
};
console.log(halvesAreAlike('textbook'));