package LinkedList.SinglyLL.SelfWrite;

public class Node {
    private Object item;
    private Node next;

    // Head node
    public Node()
    {
        next = null;
    }
    public Node(Object newItem)
    {
        item = newItem;
        next = null;
    }

    public Node(Object newItem, Node nextNode)
    {
        item = newItem;
        next = nextNode;
    }

    public void setItem(Object newItem)
    {
        item = newItem;
    }

    public Object getItem()
    {
        return item;
    }

    public void setNext(Node nextNode)
    {
        next = nextNode;
    }

    public Node getNext()
    {
        return next;
    }

    public void printNextNodes()
    {
        Node tmpNode = this;
        while (tmpNode != null)
        {
            // System.out.printf("Current node %d : %d -> \t",
            // System.out.printf("Current node : %d -> \t",
            System.out.printf("Node : %d -> \t",
                (int)tmpNode.item);
            tmpNode = tmpNode.next;
        }
        System.out.println();
        System.out.println();
    }

    public void insertNode(int toInsert, int where)
    {
        Node cur = this;
        Node prev = null;
        while (cur != null)
        {
            if ((int)cur.getItem() == (int)where)
            {
                Node newNode = new Node(toInsert);
                prev.setNext(newNode);
                newNode.setNext(cur);
                // cur.setNext();
                System.out.printf("Insert : %d at node %s\n",
                    (int)newNode.item, cur);
                break;
            }
            else
            {
                prev = cur;
                cur = cur.getNext();
            }
        }
    }
    public void deleteNode(Object toFind)
    {
        Node cur = this;
        Node prev = null;
        while (cur != null)
        {
            if ((int)cur.getItem() == (int)toFind)
            {
                System.out.printf("Delete : %d at node %s\n",
                    cur.getItem(), cur);
                prev.setNext(cur.getNext()); // skip middle node
                cur.setNext(null);
                break;
            }
            else
            {
                prev = cur;
                cur = cur.getNext();
            }
        }
    }
    public void search(Object toFind)
    // public void search(int toFind)
    {
        Node cur = new Node();
        Node prev = new Node();
        cur = this;
        prev = null;
        while (cur != null)
        {
            if ((int)cur.getItem() == (int)toFind)
            {
                System.out.printf("Found : %d at node %s\n",
                    cur.getItem(), cur);
                break;
            }
            else
            {
                prev = cur;
                cur = cur.getNext();
            }
        }
    }
}
