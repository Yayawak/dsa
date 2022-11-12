package BinaryTree.Java.Basic;

public class TreeNode {
    protected int item;
    protected TreeNode l;
    protected TreeNode r;

    public TreeNode(int newItem)
    {
        item = newItem;
        l = null;
        r = null;
    }

    public TreeNode(int newItem, TreeNode l, TreeNode r)
    {
        this.item = newItem;
        this.l = l;
        this.r = r;
    }

    public void setItem(int newItem)
    {
        item = newItem;
    }

    public int getItem()
    {
        return item;
    }

    public void setL(TreeNode newL)
    {
        l = newL;
    }

    public void setR(TreeNode newR)
    {
        r = newR;
    }

    public TreeNode getL()
    {
        return l;
    }

    public TreeNode getR()
    {
        return r;
    }
}
