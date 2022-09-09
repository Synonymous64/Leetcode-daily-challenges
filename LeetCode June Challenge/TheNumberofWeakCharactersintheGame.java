import java.util.Arrays;

class Solution {
    public int numberOfWeakCharacters(int[][] properties) {
        int count = 0, maxVal = Integer.MIN_VALUE, n = properties.length;
        Arrays.sort(properties, (a, b) -> a[0] == b[0] ? b[1] - a[1] : a[0] - b[0]);
        for(int i = n - 1; i >= 0; --i){
            if(properties[i][1] < maxVal) count++;
            if(properties[i][1] > maxVal) maxVal = properties[i][1];
        }
        return count;
    }
}
public class TheNumberofWeakCharactersintheGame {
    public static void main(String[] args) {
        int[][] properties = {{7,9},{10,7},{6,9},{10,4},{7,5},{7,10}};
        Solution s = new Solution();
        System.out.println(s.numberOfWeakCharacters(properties));
    }
}
