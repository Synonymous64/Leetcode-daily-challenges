class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int start = 0, end = numbers.length - 1;
        while(numbers[start] + numbers[end] != target){
            if(numbers[start] + numbers[end] < target)
                start++;
            else end--;
        }
        int[] ans = {start + 1, end + 1};
        return ans;
    }
}
public class TwoSum2 {
    public static void main(String[] args) {
        int[] numbers = {2,7,11,15};
        int target = 9;
        Solution s = new Solution();
        int[] ans = s.twoSum(numbers, target);
        for(int i : ans){
            System.out.println(i);
        }
    }
}
