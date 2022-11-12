package Stack.StackArray;

public class StackArrayBased {
    final int MaxStack = 50;
    private int item[];
    private int top;
    public StackArrayBased()
    {
        item = new int[MaxStack];
        top = -1;
    }

    public boolean isEmpty()
    {
        return top < 0;
    }

    public boolean isFull()
    {
        return top == MaxStack - 1;
    }

    public boolean push(int newItem)
    {
        if (!isFull())
        {
            item[++top] = newItem;
            return true;
        }
        else
            return false;
    }

    public void popAll()
    {
        item = new int[MaxStack];
        top = -1;
    }

    public int pop()
    {
        if (!isEmpty())
        {
            return item[top--];
        }
        else
            return -1;
    }

    public int peak()
    {
        if (!isFull())
        {
            return item[top];
        }
        else
            return -1;
    }
}
