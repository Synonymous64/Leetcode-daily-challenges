class Solution {
    public boolean checkIfPangram(String sentence) {
        int res = 0;
        for(Character x: sentence.toCharArray()){
            int ch = x - 'a';
            int bits = 1 << ch;
            res |= bits;
        }
        return res == (1 << 26) - 1;
    }
}
public class CheckiftheSentenceIsPangram {
    public static void main(String[] args) {
        String sentence = "thequickbrownfoxjumpsoverthelazydog";
        Solution s = new Solution();
        System.out.println(s.checkIfPangram(sentence));
    }
}
