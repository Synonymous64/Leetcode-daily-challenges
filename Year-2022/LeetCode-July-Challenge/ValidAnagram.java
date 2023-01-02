class Solution {
    public boolean isAnagram(String s, String t) {
        int lenS = s.length();
        int lenT = t.length();
        if(lenS != lenT) return false;
        int[] count = new int[26];
        for(char ch : s.toCharArray()){
            count[ch - 'a']++;
        }
        for(char ch : t.toCharArray()){
            if(count[ch - 'a'] == 0) return false;
            count[ch - 'a']--;
        }
        return true;
    }
}
public class ValidAnagram{
    public static void main(String[] args) {
        String s = "anagram", t = "nagaram";
        Solution S = new Solution();
        System.out.println(S.isAnagram(s, t));

    }
}