class Solution {
    public boolean increasingTriplet(int[] nums) {
        int first = Integer.MAX_VALUE, second = Integer.MAX_VALUE;
        for(int x: nums){
            if(x <= first){
                first = x;
            } else if(x <= second){
                second = x;
            } else return true;
        }
        return false;
    }
    public boolean increase(int[] nums){
        int first = Integer.MAX_VALUE, second = Integer.MAX_VALUE;
        for(int x: nums){
            if(first > x){
                first = x;
            } else if(first < x && x < second){
                second = x;
            } else if(x > second) return true;
        }
        return false;
    }
}
public class IncreasingTripletSubsequence {
    public static void main(String[] args) {
        int[] nums = {5,4,3,2,1};
        Solution s = new Solution();
        System.out.println(s.increasingTriplet(nums));
        System.out.println(s.increase(nums));
    }
}
