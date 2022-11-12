package LinkedList.SinglyLL.SelfWrite;

public class Main {
    public static void main(String[] args) {
        Node head = new Node(2);
        // Node newNode = new Node(5);
        // for (int i = 1; i < 100; i *= 2)
        for (int i = (int)head.getItem() * 2; i < 1000 / 2; i *= 2)
        // for (int i = 1; i < 1000 / 2; i *= 2)
        {
            Node newNode = new Node(i);
            // head = newNode;
            newNode.setNext(head);
            head = newNode;
        }

        // int testI = 256;
        // int testI = 128;
        int testI = 64;
        // int testI = 2;
        head.printNextNodes();

        head.search(testI);
        // head.deleteNode(testI);
        head.insertNode(999, 32);

        head.printNextNodes();
        head.search(testI);




        // Node n = new Node(9);
        // Node head = new Node(8, n);
        // n.setNext(new Node(5));

        // head.printNextNodes();
    }
}
