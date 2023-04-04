import java.util.*;
class Solution {
    public int partitionString(String s) {
        HashMap<Character, Integer> mp = new HashMap<>();
        int countUnique = 0;
        for(Character ch : s.toCharArray()){
            if(!mp.containsKey(ch)){
                mp.put(ch, mp.getOrDefault(mp, 0) + 1);
            } else {
                countUnique++;
                mp.clear();
                mp.put(ch, mp.getOrDefault(mp, 0) + 1);
            }
        }
        return ++countUnique;
    }
}
public class OptimalPartitionofString {
    public static void main(String[] args) {
        String s = "abacaba";
        Solution S = new Solution();
        System.out.println(S.partitionString(s));

    }
}
