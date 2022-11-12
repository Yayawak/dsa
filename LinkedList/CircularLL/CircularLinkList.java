package LinkedList.CircularLL;

public class CircularLinkList
{
    private Node newNode;
    private Node head;
    private Node lastNode;
    private Node curr;
    private Node prev;

    public void add(Object newItem)
    {
        if (head == null)
        {
            newNode = new Node(newItem);
            lastNode = newNode;
        }
        else
            newNode = new Node(newItem, head);
        lastNode.setNext(newNode);;
        head = newNode;
    }

    public boolean searchItem(Object item)
    {
        curr = head;
        prev = null;
        boolean status = false;
        do
        {
            if (curr.getItem() == item)
            {
                status = true;
                break ;
            }
            else
            {
                prev = curr;
                curr = curr.getNext();
            }
        }
        while (curr != null);
        return status;
    }

    public void deleteNode(Object item)
    {
        if (searchItem(item))
        {
            // 1st case : found at head of ll
            if (prev == null)
            {
                head = curr.getNext();
                lastNode.setNext(curr.getNext());
                curr.setNext(null);
            }
            // 2nd case : found at tail of ll
            else if (curr == lastNode)
            {
                // prev.setNext(lastNode);
                prev.setNext(lastNode.getNext());
                // lastNode = curr;
                lastNode = prev;
                // lastNode.setNext(head);
                // curr = null;
                curr.setNext(null);
                // lastNode = null;
                // curr.setNext(null);
            }
            // 3rd case : handling inter-node
            else
                prev.setNext(curr.getNext());
        }
        else
            System.out.println("Not found item");
    }

    public void insert(Object itemInsert, Object newItem)
    {
        newNode = new Node(newItem);
        if (searchItem(itemInsert))
        {
            // at head
            if (prev == null)
            {
                // newNode.setNext(head.getNext());
                newNode.setNext(curr);
                head = newNode;
                lastNode.setNext(head);
                // newNode.setNext(curr);
                // head = newNode;
            }
            else
            {
                newNode.setNext(curr);
                prev.setNext(newNode);
            }
        }
        else
        {
            if (head == null)
            {
                newNode.setNext(curr);
                head = newNode;
            }
            else if (curr == head)
            {
                newNode.setNext(head);
                lastNode.setNext(newNode);
                lastNode = newNode;
            }
        }
    }

    public void showdata()
    {
        curr = head;
        while (curr != lastNode)
        {
            System.out.println(curr.getItem() + " ");
            curr = curr.getNext();
        }
        System.out.println(curr.getItem() + " "); // remainder of lastnode
        System.out.println("head data = " + curr.getItem());
        System.out.println();
    }
}
