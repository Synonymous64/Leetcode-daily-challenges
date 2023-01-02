class Solution {
    public int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        return (int) Math.ceil(Math.log(buckets)/Math.log(minutesToTest/ minutesToDie + 1)) ;
    }
}
public class PoorPigs {
    public static void main(String[] args) {
        int buckets = 1000, minutesToDie = 15, minutesToTest = 60;
        Solution s = new Solution();
        System.out.println(s.poorPigs(buckets, minutesToDie, minutesToTest));
    }
}
