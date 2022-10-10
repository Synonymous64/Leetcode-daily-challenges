var breakPalindrome = function(palindrome) {
    let n = palindrome.length;
    if(n <= 1) return "";
    for(let i = 0; i < Math.floor(n / 2); ++i){
        if(palindrome[i] != 'a'){
            palindrome[i] = 'a';
            return palindrome.substr(0, i) + 'a' + palindrome.substr(i + 1);
        }
    }
    return palindrome.substr(0, n - 1) + 'a';
};
let palindrome = "abccba";
console.log(breakPalindrome(palindrome));