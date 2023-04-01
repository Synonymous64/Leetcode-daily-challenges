class Solution {
    public int search(int[] nums, int target) {
        int n = nums.length;
        if((n == 0) || (n == 1 && nums[0] != target)) return -1;
        int low = 0, high = n - 1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] < target) low = mid + 1;
            else high = mid - 1;
        }
        return -1;
    }
}
public class BinarySearch{
    public static void main(String[] args) {
        int[] nums = {5}; int target = 5;
        System.out.println(new Solution().search(nums, target));
    }
}