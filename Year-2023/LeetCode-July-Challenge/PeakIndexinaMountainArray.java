class Solution {
    public int peakIndexInMountainArray(int[] arr) {
        int low = 0, high = arr.length - 1;
        while(low < high){
            int mid = low + (high - low)/2;
            if(arr[mid] < arr[mid + 1]) low = mid + 1;
            else high = mid;
        }
        return low;
    }
}
public class PeakIndexinaMountainArray{
    public static void main(String[] args) {
        int[] arr = {0,1,0};
        System.out.println(new Solution().peakIndexInMountainArray(arr));
    }
}