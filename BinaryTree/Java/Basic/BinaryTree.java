package BinaryTree.Java.Basic;

public class BinaryTree {
    TreeNode root;
    TreeNode newNode;
    TreeNode parent;
    TreeNode nodeDelete;
    char child;
    int countLevel;

    public boolean isEmpty()
    {
        return root == null;
    }

    public void insertItem(TreeNode bst, int newItem)
    {
        if (newItem < bst.item)
        {
            if (bst.l == null)
            {
                newNode = new TreeNode(newItem);
                bst.l = newNode;
            }
            else
                insertItem(bst.l, newItem);
        }
        else
        {
            if (bst.r == null)
            {
                newNode = new TreeNode(newItem);
                bst.r = newNode;
            }
            else
                insertItem(bst.r, newItem);
        }
    }

    public TreeNode insert(int newItem)
    {
        if (isEmpty())
        {
            newNode = new TreeNode(newItem);
            root = newNode;
        }
        else
            insertItem(root, newItem);
        return root;
    }

    public void search(TreeNode bst, int searchKey)
    {
        if (searchKey == bst.item)
            nodeDelete = bst;
        else if (searchKey < bst.item)
        {
            parent = bst;
            child = 'l';
            search(bst.l, searchKey);
        }
        else
        {
            parent = bst;
            child = 'r';
            search(bst.r, searchKey);
        }
    }

    public void inordersuccessor(TreeNode bst)
    {
        if (bst.l != null)
        {
            parent = bst;
            ++countLevel;
            inordersuccessor(bst.l);
        }
        else
        {
            nodeDelete.item = bst.item;
            if (countLevel == 0)
                nodeDelete.r = null;
            else
                parent.l = null;
        }
    }

    public void deleteItem(int deleteItem)
    {
        if (isEmpty())
            System.out.println("Tree Empty");
        else
        {
            parent = root;
            nodeDelete = null;
            search(root, deleteItem);
            TreeNode l = nodeDelete.l;
            TreeNode r = nodeDelete.r;
            if ((l == null) && (r == null))
            {
                if (child == 'l')
                    parent.l = null;
                else
                    parent.r = null;
            }
            else if ((l != null) && (r != null))
            {
                countLevel = 0;
                inordersuccessor(nodeDelete.r);
            }
            else
            {
                if (nodeDelete.l != null)
                {
                    if (child == 'l')
                        parent.l = nodeDelete.l;
                    else
                        parent.r = nodeDelete.l;
                }
                else
                {
                    if (child == 'l')
                        parent.l = nodeDelete.r;
                    else
                        parent.r = nodeDelete.r;
                }
            }
        }
    }

    public void preOrder(TreeNode rootNode)
    {
        if (rootNode != null)
        {
            System.out.println(rootNode.item + " ");
            preOrder(rootNode.l);
            preOrder(rootNode.r);
        }
    }

    public void inOrder(TreeNode rootNode)
    {
        if (rootNode != null)
        {
            inOrder(rootNode.l);
            System.out.println(rootNode.item + " ");
            inOrder(rootNode.r);
        }
    }
    public void postOrder(TreeNode rootNode)
    {
        if (rootNode != null)
        {
            postOrder(rootNode.l);
            postOrder(rootNode.r);
            System.out.println(rootNode.item + " ");
        }
    }
}
