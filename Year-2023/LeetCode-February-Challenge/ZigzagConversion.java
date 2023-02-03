class Solution {
    public String convert(String s, int numRows) {
        if(numRows == 1) return s;
        int steps = (numRows - 1) * 2;
        String res = "";
        for(int i = 0; i < numRows; ++i){
            for(int j = i; j < s.length(); j += steps){
                res+=s.charAt(j);
                if(i > 0 && i < numRows - 1 && (j + steps - 2 * i) < s.length()){
                    res+=s.charAt(j + steps - 2 * i);
                }
            }
        }
        return res;
    }
}
public class ZigzagConversion {
    public static void main(String[] args) {
        String s = "PAYPALISHIRING"; int numRows = 4;
        Solution S = new Solution();
        System.out.println(S.convert(s, numRows));
    }
}
