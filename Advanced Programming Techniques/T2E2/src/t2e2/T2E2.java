/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package t2e2;

import java.io.File;
import java.io.PrintStream;
import java.util.Scanner;

public class T2E2 {

    public static void main(String[] args) throws Exception{
       Scanner sc = new Scanner(new File("date.in"));
            int n = sc.nextInt();
            int m = sc.nextInt();
            
            Graf g = new Graf(n);
            for(int i=0; i<m; i++){
                int x = sc.nextInt();
                int y = sc.nextInt();
                g.add(x,y);
                g.add(y,x);
            }
            
            int start = sc.nextInt();
            
            //System.out.print(g.getLists());
            PrintStream out = new PrintStream(new File("date.out"));
            out.print(g.getLists());
            out.println(g.getBreadth(start));
    }
    
}
