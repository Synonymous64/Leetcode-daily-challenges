class Solution {
    private void reverse(char[] chArray){
        int i = 0, j = chArray.length - 1;
        while(i < j){
            char temp = chArray[i];
            chArray[i] = chArray[j];
            chArray[j] = temp;
            i++;
            j--;
        }
    }
    public String addBinary(String a, String b) {
        int i = a.length() - 1, j = b.length() - 1;
        String res = "";
        int carry = 0;
        while (i >= 0 || j >= 0 || carry != 0) {
            int sum = carry;
            if(i >= 0) sum += a.charAt(i--) - '0';
            if(j >= 0) sum += b.charAt(j--) - '0';

            carry = sum > 1 ? 1: 0;
            res += Integer.toString(sum % 2);
        }
        if(carry != 0) res += Integer.toBinaryString(carry);
        char[] chArray = res.toCharArray();
        reverse(chArray);
        return new String(chArray);
    }
}

public class AddBinary {
    public static void main(String[] args) {
        String a = "11", b = "1";
        Solution s = new Solution();
        System.out.println(s.addBinary(a, b));
    }
}