package Hashing.Basic;

import java.util.LinkedHashMap;
// import java.util.

public class LinkedHM {
    public static void main(String[] args) {
        LinkedHashMap<String, String> lhm =
            new LinkedHashMap<>();
        lhm.put("one", "practice linked list / node");
        lhm.put("two", "dijkstra algorithm");
        lhm.put("four", "krugskal");
        lhm.put("nine", "Stack");

        System.out.println(lhm);

        System.out.println("Getting value for key 'one' : "
            + lhm.get("one"));

        System.out.println("Size of the map : " + lhm.size());
        System.out.println("Is map empty ? " + lhm.isEmpty());
        System.out.println("Delete key 'two : " + lhm.remove("two"));

        System.out.println(lhm.toString());

    }
}
