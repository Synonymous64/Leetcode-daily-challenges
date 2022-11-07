class Solution {
    public int maximum69Number (int num) {
        String res = Integer.toString(num);
        char[] chars = res.toCharArray();
        for(int i = 0; i < chars.length; ++i){
            if(chars[i] == '6'){
                chars[i] = '9';
                break;
            }
        }
        return Integer.parseInt(new String(chars));
    }
}
public class Maximum69Number {
    public static void main(String[] args) {
        int num = 9669;
        Solution s = new Solution();
        System.out.println(s.maximum69Number(num));
    }
}
