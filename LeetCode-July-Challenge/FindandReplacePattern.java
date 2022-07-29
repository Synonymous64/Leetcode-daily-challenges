import java.util.*;
class Solution {
    public List<String> findAndReplacePattern(String[] words, String pattern) {
        List<String> result = new LinkedList<>();
        for (String word : words) {
            if (match(word, pattern)) {
                result.add(word);
            }
        }
        return result;
    }
    private boolean match(String s, String p) {
        Map<Character, Character> map1 = new HashMap<>();
        Map<Character, Character> map2 = new HashMap<>();
        for (int i = 0; i < s.length(); i++) {
            char c1 = s.charAt(i);
            char c2 = p.charAt(i);
            if (!map1.containsKey(c1)) {
                map1.put(c1, c2);
            }
            if (!map2.containsKey(c2)) {
                map2.put(c2, c1);
            }
            if (map1.get(c1) != c2 || map2.get(c2) != c1) {
                return false;
            }
        }
        return true;
    }
}
public class FindandReplacePattern {
    public static void main(String[] args) {
        String[] words = {"abc","deq","mee","aqq","dkd","ccc"};
        String pattern = "abb";
        Solution s = new Solution();
        List<String> res = s.findAndReplacePattern(words, pattern);
        for(int i = 0; i < res.size(); ++i){
            System.out.print(res.get(i) + " ");
        }
    }
}
