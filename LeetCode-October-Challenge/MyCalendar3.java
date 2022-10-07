import java.util.*;
class MyCalendarThree {
    private Map<Integer, Integer> mp = new TreeMap<>();
    private int maxCount = 0;
    public int book(int start, int end) {
        mp.put(start, mp.getOrDefault(start, 0) + 1);
        mp.put(end, mp.getOrDefault(end, 0) - 1);
        int count = 0;
        for(Map.Entry<Integer, Integer> it : mp.entrySet()){
            count += it.getValue();
            maxCount = Math.max(maxCount, count);
        }
        return maxCount;
    }
}

public class MyCalendar3 {
    public static void main(String[] args) {
        MyCalendarThree m = new MyCalendarThree();
        System.out.println(m.book(10, 20));
        System.out.println(m.book(50, 60));
        System.out.println(m.book(10, 40));
        System.out.println(m.book(5, 15));
        System.out.println(m.book(5, 10));
        System.out.println(m.book(25, 55));
    }    
}
