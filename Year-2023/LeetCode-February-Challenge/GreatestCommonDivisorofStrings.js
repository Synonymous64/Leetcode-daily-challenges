var gcdOfStrings = function(str1, str2) {
    if(str1.length < str2.length) return gcdOfStrings(str2, str1);
    if(str2.length === 0) return str1;
    if(str1.substring(0, str2.length) !== str2) return "";
    return gcdOfStrings(str1.substring(str2.length), str2);
};
let str1 = "ABCABC", str2 = "ABC";
console.log(gcdOfStrings(str1, str2));