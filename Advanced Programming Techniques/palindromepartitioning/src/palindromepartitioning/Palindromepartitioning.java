/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package palindromepartitioning;

import java.io.File;
import static java.lang.Double.min;
import java.util.Arrays;
import java.util.Scanner;

/**
 *
 * @author Laura
 */
public class Palindromepartitioning {

    /**
     * @param args the command line arguments
     */
    public static void minPalPartion(String word)
    {
        int max_sz = 100000000;
       
        int n = word.length();

        /* Create two arrays to build the solution in bottom up manner
           C[i] = Minimum number of cuts needed for palindrome partitioning
                 of substring str[0..i]
           P[i][j] = true if substring str[i..j] is palindrome, else false
           Note that C[i] is 0 if P[0][i] is true */
        int [] cuts = new int[n];
        int [] p = new int[n];
        boolean [][] palindrome = new boolean[n][n];
        int i, j, k, lg; // different looping variables

        // Every substring of length 1 is a palindrome
        for (i=0; i<n; i++)
        {
            palindrome[i][i] = true;            
        }

        /* L is substring length. Build the solution in bottom up manner by
           considering all substrings of length starting from 2 to n.
        */
        for (lg=2; lg<=n; lg++)
        {
            // For substring of length lg, set different possible starting indexes
            for (i=0; i<n-lg+1; i++)
            {
                j = i+lg-1; // Set ending index

                // If L is 2, then we just need to compare two characters. Else
                // need to check two corner characters and value of P[i+1][j-1]
                if (lg == 2)
                    palindrome[i][j] = (word.charAt(i) == word.charAt(j));
                else
                    palindrome[i][j] = (word.charAt(i) == word.charAt(j)) && palindrome[i+1][j-1];
            }
            for (i=0; i<n; i++)
            {
                // IF str[i..j] is palindrome, then C[i][j] is 0
                if (palindrome[0][i] == true)
                    cuts[i] = 0;
                else
                {
                    // Make a cut at every possible localtion starting from i to j,
                    // and get the minimum cost cut.
                    cuts[i] = max_sz;
                    for (k=0; k<i; k++)
                        if(palindrome[k+1][i] == true && 1+cuts[k]<cuts[i])
                        {     
                            cuts[i]=1+cuts[k];
                            p[i] = p[k];
                        }
                }
            }
        }
        
       
        for(i=0; i<n; i++)
            System.out.println(Arrays.toString(palindrome[i]));
    }
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        //Scanner read = new Scanner(new File("data.in"));
        String word = "abcbaabc ";//read.next();
        int i,j,l;
        int n;
        int length =n= word.length();
        int[][]mat = new int[n][n];
        int total = 0;
        int subtotal;
        
        for (l = 1; l < length; l++) {
		for (i = 0; i <= length - l; i++) {
			j = i + l - 1;
			if ( word.charAt(i) == word.charAt(j)) {
				if (l == 1 || l == 2) {
					mat[i][j] = 1;
				} else {
					mat[i][j] = mat[i + 1][j - 1];
				}
				if (mat[i][j] == 1) {
					total++;//result.add(s.substring(i, j + 1));
                                        //System.out.println(word.substring(i,j+1));
				}
			} else {
				mat[i][j] = 0;
			}
		}
	}
        //System.out.println(total);
        minPalPartion(word);
    }
    
}
