/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package mediana;

import java.io.File;
import java.util.Arrays;
import java.util.Scanner;

public class Mediana {

    public static float findMedian(int[] a, int[] b) {
        int n1 = a.length;
        int n2 = b.length;
        if (n1 < n2) {
            return findMedian(b, a);                                            //O(1) preprocesare
        }
        if (n2 == 0) {
            return ((float) a[(n1 - 1) / 2] + (float) a[n1 / 2]) / 2;           //O(1) caz banal, un vector gol
        }
        int lo = 0, hi = n2 * 2;
        while (lo <= hi) {
            int mid2 = (lo + hi) / 2;                                           //
            int mid1 = n1 + n2 - mid2;                                          // O(1)

            float L1 = (mid1 == 0) ? Integer.MIN_VALUE : a[(mid1 - 1) / 2];	//
            float L2 = (mid2 == 0) ? Integer.MIN_VALUE : b[(mid2 - 1) / 2];     //
            float R1 = (mid1 == n1 * 2) ? Integer.MAX_VALUE : a[(mid1) / 2];    // O(1)
            float R2 = (mid2 == n2 * 2) ? Integer.MAX_VALUE : b[(mid2) / 2];    //

            if (L1 > R2) {                                                      //
                lo = mid2 + 1;                                                  // alege noile capete si repeta 
            } else if (L2 > R1) {                                               // (echivalentul unui apel recursiv)
                hi = mid2 - 1;                                                  // 
            } else {
                return (Math.max(L1, L2) + Math.min(R1, R2)) / 2;               
            }
        }
        return -1;
    }

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(new File("date.in"));
        int m, n;
        int[] a, b;

        n = sc.nextInt();
        a = new int[n];

        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }

        m = sc.nextInt();
        b = new int[m];

        for (int i = 0; i < m; i++) {
            b[i] = sc.nextInt();
        }

        System.out.println(findMedian(a, b));

    }

}
