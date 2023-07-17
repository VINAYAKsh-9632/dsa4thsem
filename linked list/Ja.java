import java.util.*;

public class Ja {
    public class Node {
        int data;
        Node left;
        Node right;

        public Node(int data) {
            this.data = data;
            this.left = null;
            this.right = null;
        }
    }

    public static Node insert(Node root, int val) {
        Node newNode = new Node(val);
        if (root == null) {
            root = newNode;
            return root;
        } else if (root.data > val) {
            // leftsubtree
            root.left = insert(root.left, val);

        } else {
            root.right = insert(root.right, val);
        }
        return root;
    }

    public static void inorder(Node root) {
        if (root == null) {
            return;
        }
        inorder(root.left);
        System.out.print(root.data + " ");
        inorder(root.right);
    }

    public static void main(String[] args) {
        Node root = null;
        int val[] = { 5, 1, 3, 4, 2, 7 };
        for (int i = 0; i < val.length; i++) {
            root = insert(root, val[i]);
        }
        System.out.println();

        inorder(root);
    }
}