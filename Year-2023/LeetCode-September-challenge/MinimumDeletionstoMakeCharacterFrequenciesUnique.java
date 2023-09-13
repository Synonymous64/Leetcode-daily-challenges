import java.util.*;

class Solution {
    public int minDeletions(String s) {
        int[] freq = new int[26];
        int deletions = 0;
        for (char ch : s.toCharArray())
            freq[ch - 'a']++;

        Set<Integer> mySet = new HashSet<>();

        for (int i = 0; i < 26; ++i) {
            while (freq[i] > 0 && mySet.contains(freq[i])) {
                freq[i]--;
                deletions++;
            }
            mySet.add(freq[i]);
        }
        return deletions;
    }
}

public class MinimumDeletionstoMakeCharacterFrequenciesUnique {
    public static void main(String[] args) {
        String s = "ceabaacb";
        System.out.println(new Solution().minDeletions(s));
    }
}