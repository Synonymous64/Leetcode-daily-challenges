import java.util.*;
class Solution {
    public int minSetSize(int[] arr) {
        HashMap<Integer, Integer> freq = new HashMap<>();

        for(int i : arr){
            freq.put(i, freq.getOrDefault(i, 0) + 1);
        }
        int[] frequencies = new int[freq.values().size() + 1];
        int i = 0;
        for(int it:  freq.values()) frequencies[i++] = it;
        Arrays.sort(frequencies);
        int half = arr.length/2, count = 0, checker = 0;
        while(checker < half){
            count++;
            checker += frequencies[i--];
        }
        return count;
    }
}
public class ReduceArraySizetoTheHalf {
    public static void main(String[] args) {
        int arr[] = {3,3,3,3,5,5,5,2,2,7};
        Solution s = new Solution();
        System.out.println(s.minSetSize(arr));
    }
}
