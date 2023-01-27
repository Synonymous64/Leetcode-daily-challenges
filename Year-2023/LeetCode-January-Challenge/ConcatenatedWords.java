import java.util.*;
class Solution {
    private boolean DFS(String word, HashMap<String, Integer> mp, int idx){
        if(idx == word.length()) return true;
        String temp = "";
        for(int i = idx; i < word.length(); ++i){
            temp += word.charAt(i);
            if(mp.getOrDefault(temp, -1) > 0 && DFS(word, mp, i + 1)) return true;
        }
        return false;
    }
    public List<String> findAllConcatenatedWordsInADict(String[] words) {
        HashMap<String, Integer> mp = new HashMap<>();
        for(String word: words) mp.put(word, mp.getOrDefault(word, 0) + 1);

        ArrayList<String> res = new ArrayList<>();
        for(String word: words){
            mp.put(word, mp.get(word) - 1);
            if(DFS(word, mp, 0)) res.add(word);
            mp.put(word, mp.get(word) + 1);
        }
        return res;
    }
}
public class ConcatenatedWords {
    public static void main(String[] args) {
        String[] word = {"cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"};
        Solution s = new Solution();
        List<String> res = s.findAllConcatenatedWordsInADict(word);
        for(String str: res) System.out.print(str + " ");
    }
}
