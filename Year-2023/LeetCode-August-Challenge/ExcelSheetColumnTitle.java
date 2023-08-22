class Solution {
    public String convertToTitle(int columnNumber) {
        String res = "";
        while (columnNumber != 0) {
            char ch = (char) ('A' + (columnNumber - 1) % 26);
            res = ch + res;
            columnNumber = (columnNumber - 1) / 26;
        }
        return res;
    }
}

public class ExcelSheetColumnTitle {
    public static void main(String[] args) {
        int columnNumber = 28;
        System.out.println(new Solution().convertToTitle(columnNumber));
    }
}