import java.util.*;

class StockSpanner {
    Stack<int[]> ms;

    public StockSpanner() {
        ms = new Stack<>();
    }

    public int next(int price) {
        int res = 1;
        while (!ms.isEmpty() && price >= ms.peek()[0]) {
            res += ms.peek()[1];
            ms.pop();
        }
        ms.add(new int[] { price, res });
        return res;
    }
}

public class OnlineStockSpan {
    public static void main(String[] args) {
        StockSpanner re = new StockSpanner();
        System.out.println(re.next(100));
        System.out.println(re.next(80));
        System.out.println(re.next(60));
        System.out.println(re.next(70));
        System.out.println(re.next(60));
        System.out.println(re.next(75));
        System.out.println(re.next(85));
    }
}
