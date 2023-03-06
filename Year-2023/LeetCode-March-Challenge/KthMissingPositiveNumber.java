class Solution {
    public int findKthPositive(int[] arr, int k) {
        int low = 0, high = arr.length;
        while(low < high){
            int mid = low + (high - low)/2;
            if(arr[mid] - mid > k) high = mid;
            else low = mid + 1;
        }
        return high + k;
    }
}
public class KthMissingPositiveNumber {
    public static void main(String[] args) {
        int[] arr = {2,3,4,7,11}; int k = 5;
        Solution s = new Solution();
        System.out.println(s.findKthPositive(arr, k));
    }
}
