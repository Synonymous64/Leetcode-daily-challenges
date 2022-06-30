var longestPalindrome = function(s) {
    let start = 0, end = 0, maxLen = 0, n = s.length;
    if(n <= 1) return s;
    for(let i = 0; i < n - 1; ++i){
        let left = i, right = i;
        while(left >= 0 && right < n){
            if(s[left] == s[right]){
                --left;++right;
            } else break;
        }
        let len = right - left - 1;
        if(maxLen < len){
            maxLen =  len;
            start = left + 1;
            end = right - 1;
        }
    }
    for(let i = 0; i < n - 1; ++i){
        let left = i, right = i + 1;
        while(left >= 0 && right < n){
            if(s[left] == s[right]){
                --left;++right;
            } else break;
        }
        let len = right - left - 1;
        if(maxLen < len){
            maxLen =  len;
            start = left + 1;
            end = right - 1;
        }
    }
    return s.slice(start, end + 1);
};
console.log(longestPalindrome("pop"));