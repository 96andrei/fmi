package t2e4;

import java.util.Objects;
import java.util.Stack;

public class BinarySearchTree<E extends Comparable> {
        class Node<E>{
            E info;
            Node left, right;
            public Node(){
                
            }
            
            public Node(E info){
                this.info = info;
            }
            
            public void setInfo(E info){
                this.info = info;
            }
            
            public E getInfo(){
                return info;
            }
            
            public void setLeft(Node left){
                this.left = left;
            }
            
            public Node getLeft(){
                return left;
            }
            
            public void setRight(Node right){
                this.right = right;
            }
            
            public Node getRight(){
                return right;
            }
            
            @Override
            public int hashCode(){
                int h = 1;
                h += Objects.hashCode(info) + Objects.hashCode(left) + Objects.hashCode(right);
                return h;
            }
        }
        
        Node root = null;
        
        public boolean add(E item){
            
            if(root == null){
                root = new Node(item);
                return true;
            }else{
                boolean done = false;
                Node current = root;
                while(!done){
                    if(item.compareTo(current.getInfo())< 0){
                        if(current.getLeft() == null){
                            current.setLeft(new Node(item));
                            return true;
                        }else{
                            current = current.getLeft();
                        }
                    }else if(item.compareTo(current.getInfo()) > 0){
                        if(current.getRight() == null){
                            current.setRight(new Node(item));
                            return true;
                        }else{
                            current = current.getRight();
                        }
                    }else{
                        return false;
                    }
                }
            }
            
            return false;
        }
        
        public String toString(){
            String result = "";
            
            Stack<Node> s = new Stack<>();
            //s.push(root);
            Node current = root;
            while(current != null){
                    s.push(current);
                    current = current.getLeft();
                }
            
            while(!s.empty()){
                current = s.pop();
                
                result += current.getInfo() + " ";
                
                if(current.getRight() != null){
                    
                    current = current.getRight();
                    
                    while(current != null){
                        s.push(current);
                        current = current.getLeft();
                    }
                }
            }
            return result;
        }
        
        @Override
        public boolean equals(Object o){
            return toString().equals(o.toString());
        }

    @Override
    public int hashCode() {
        int hash = 5;
        hash += Objects.hashCode(this.root);
        return hash;
    }
        
}
