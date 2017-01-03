package arbore;

import java.io.File;
import java.util.Arrays;
import java.util.Scanner;

public class Arbore {

    public static final class Tree {

        Node root;

        int[] in, post, pre, inIndex;

        public Tree(int[] in, int[] post) throws cantBuildTreeException {
            this.in = in;
            this.post = post;
            inIndex = new int[in.length + 1];
            for (int i = 0; i < in.length; i++) {
                inIndex[in[i]] = i;
            }
            root = buildTree();
            pre = new int[in.length];
            makePre(root);
        }

        void makePre(Node node) {
            if (node == null) {
                return;
            }
            makePre(node, 0);
        }

        int makePre(Node node, int index) {
            pre[index] = node.value;
            index++;

            if (node.left != null) {
                index = makePre(node.left, index);
            }
            if (node.right != null) {
                index = makePre(node.right, index);
            }

            return index;
        }

        public int[] getPre() {
            return pre;
        }

        public int[] getIn() {
            return in;
        }

        public int[] getPost() {
            return post;
        }

        public Node buildTree() throws cantBuildTreeException {
            int inStart = 0;
            int inEnd = in.length - 1;
            int postStart = 0;
            int postEnd = post.length - 1;

            return buildTree(inStart, inEnd, postStart, postEnd);
        }

        public Node buildTree(int inStart, int inEnd, int postStart, int postEnd) throws cantBuildTreeException {
            if (inStart > inEnd || postStart > postEnd) {
                return null;
            }

            int rootValue = post[postEnd];                                      //
            Node root = new Node(rootValue);                                    // O(1)
            int k = inIndex[rootValue];                                         //

            if (k > inEnd || k < inStart) {
                throw new cantBuildTreeException();
            }

            //postStart + k - (inStart + 1)) = lungimea sirului in care caut
            root.left = buildTree(inStart, k - 1, postStart,                    //
                    postStart + k - (inStart + 1));                             //apel recusiv 1
            root.right = buildTree(k + 1, inEnd, postStart + k - inStart,       //
                    postEnd - 1);                                               //apel recusiv 2

            return root;
            
                                                                                //fara combinare
        }

    }

    public static class Node {

        Node left;
        Node right;
        int value;

        public Node(int value) {
            this.value = value;
            left = right = null;
        }
    }

    public static void main(String[] args) throws Exception {

        int n;
        int[] post, in;
        Scanner sc = new Scanner(new File("date.in"));

        n = sc.nextInt();

        post = new int[n];
        in = new int[n];

        for (int i = 0; i < n; i++) {
            post[i] = sc.nextInt();
        }

        for (int i = 0; i < n; i++) {
            in[i] = sc.nextInt();
        }

        Tree tree = null;
        try {
            tree = new Tree(in, post);
        } catch (cantBuildTreeException ex) {
            System.out.println("nu");
        }

        if (tree != null) {
            System.out.println(" pre: " + Arrays.toString(tree.getPre()));
            System.out.println("  in: " + Arrays.toString(tree.getIn()));
            System.out.println("post: " + Arrays.toString(tree.getPost()));
        }

    }

}
