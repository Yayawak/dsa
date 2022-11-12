package LinkedList.Applications.FootballData;

import LinkedList.SinglyLL.Complete.SinglyLinkedList;

public class Team {

    String name;
    SinglyLinkedList players = new SinglyLinkedList();

    public Team(String name)
    {
        this.name = name;
    }

    public Team(String name, SinglyLinkedList players)
    {
        this.name = name;
        this.players = players;
    }

    public void addPlayer(Player player)
    {
        players.add(player);
    }

    public void deletePlayer(Player player)
    {
        players.deleteNode(player);
    }

    public void printPlayers()
    {
        players.showdata();
        // players.
        // players.
    }

}
