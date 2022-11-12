package LinkedList.DoublyLL.Complete;

import LinkedList.DoublyLL.DoubleLinkList;

public class Main {
    public static void main(String[] args) {
        DoubleLinkList ll = new DoubleLinkList();
        for (int i = 9; i <= 18; i++)
        {
            ll.add(i);
        }
        ll.deleteNode(11);
        ll.deleteNode(13);
        // ll.add(9);
        ll.insert(10, 99);
        // ll.add(10);
        ll.showdata();

        // DoubleLink curr = new
        // DoubleLink n = new DoubleLink(6);
        // DoubleLink first = new DoubleLink(9, n, null);
        // n.setPrecede(n);
    }
}
