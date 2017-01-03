/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package joculetinfoarena;

import java.io.File;
import static java.lang.Integer.max;
import static java.lang.Math.abs;
import java.util.Random;
import java.util.Scanner;

/**
 *
 * @author Laura
 */
public class JoculetInfoarena {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception {
        // TODO code application logic here
        Scanner read = new Scanner(new File("date.in"));
        int n = read.nextInt();
        int[] a = new int[n + 1];
        int[][] dp = new int[n + 1][n + 1];
        int i, j, lg;

        for (i = 1; i <= n; i++) {
            a[i] = read.nextInt();
        }
        if (n == 1) {
            System.out.println(a[1] + "\n");
        } else {
            //dp[i,j]=  diferenta maxima care o poate obtine jucatorul care este la mutare daca are la dispozitie o tabla cu nr de la i la j

            for (i = 1; i <= n; i++) {
                dp[i][i] = a[i]; //cuv de lg 1
            }
            for (i = 1; i < n; i++) {
                dp[i][i + 1] = abs(a[i] - a[i + 1]); //cuv de lg 2
            }
            for (lg = 2; lg < n; lg++) {
                for (i = 1; i <= n - lg; i++) {
                    j = i + lg;
                    dp[i][j] = (max(a[j] - dp[i][j - 1], a[i] - dp[i + 1][j]));
                }
            }
            System.out.println(dp[1][n] + "\n");
        }
        //play a game
        int first = 1, last = n;
        int s1=0,s2=0;
        Random rand = new Random();        
        for (i = 1; i <= n && last >=1 && first<=n; i++) 
        {            
            if(i%2==0) //player turn
            {
                if (rand.nextInt(2) == 1) //j2 alege sa mute la inceput
                {   
                  //  System.out.println("Suma la pasul "+i+" va fi mai mare cu "+ dp[first][last] );
                  //  System.out.print(" S ");
                    s2+=a[first];
                    first++;                    
                }
                 else 
                {   
                  //  System.out.println("Suma la pasul "+i+" va fi mai mare cu "+ dp[first][last] );
                  //   System.out.print(" D ");
                    s2+=a[last];
                    last--; //j2 alege sa mute la sfarsit                    
                }
            }
                
            else  //computer turn
            { 
              if(first == n){    
                  s1+=a[first];
                 System.out.println("Suma la pasul "+i+" va fi mai mare cu "+ (s1- s2) );
               //   System.out.print(" S ");
                  first++;
              }
              else if(last == 1)
              {
                  s1+=a[last];
                  System.out.println("Suma la pasul "+i+" va fi mai mare cu "+ (s1- s2) );
               //    System.out.print(" D ");
                  last--;
              }
              else {
                if( a[first] - dp[first+1][last] >= a[last] - dp[first][last-1]) //j1 alege nr de la inceput
                {
                    
                   System.out.println("Suma la pasul "+i+" va fi mai mare cu "+ (s1+a[first] - dp[first+1][last]-s2) );
                  //   System.out.print(" S ");
                    s1+=a[first];    
                    first++;
                }
                else
                {
                    
                    System.out.println("Suma la pasul "+i+" va fi mai mare cu "+ (s1+a[last] - dp[first][last-1]-s2));
                 //    System.out.print(" D ");
                    s1+=a[last];
                    last--;
                }
              }
              
            }
        }
    }
}
