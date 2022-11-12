package LinkedList.StaticLL;

public class ArrayLinkList {
    private int MaxNode = 10;
    private int newNode;
    private int head = -1;
    private int curr;
    private int prev;
    private int Null = -1;
    private int countNode = 0;
    ArrayNode[] node = new ArrayNode[MaxNode];

    public ArrayLinkList()
    {
        for (newNode = 0; newNode < MaxNode; newNode++)
        {
            node[newNode] = new ArrayNode();
            node[newNode].item = Null;
            node[newNode].next = Null;
        }

    }

    public boolean isNotFull()
    {
        return countNode != MaxNode ? true : false;
    }

    private boolean findEmptyNode()
    {
        newNode = 0;
        for (newNode = 0; newNode < MaxNode; newNode++)
            if (node[newNode].item == Null)
                break;
        return newNode == MaxNode ? false : true;
    }

    public void add(int newItem)
    {
        if (isNotFull() && findEmptyNode())
        {
            node[newNode].item = newItem;
            if (head != Null)
                node[newNode].next = head;
            head = newNode;
            countNode++;
        }
        else
            System.out.println("Array Link List is Full");
    }

    public boolean searchItem(int item)
    {
        curr = head;
        prev = Null;
        boolean status = false;
        while (curr != Null)
        {
            if (node[curr].item == item)
            {
                status = true;
                break;
            }
            else
            {
                prev = curr;
                curr = node[curr].next;
            }
        }
        return status;
    }

    public void deleteNode(int item)
    {
        if (searchItem(item))
        {
            node[curr].item = Null;
            if (prev == Null)
                head = node[curr].next;
            else
                node[prev].next = node[curr].next;
            countNode--;
        }
        else
            System.out.println("Not found item");
    }

    public void insert(int itemInsert, int newItem)
    {
        if (isNotFull() && findEmptyNode())
        {
            node[newNode].item = newItem;
            countNode++;
            if (searchItem(itemInsert))
            {
                if (prev == Null)
                {
                    node[newNode].next = curr;
                    head = newNode;
                }
                else{
                    node[newNode].next = curr;
                    node[prev].next = newNode;
                }
            }
            else
            {
                if (head == Null)
                    head = newNode;
                else if (curr == Null)
                    node[prev].next = newNode;
            }
        }
        else
            System.out.println("Array Link List is already full.");
    }

    public void showData()
    {
        curr = head;
        while (curr != Null)
        {
            System.out.println(node[curr].item + " ");
            curr = node[curr].next;
        }
        System.out.println();
    }
}
