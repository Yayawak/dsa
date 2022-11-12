package Queue.Java.QueueCLL;

public class Main {
    public static void main(String[] args) {
        try {
            Queue q = new Queue();
            for (int i = 0; i < 9; i++)
            {
                q.enqueue(i);
            }
            while (!q.isEmpty())
                System.out.println(q.dequeue() + " ");
        } catch (Exception e) {
            System.out.println("Error : " + e);
        }
    }
}
