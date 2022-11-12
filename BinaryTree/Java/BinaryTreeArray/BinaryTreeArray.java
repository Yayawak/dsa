package BinaryTree.Java.BinaryTreeArray;

public class BinaryTreeArray {
    int MaxNode = 10;
    int root = -1;
    int Null = 01;
    int newNode;
    int countNode = 0;
    int parent;
    int nodeDelete;
    char child;
    int countLevel;
    TreeArray[] node = new TreeArray[MaxNode];

    public BinaryTreeArray()
    {
        for (newNode = 0; newNode < MaxNode; newNode++)
        {
            node[newNode] = new TreeArray();
            node[newNode].item = Null;
            node[newNode].l = Null;
            node[newNode].r = Null;
        }
    }

    public boolean isNotFull()
    {
        return countNode != MaxNode;
    }

    public boolean isEmpty()
    {
        return root == Null;
    }

    public boolean findEmptyNode()
    {
        newNode = 0;
        for (newNode = 0; newNode < MaxNode; newNode++)
            if (node[newNode].item == Null)
                break;
        return newNode != MaxNode;
    }

    // public void insertItem(int root, int newItem)
    private void insertItem(int root, int newItem)
    {
        if (newItem < node[root].item)
            if (node[root].l == Null)
                node[root].l = newNode;
            else
                insertItem(node[root].l, newItem);
        else
            if (node[root].r == Null)
                node[root].r = newNode;
            else
                insertItem(node[root].r, newItem);
    }

    public void insert(int newItem)
    {
        if (isNotFull() && findEmptyNode())
        {
            node[newNode].item = newItem;
            if (root != Null)
                insertItem(root, newItem);
            else
                root = newNode;
            countNode++;
        }
        else
            System.out.println("Tree array is Full");
    }

    public void search(int root, int searchKey)
}
