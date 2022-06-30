import java.util.*;
class Solution {
    public int minimumLengthEncoding(String[] words) {
        Set<String> mySet = new HashSet<>(Arrays.asList(words));
        for(String ch : words){
            int size = ch.length();
            for(int i = 1; i < size; ++i){
                String str = ch.substring(i, size);
                if(mySet.contains(str)){
                    mySet.remove(str);
                }
            }
        }
        int ans = 0;
        for(String myWords : mySet){
            ans += myWords.length() + 1;
        }
        return ans;
    }
}
public class ShortEncodingofWords{
    public static void main(String[] args) {
        Solution s = new Solution();
        String[] words = {"k"};
        System.out.println(s.minimumLengthEncoding(words));
    }
}