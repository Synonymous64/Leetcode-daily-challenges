var maxLength = function (arr) {
    const helper = (index, temp, arr) => {
        let mySet = new Set(temp);
        if(temp.length !==  Number.parseInt(mySet.size)) return 0;
        let res = temp.length;
        for(let i = index; i < arr.length; ++i) res = Math.max(res, helper(i + 1, temp + arr[i], arr));
        return Number.parseInt(res);
    }
    return helper(0, "", arr);
};
let arr = ["un","iq","ue"];
console.log(maxLength(arr));