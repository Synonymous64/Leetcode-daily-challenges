var mirrorReflection = function(p, q) {
    let extension = q, reflection = p;
    while(extension % 2 == 0 && reflection % 2 == 0){
        extension /= 2;
        reflection /= 2;
    }
    if(extension % 2 == 0 && reflection % 2 != 0) return 0;
    if(extension % 2 != 0 && reflection % 2 == 0) return 2;
    if(extension % 2 != 0 && reflection % 2 != 0) return 1;
    return -1;
};
let p = 2, q = 1;
console.log(mirrorReflection(p, q));