import java.util.*;
class Solution {
    private boolean helper(int[] arr){
        for(int i = 0; i < 26; ++i){
            if(arr[i] != 0) return false;
        }
        return true;
    }
    public List<Integer> findAnagrams(String s, String p) {
        int lenS = s.length();
        int lenP = p.length();
        if(lenS < lenP) return new ArrayList<>();

        int[] count = new int[26];

        for(int i = 0; i < lenP; i++){
            count[p.charAt(i) - 'a']++;
            count[s.charAt(i) - 'a']--;
        }
        ArrayList<Integer> res = new ArrayList<>();
        if(helper(count)) res.add(0);

        for(int i = lenP; i < lenS; ++i){
            count[s.charAt(i - lenP) - 'a']++;
            count[s.charAt(i) - 'a']--;
            if(helper(count)) res.add(i - lenP + 1);
        }
        return res;
    }
}
public class FindAllAnagramsinaString{
    public static void main(String[] args) {
        String  s = "baa", p = "aa";
        Solution S = new Solution();
        List<Integer> res = S.findAnagrams(s, p);
        for(int ch: res) System.out.print(ch + " ");
        
    }
}