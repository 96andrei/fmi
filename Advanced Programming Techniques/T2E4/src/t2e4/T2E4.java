/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package t2e4;

import java.io.File;
import java.util.Scanner;

/**
 *
 * @author a96an
 */
public class T2E4 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception{
        BinarySearchTree<Integer> bst = new BinarySearchTree<>();
        
        Scanner sc = new Scanner(new File("date.in"));
        
        while(sc.hasNextInt()){
            bst.add(sc.nextInt());
        }
        
        System.out.println(bst);
        
        BinarySearchTree<Person> pt = new BinarySearchTree();
        
        pt.add(new Person("Ion", 20));
        pt.add(new Programmer("Alex", 23, "C++"));
        pt.add(new Programmer("Marius", 19, "Java"));
        pt.add(new Person("Dorel", 28));
        
        System.out.println(pt);
        
        BinarySearchTree<Integer> bst1 = new  BinarySearchTree<>();
        BinarySearchTree<Integer> bst2 = new  BinarySearchTree<>();
        
        bst1.add(3);
        bst1.add(1);
        bst1.add(2);
        bst2.add(2);
        bst2.add(3);
        bst2.add(1);
        
        System.out.println(bst1.equals(bst2));
        System.out.println(bst1.hashCode() == bst2.hashCode());
        
        BinarySearchTree<String> bsts1 = new  BinarySearchTree<>();
        BinarySearchTree<String> bsts2 = new  BinarySearchTree<>();
        
        bsts1.add("Alex");
        bsts2.add("Alex");
        bsts1.add("Ion");
        bsts2.add("Ion");
        
        System.out.println(bsts1.equals(bsts2));
         System.out.println(bsts1.hashCode() == bsts2.hashCode());
    }
    
}
