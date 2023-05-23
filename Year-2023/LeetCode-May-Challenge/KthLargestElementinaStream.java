import java.util.*;

class KthLargest {
    private int kth;
    private PriorityQueue<Integer> pq = new PriorityQueue<>();

    public KthLargest(int k, int[] nums) {
        kth = k;
        for (int x : nums)
            add(x);
    }

    public int add(int val) {
        if (pq.size() < kth)
            pq.add(val);
        else if (pq.peek() < val) {
            pq.remove();
            pq.add(val);
        }
        return pq.peek();
    }
}

public class KthLargestElementinaStream {
    public static void main(String[] args) {
        int[] nums = { 4, 5, 8, 2 };
        int k = 3;
        KthLargest s = new KthLargest(k, nums);
        System.out.println(s.add(3));
        System.out.println(s.add(5));
        System.out.println(s.add(10));
        System.out.println(s.add(9));
        System.out.println(s.add(4));
    }
}
