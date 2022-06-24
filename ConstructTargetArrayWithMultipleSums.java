class Solution {
    public boolean isPossible(int[] target) {
        long sum = 0;
        int max = 0;
        for(int i = 0; i < target.length; ++i){
            sum += target[i];
            if(target[max] < target[i]){
                max = i;
            }
        }
        long diff = sum - target[max];
        if(diff == 1 || target[max] == 1) return true;
        if(diff > target[max] || diff == 0 || target[max] % diff == 0) return false;
        target[max] %= diff;
        return isPossible(target);
    }
}
public class ConstructTargetArrayWithMultipleSums {
    public static void main(String[] args) {
        int[] target = {9,3,5};
        Solution s = new Solution();
        System.err.println(s.isPossible(target));
    }
}
