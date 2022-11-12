package BinaryTree.Java.Basic;

public class Main {
    public static void main(String[] args) {
        BinaryTree tree = new BinaryTree();
        TreeNode root;
        root = tree.insert(60);
        tree.insert(20);
        tree.insert(10);
        tree.insert(40);
        tree.insert(30);
        tree.insert(50);
        tree.insert(70);
        System.out.println("Insert 60 20 10 40 30 50 70 ");
        System.out.println("Preorder : ");
        tree.preOrder(root);
        tree.deleteItem(20);
        System.out.println("\nDelete : 20");
        tree.preOrder(root);

        System.out.println("Inorder");
        tree.inOrder(root);

        System.out.println("PostOrder");
        tree.postOrder(root);
    }
}
