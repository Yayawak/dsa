package LinkedList.CircularLL;

public class Main {
    public static void main(String[] args) {
        CircularLinkList cl = new CircularLinkList();
        for (int i = 10; i <= 20; i++)
        {
            cl.add(i);
        }
        cl.deleteNode(15);
        cl.insert(17, 99);
        cl.showdata();
    }
}
