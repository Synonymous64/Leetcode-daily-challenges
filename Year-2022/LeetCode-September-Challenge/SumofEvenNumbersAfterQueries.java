import java.util.ArrayList;

class Solution {
    public int[] sumEvenAfterQueries(int[] nums, int[][] queries) {
        int sum = 0; ArrayList<Integer> res = new ArrayList<>();
        for(int i : nums){
            if(!((i & 1) == 1)) sum += i;
        }
        for(int[] x: queries){
            int index = x[1];
            int value = x[0];
            
            if(nums[index] % 2 == 0){
                sum -= nums[index];
            }
            nums[index] += value;
            if(nums[index] % 2 == 0){
                sum += nums[index];
            }
            res.add(sum);
        }
        int[] ans = new int[res.size()];
        for(int i = 0; i < res.size(); ++i){
            ans[i] = res.get(i);
        }
        return ans;
    }
}
public class SumofEvenNumbersAfterQueries {
    public static void main(String[] args) {
        int[] nums = {1,2,3,4};
        int[][] queries = {{1,0},{-3,1},{-4,0},{2,3}};
        Solution s = new Solution();
        int[] res = s.sumEvenAfterQueries(nums, queries);
        for(int i : res) System.out.print(i + " ");
    }
}
