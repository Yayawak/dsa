package Hashing.Basic;

import java.util.HashSet;
import java.util.Iterator;

// Maintains only keys
public class HSet {
    public static void main(String[] args) {
        HashSet<String> h = new HashSet<>();

        h.add("India");
        h.add("Korean");
        h.add("China");
        h.add("Korean"); // set properties

        System.out.println(h);
        h.remove("India");
        System.out.println(h);

        System.out.println("Iteration\n");
        h.add("Canada");
        h.add("Hawaii");

        Iterator<String> iterator = h.iterator();
        while (iterator.hasNext())
        // while (h.iterator().hasNext())
            System.out.println(iterator.next());
    }
}
