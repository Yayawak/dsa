package Hashing.Basic;

import java.util.Hashtable;

// Synchronized
public class HT {
    public static void main(String[] args) {
        Hashtable<Integer, String> hm
            = new Hashtable<>();

        hm.put(1, "Array");
        hm.put(12, "LinkedList");
        hm.put(15, "BinaryTree");
        hm.put(3, "ALETree");

        System.out.println(hm);
    }
}
