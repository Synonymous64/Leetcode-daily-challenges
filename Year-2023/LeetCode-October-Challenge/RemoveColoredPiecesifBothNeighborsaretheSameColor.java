class Solution {
    public boolean winnerOfGame(String colors) {
        int aliceCount = 0, bobCount = 0;
        for(int i = 1; i < colors.length() - 1; i++){
            if(colors.charAt(i - 1) == 'A' && colors.charAt(i) == 'A' && colors.charAt(i + 1) == 'A') aliceCount++;
            if(colors.charAt(i - 1) == 'B' && colors.charAt(i) == 'B' && colors.charAt(i + 1) == 'B') bobCount++;
        }
        return aliceCount > bobCount;
    }
}
public class RemoveColoredPiecesifBothNeighborsaretheSameColor{
    public static void main(String[] args) {
        String colors = "AAABABB";
        System.out.println(new Solution().winnerOfGame(colors));
    }
}