import java.util.ArrayList;
import java.util.Stack;

class StockSpanner {
    private final Stack<Integer> st;
    private final int[] result;
    private final ArrayList<Integer> prices;
    private int i;

    public StockSpanner() {
       st = new Stack<>();
       result = new int[100005];
       prices = new ArrayList<>();
       i = 0;
    }

    public int next(int price) {
        int ans = 1;

        while (!st.empty() && prices.get(st.peek()) <= price) {
            ans += result[st.peek()];
            st.pop();
        }

        prices.add(price);
        result[i] = ans;
        st.push(i);
        ++i;

        return ans;
    }
}

public class Main {
    public static void main(String[] args) {
        StockSpanner stockSpanner = new StockSpanner();

        System.out.println(stockSpanner.next(100)); // return 1
        System.out.println(stockSpanner.next(80));  // return 1
        System.out.println(stockSpanner.next(60));  // return 1
        System.out.println(stockSpanner.next(70));  // return 2
        System.out.println(stockSpanner.next(60));  // return 1
        System.out.println(stockSpanner.next(75));  // return 4, because the last 4 prices (including today's price of 75) were less than or equal to today's price.
        System.out.println(stockSpanner.next(85));  // return 6
    }
}
