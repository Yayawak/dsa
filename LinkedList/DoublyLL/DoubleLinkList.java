package LinkedList.DoublyLL;

import javax.lang.model.util.ElementScanner14;
import javax.swing.text.StyledEditorKit.BoldAction;

import LinkedList.DoublyLL.Complete.DoubleLink;

public class DoubleLinkList {
    DoubleLink newNode;
    DoubleLink head;
    DoubleLink last;
    DoubleLink curr;
    DoubleLink prev1;
    DoubleLink prev2;

    public void add(Object newItem)
    {
        if (head == null)
        {
            newNode = new DoubleLink(newItem);
            last = newNode;
        }
        else
        {
            newNode = new DoubleLink(newItem, head, null);
            head.setPrecede(newNode);
            head = newNode;
        }
        head = newNode;
    }

    public boolean searchItem(Object item)
    {
        curr = head;
        prev1 = null;
        boolean status = false;
        while (curr != null)
        {
            if (curr.getItem() == item)
            {
                // prev2 always next to prev2 (on right side)
                prev2 = curr.getNext();
                status = true;
                break;
            }
            else
            {
                prev1 = curr;
                curr = curr.getNext();
            }
        }
        return status;
    }

    public void deleteNode(Object item)
    {
        if (searchItem(item))
        {
            if (prev1 == null)
            {
                head = curr.getNext();
                if (prev2 != null)
                    prev2.setPrecede(null);
            }
            else if (prev2 == null)
            {
                prev1.setNext(null);
                curr.setPrecede(null);
                last = prev1;
            }
            else
            {
                prev1.setNext(curr.getNext());
                prev2.setPrecede(curr.getPrecede());
            }
        }
        else
        {
            System.out.println("Not found data");
        }
    }

    public void insert(Object itemInsert, Object newItem)
    {
        newNode = new DoubleLink(newItem);
        if (searchItem(itemInsert))
        {
            prev2 = curr;
            if (prev1 == null)
            {
                newNode.setNext(curr);
                curr.setPrecede(newNode);
                head = newNode;
            }
            else
            {
                newNode.setNext(prev1.getNext());
                prev1.setNext(newNode);
                newNode.setPrecede(prev2.getPrecede());
                prev2.setPrecede(newNode);
            }
        }
        else
        {
            if (head == null)
            {
                newNode = new DoubleLink(newItem);
                last = newNode;
            }
            else
            {
                newNode = new DoubleLink(newItem, null, last);
                last.setNext(newNode);
                last = newNode;
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
        if (head != null)
        {
            System.out.println("backward : ");
            curr = last;
            while (curr != null)
            {
                System.out.println(curr.getItem());
                curr = curr.getPrecede();
            }
        }
        System.out.println("\n\n");
    }
}
