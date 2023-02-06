import java.util.*;
class Solution {
    public int[] shuffle(int[] nums, int n) {
        ArrayList<Integer> sum = new ArrayList<>();        
        for(int i = 0; i < n; ++i){
            sum.add(nums[i]);
            if(i + n < nums.length){
                sum.add(nums[i + n]);
            }
        }
        int[] res = new int[sum.size()];
        for(int i = 0; i < sum.size(); ++i){
            res[i] = sum.get(i);
        }
        return res;
    }
}
public class ShuffletheArray{
    public static void main(String[] args) {
        int[] nums = {2,5,1,3,4,7}; int n = 3;
        Solution s = new Solution();
        int[] res = s.shuffle(nums, n);
        for(int x: res) System.out.print(x + " ");
    }
}