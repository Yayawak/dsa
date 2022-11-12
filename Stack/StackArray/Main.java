package Stack.StackArray;

public class Main {
    public static final int MaxItems = 15;
    public static void main(String[] args) {
        StackArrayBased stack = new StackArrayBased();
        int items[] = new int[MaxItems];
        for (int i = 0; i < MaxItems; i++)
        {
            items[i] = i;
            if (!stack.isFull())
            {
                stack.push(items[i]);
            }
        }
        System.out.println(stack.pop());
        while (!stack.isEmpty())
        // while (!stack.isFull())
        {
            System.out.println(stack.pop());
        }
    }
}
