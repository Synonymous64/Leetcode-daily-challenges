class Solution {
    public int largestAltitude(int[] gain) {
        int res = 0, temp = 0;
        for(int x: gain){
            temp += x;
            res = Math.max(res, temp);
        }
        return res;
    }
}
public class FindtheHighestAltitude{
    public static void main(String[] args) {
        int[] gain = {-5,1,5,0,-7};
        System.out.println(new Solution().largestAltitude(gain));
    }
}