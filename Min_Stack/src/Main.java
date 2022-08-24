import java.util.Scanner;
import java.util.Stack;

class MinStack {
    Stack<Integer> s1;
    Stack<Integer> s2;

    public MinStack() {
       s1 = new Stack<>();
       s2 = new Stack<>();
    }

    public void push(int val) {
       s1.push(val);

       if (s2.empty() || s2.peek() >= s1.peek()) s2.push(val);
    }

    public void pop() {
       int x = s1.pop();

       if (s2.peek() == x) s2.pop();
    }

    public int top() {
       return s1.peek();
    }

    public int getMin() {
       return s2.peek();
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();

        while (T-- > 0) {
            MinStack minStack = new MinStack();

            minStack.push(-2);
            minStack.push(0);
            minStack.push(-3);
            System.out.println(minStack.getMin()); // return -3
            minStack.pop();
            System.out.println(minStack.top());    // return 0
            System.out.println(minStack.getMin()); // return -2
        }

        sc.close();
    }
}
