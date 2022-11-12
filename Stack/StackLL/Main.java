package Stack.StackLL;

public class Main {
    public static void main(String[] args) {

        // String str = "aaa{bbbb{ccc}}ddd{{{eee}}}";
        String str = "aaa{bbbb{ccc}}}}}}}}}}}}}}}}}}}}}}}ddd{{{eee}}}";
        CountParanthaseses pCounter = new CountParanthaseses(str);
        // pCounter.isBalance()
        if (pCounter.isBalance())
        {
            System.out.println("balance");
        }
        // StackLinkList stack = new StackLinkList();
        // stack.push(10);
        // stack.push(30);

        // System.out.println((int)stack.pop());
        // System.out.println((int)stack.pop());
        // System.out.println((int)stack.pop());
        // System.out.println((int)stack.pop());

    }

}
