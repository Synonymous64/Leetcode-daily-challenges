import java.util.*;
class Solution {
    public int uniqueMorseRepresentations(String[] words) {
        String[] morse = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        Set<String> mySet = new HashSet<>();
        for(String word : words){
            StringBuilder tempStr = new StringBuilder();
            for(char ch : word.toCharArray()) tempStr.append(morse[ch - 'a']);
            mySet.add(tempStr.toString());
        }
        return mySet.size();
    }
}
public class UniqueMorseCodeWords {
    public static void main(String[] args) {
        String[] words = {"gin","zen","gig","msg"};
        Solution s = new Solution();
        System.out.println(s.uniqueMorseRepresentations(words));
    }
}
