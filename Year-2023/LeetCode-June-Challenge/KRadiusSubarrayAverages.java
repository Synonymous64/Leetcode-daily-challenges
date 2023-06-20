class Solution {
    public int[] getAverages(int[] nums, int k) {
        int N = nums.length;
        int[] res = new int[N];
        long sum = 0;
        for (int i = 0; i < N; i++) {
            if (i < k) res[i] = -1;
            sum += nums[i];
            if (i >= 2*k) {
                res[i - k] = (int)(sum / (2*k + 1));
                sum -= nums[i - 2*k];
            }
			if (i >= N - k) res[i] = -1;
        }
        return res;
    }
}
public class KRadiusSubarrayAverages{
    public static void main(String[] args) {
        int[] nums = {7,4,3,9,1,8,5,2,6}; int k = 3;
        int[] res = new Solution().getAverages(nums, k);
        for(int x: res) System.out.print(x + " ");
    }
}