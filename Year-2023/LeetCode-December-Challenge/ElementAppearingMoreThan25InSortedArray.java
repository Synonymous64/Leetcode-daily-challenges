import java.util.*;

class Solution {
    public int findSpecialInteger(int[] arr) {
        HashMap<Integer, Integer> mp = new HashMap<>();
        int n = arr.length;

        for(int x: arr){
            mp.put(x, mp.getOrDefault(x, 0) + 1);
            if(mp.get(x) > n / 4) return x;
        }
        return -1;
    }
}

class ElementAppearingMoreThan25InSortedArray {
    public static void main(String[] args) {
        int[] arr = {1,2,2,6,6,6,6,7,10};
        System.out.println(new Solution().findSpecialInteger(arr));
    }
}