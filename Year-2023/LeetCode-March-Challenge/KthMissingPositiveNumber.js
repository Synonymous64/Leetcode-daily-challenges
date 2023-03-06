var findKthPositive = function (arr, k) {
    let low = 0, high = arr.length;
    while(low < high){
        let mid = low + Math.trunc((high - low)/2);
        if(arr[mid] - mid > k) high = mid;
        else low = mid + 1;
    }
    return high + k;
};
let arr = [2,3,4,7,11], k = 5;
console.log(findKthPositive(arr, k));