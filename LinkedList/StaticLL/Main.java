package LinkedList.StaticLL;

public class Main {
    public static void main(String[] args) {
        ArrayLinkList linkList = new ArrayLinkList();
        for (int i = 0; i < 10; i++)
        {
            linkList.add(i);
        }
        linkList.deleteNode(8);
        // linkList.insert(8, 99);
        linkList.insert(3, 99);
        linkList.showData();

    }
}
