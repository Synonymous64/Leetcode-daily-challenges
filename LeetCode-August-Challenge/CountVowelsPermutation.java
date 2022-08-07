import java.util.*;
class Solution {
    private int MOD = 1000000007;
    private HashMap<Character, char[]> mp = new HashMap<>();
    public int helper(int n, int i, char prev, int[][] dp){
        if(i > n) return 0;
        if(i == n){
            switch(prev){
                case 'a' : return 1;
                case 'e' : return 2;
                case 'i' : return 4;
                case 'o' : return 2;
                case 'u' : return 1;
                default : return 5;
            }
        }
        int idx = prev - 'a';
        if(dp[i][idx] != -1) return dp[i][idx];
        long ans = 0;
        for(char next : mp.get(prev)){
            ans = ((ans % MOD)+ ((helper(n, i + 1, next, dp) % MOD)) % MOD) %MOD;
        }
        return dp[i][idx] = (int)ans % MOD;
    }
    public int countVowelPermutation(int n) {
        mp.put('c', new char[]{'a', 'e', 'i', 'o', 'u'});
        mp.put('a', new char[]{'e'});
        mp.put('e', new char[]{'a', 'i'});
        mp.put('i', new char[]{'a', 'e', 'o', 'u'});
        mp.put('o', new char[]{'i', 'u'});
        mp.put('u', new char[]{'a'});
        int[][] dp = new int[n + 2][27];
        for(int[] arr : dp){
            Arrays.fill(arr, -1);
        }
        return helper(n, 1, 'c', dp);
    }
}
public class CountVowelsPermutation{
    public static void main(String[] args) {
        Solution s = new Solution();
        int n = 144;
        System.out.println(s.countVowelPermutation(n));
    }
}