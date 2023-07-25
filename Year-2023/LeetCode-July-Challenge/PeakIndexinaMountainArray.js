var peakIndexInMountainArray = function (arr) {
    let low = 0, high = arr.length - 1;
    while (low < high) {
        let mid = low + Math.trunc((high - low) / 2);
        if (arr[mid] < arr[mid + 1]) low = mid + 1;
        else high = mid;
    }
    return low;
};

let arr = [0,1,0];
console.log(peakIndexInMountainArray(arr));