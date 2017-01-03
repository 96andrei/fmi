/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package t1e1;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;

public class T1E1 {

     public static void main(String[] args) {
        try{
            Scanner sc = new Scanner(new File("date.in"));
            PrintStream out = new PrintStream(new File("date.out"));
            int n;
            n = sc.nextInt();
            int list[] = new int[n];
            for(int i=0; i<n; i++)
                list[i] = sc.nextInt();

            sc.close();

            Arrays.sort(list);

            int left=0, right=n-1;

            for(left = 0; left < right; left++){
                for(right = n-1; right > left; right--)
                    if(list[left] + list[right] < 0){
                        int third = right-1;
                        while(third > left && list[left] + list[right] + list[third] < 0){

                            third--;
                        }
                        if(list[left] + list[right] + list[third] == 0){
                            out.println("(" + list[left] + ", " + list[third] + ", " + list[right] + ")");
                        }
                    }else{
                        int third = left+1;
                        while(third < right && list[left] + list[right] + list[third] > 0){
                            third++;
                        }
                        if(list[left] + list[right] + list[third] == 0){
                            out.println("(" + list[left] + ", " + list[third] + ", " + list[right] + ")");
                        }       
                }
            }
        }catch(FileNotFoundException ex){
            System.out.println(ex);
        }
    }

}
