class Solution {
    public int search(int[] nums, int target) {
        int n = nums.length;
        int low = 0, high = n - 1;
        while(low < high){
            int mid = low + (high - low)/2;
            if(nums[mid] > nums[high]) low = mid + 1;
            else high = mid;
        }

        int temp = low;
        low = 0; high = n - 1;

        while(low <= high){
            int mid = low + (high - low)/2;
            int newMid = (mid + temp) % n;
            if(nums[newMid] == target) return newMid;
            else if(nums[newMid] < target) low = mid + 1;
            else high = mid - 1;
        }
        return -1;
    }
}
public class SearchinRotatedSortedArray {
    public static void main(String[] args) {
        int[] nums = {4,5,6,7,0,1,2}; int target = 0;
        System.out.println(new Solution().search(nums, target));
    }
}
