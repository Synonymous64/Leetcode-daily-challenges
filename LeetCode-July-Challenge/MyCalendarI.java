import java.util.*;
class MyCalendar {
    private List<int[]> mp = new ArrayList<>();
    public boolean book(int start, int end) {
        for(int[] b : mp){
            if(Math.max(b[0], start) < Math.min(b[1], end)) return false;
        }
        mp.add(new int[]{start, end});
        return true;
    }
}
public class MyCalendarI {
    public static void main(String[] args) {
        MyCalendar c = new MyCalendar();
        c.book(10, 20);
        c.book(15, 25);
        // cout<<std::boolalpha<<c.book(20, 30)<<endl;
        System.out.println(c.book(20, 30));    
    }
}
