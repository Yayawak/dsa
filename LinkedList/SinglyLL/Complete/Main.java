package LinkedList.SinglyLL.Complete;

public class Main {
    public static void main(String[] args) {
        // SinglyLinkedList linkedList = new SinglyLinkedList();
        SinglyLinkedList ll = new SinglyLinkedList();
        // linkedList
        ll.add(9);
        ll.add(10);
        ll.add(11);
        ll.add(12);
        ll.showdata();

        // ll.deleteNode(10);
        ll.insert(10, 99);
        ll.showdata();
        // ll
    }
}
