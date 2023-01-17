class Solution {
    public int minFlipsMonoIncr(String s) {
        int minFlips = 0, counter = 0;
        for(char ch: s.toCharArray()){
            if(ch == '1') counter++;
            else minFlips++;
            minFlips = Math.min(minFlips, counter);
        }
        return minFlips;
    }
}
public class FlipStringtoMonotoneIncreasing{
    public static void main(String[] args) {
        String s = "00110";
        Solution S = new Solution();
        System.out.println(S.minFlipsMonoIncr(s));
    }
}