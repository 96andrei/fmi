/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package t1e4;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Scanner;

/**
 *
 * @author a96an
 */
public class T1E4 {

    
    public static void encrypt(String key){
        String text = "";
        String result = "";
        
        try{
            Scanner sc = new Scanner(new File("date.in"));
            
            while(sc.hasNextLine()){
                if(text != "")
                    text += "\n";
                text += sc.nextLine();
            }
            
            //System.out.println(text);
            
            int k = text.length();
            int n = key.length();
            for(int i=0; i<k; i++){
                result += text.charAt(i) ^ key.charAt(i%n);
                result += " ";
            }
            
            PrintStream out = new PrintStream(new File("date.out"));
            out.println(result);
            
        }catch(FileNotFoundException ex){
            
        }
    }
    
    public static void decrypt(String key){
        ArrayList<Integer> enc = new ArrayList<Integer>();
        String result = "";
        
        try{
            Scanner sc = new Scanner(new File("date.out"));
            
            while(sc.hasNextInt()){
                enc.add(sc.nextInt());
            }
            
            //System.out.println(text);
            
            int k = enc.size();
            int n = key.length();
            for(int i=0; i<k; i++){
                int x = enc.get(i) ^ key.charAt(i%n);
                
                result += (char)x;
            }
            
            PrintStream out = new PrintStream(new File("date.in"));
            out.println(result);
            
        }catch(FileNotFoundException ex){
            
        }
    }
    
    public static void main(String[] args) {
        
        Scanner sc = new Scanner(System.in);
        
        String key = sc.nextLine();
        
        //encrypt(key);
        decrypt(key);
    }
    
}
