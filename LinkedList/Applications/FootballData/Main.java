package LinkedList.Applications.FootballData;

import LinkedList.SinglyLL.Complete.SinglyLinkedList;

public class Main {
    public static void main(String[] args) {
        // Player[]
        // SinglyLinkedList ll = new SinglyLinkedList();
        // ll.add(new Player("halminton", 55, 1));
        SinglyLinkedList manchesPlayers = new SinglyLinkedList();
        manchesPlayers.add(new Player("bach", 30, 0));
        manchesPlayers.add(new Player("valyrion", 23, 1));
        manchesPlayers.add(new Player("stormborn", 25, 2));
        Team manchester = new Team("manchester", manchesPlayers);

        // manchesPlayers.showdata();
        manchester.printPlayers();
    }

}
