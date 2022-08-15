import java.util.*;

class Solution {
    public int romanToInt(String s) {
        HashMap<Character, Integer> mp = new HashMap<>();
        mp.put('V', 5);
        mp.put('I', 1);
        mp.put('X', 10);
        mp.put('L', 50);
        mp.put('C', 100);
        mp.put('D', 500);
        mp.put('M', 1000);

        int res = mp.get(s.charAt(s.length() - 1));

        for(int i = s.length() - 2; i >= 0; --i)
            res += mp.get(s.charAt(i)) < mp.get(s.charAt(i + 1)) ? -mp.get(s.charAt(i)) : +mp.get(s.charAt(i));
        return res;
    }
}

public class RomantoInteger {
    public static void main(String[] args) {
        String s = "MCMXCIV";
        Solution S = new Solution();
        System.out.println(S.romanToInt(s));
    }
}
