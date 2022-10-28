import java.util.*;
class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String, List<String>> mp = new TreeMap<>();
        for(int i = 0; i < strs.length; ++i){
            char[] str = strs[i].toCharArray();
            Arrays.sort(str);
            String keyStr = String.valueOf(str);
            if(!mp.containsKey(keyStr)) mp.put(keyStr, new ArrayList<>());
            mp.get(keyStr).add(strs[i]);
        }
        return new ArrayList<>(mp.values());
    }
}
public class GroupAnagrams {
    public static void main(String[] args) {
        String[] strs = {"eat","tea","tan","ate","nat","bat"};
        Solution s = new Solution();
        List<List<String>> res = s.groupAnagrams(strs);
        for(List<String> str: res){
            for(String ch: str){
                System.out.print(ch + " ");
            }
        }
    }
}
