package Stack.StackLL;

public class StackLinkList {
    private Node top;

    public StackLinkList()
    {
        top = null;
    }

    public boolean isEmpty()
    {
        return top == null;
    }

    public void push(int newItem)
    {
        top = new Node(newItem, top);
    }

    public Object pop()
    {
        if (!isEmpty())
        {
            Node tmp = top;
            top = top.getNext();
            return tmp.getItem();
        }
        else
            return -1;
    }

    public void popAll()
    {
        top = null;
    }

    public Object peek()
    {
        if (!isEmpty())
        {
            return top.getItem();
        }
        else
            return -1;
    }
}
