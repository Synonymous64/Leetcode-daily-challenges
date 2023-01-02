import java.util.*;

class MedianFinder {
    private PriorityQueue<Integer> minHeap;
    private PriorityQueue<Integer> maxHeap;

    public MedianFinder() {
        minHeap = new PriorityQueue<>();
        maxHeap = new PriorityQueue<>(Collections.reverseOrder());
    }

    public void addNum(int num) {
        if (minHeap.isEmpty() && maxHeap.isEmpty())
            maxHeap.add(num);
        else {
            if (maxHeap.peek() < num)
                minHeap.add(num);
            else
                maxHeap.add(num);
        }
        int minSize = minHeap.size(), maxSize = maxHeap.size();
        if (Math.abs(minSize - maxSize) == 2) {
            if (minSize > maxSize) {
                int ele = minHeap.poll();
                maxHeap.add(ele);
            } else {
                int ele = maxHeap.poll();
                minHeap.add(ele);
            }
        }
    }

    public double findMedian() {
        int minSize = minHeap.size(), maxSize = maxHeap.size();
        if ((minSize + maxSize) % 2 == 0)
            return (((double) minHeap.peek()) + ((double) maxHeap.peek())) / 2.0;
        if (minSize > maxSize)
            return minHeap.peek();
        return maxHeap.peek();
    }
}

public class FindMedianfromDataStream {
    public static void main(String[] args) {
        MedianFinder m = new MedianFinder();
        m.addNum(1);
        m.addNum(2);
        System.out.println(m.findMedian());
        m.addNum(3);
        System.out.println(m.findMedian());
    }
}