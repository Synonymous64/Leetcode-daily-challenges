class Solution {
    public boolean isPowerOfFour(int n) {
        int count = 0;
        for(int i = 0; i < 32; ++i){
            if(((n >>> i) & 1) != 0){
                count++;
                if(i % 2 == 1) return false;
            }
        }
        return count == 1 ? true : false;
    }
}
public class PowerofFour {
    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.isPowerOfFour(16));
    }
}
