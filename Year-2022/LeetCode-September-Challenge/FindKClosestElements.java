import java.util.*;
class Solution {
    class Pair{
        int key;
        int value;
        
        Pair(int key, int value){
            this.key = key;
            this.value = value;
        }
        
    }
    public List<Integer> findClosestElements(int[] arr, int k, int x) {
        List<Integer> list = new ArrayList<>();
        PriorityQueue<Pair> pq = new PriorityQueue<>(
            new Comparator<Pair>(){
                public int compare(Pair a, Pair b){
                    if((b.key - a.key) == 0)
                        return b.value - a.value;
                    return b.key - a.key;
                }
        });
        
        for(int i: arr){
            pq.add(new Pair(Math.abs(i-x), i));
            
            if(pq.size() > k)
                pq.poll();
        }
        
        while(pq.size() != 0){
            Pair p = pq.poll();
            list.add(p.value);
        }
        Collections.sort(list);
        return list;
    }
}
public class FindKClosestElements {
    public static void main(String[] args) {
        int[] arr = {1,2,3,4,5};
        int k = 4, x = 3;
        Solution s = new Solution();
        List<Integer> res = s.findClosestElements(arr, k, x);
        for(int i = 0; i < res.size(); ++i){
            System.out.print(res.get(i) + " ");
        } 
    }
}
