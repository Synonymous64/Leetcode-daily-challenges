import java.util.*;
class Solution {
    public int minDeletions(String s) {
        int[] freq = new int[26];
        int deletions = 0;
        for(char ch : s.toCharArray()) freq[ch - 'a']++;
        Set<Integer> myset = new HashSet<>();
        for(int i = 0; i < 26; ++i){
            while(freq[i] > 0 && myset.contains(freq[i])){
                freq[i]--;
                deletions++;
            }
            myset.add(freq[i]);
        }
        return deletions;
    }
}
public class MinimumDeletionstoMakeCharacterFrequenciesUnique{
    public static void main(String[] args) {
        String s = "aaabbbcc";
        Solution S = new Solution();
        System.out.println(S.minDeletions(s));
    }
}