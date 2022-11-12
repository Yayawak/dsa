package LinkedList.SinglyLL.Complete;

public class SinglyLinkedList
{
    Node newNode;
    Node head;
    Node curr;
    Node prev;

    public void add(Object newItem)
    {
        if (head == null)
            newNode = new Node(newItem);
        else
            newNode = new Node(newItem, head);
        head = newNode;
    }

    public boolean searchItem(Object item)
    {
        curr = head;
        prev = null;
        boolean status = false;
        while (curr != null)
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
        return status;
    }

    public void deleteNode(Object item)
    {
        if (searchItem(item))
        {
            if (prev == null)
                head = curr.getNext();
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
            if (prev == null)
            {
                newNode.setNext(curr);
                head = newNode;
            }
            else
            {
                if (head == null)
                {
                    newNode.setNext(curr);
                    head = newNode;
                }
                else if (curr == null)
                {
                    prev.setNext(newNode);
                }
            }
        }
    }

    public void showdata()
    {
        curr = head;
        while (curr != null)
        {
            System.out.println(curr.getItem() + " ");
            curr = curr.getNext();
        }
        System.out.println();
        System.out.println();
    }
}
