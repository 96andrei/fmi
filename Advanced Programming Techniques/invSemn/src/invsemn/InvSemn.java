package invsemn;

import java.io.File;
import java.util.Arrays;
import java.util.Scanner;

public class InvSemn {

    static int inv = 0;

    static void merge(int a[], int left, int mid, int right, int b[]) {
        int i0 = left, i1 = mid;
        for (int i = left; i < right; i++) {
            if (i0 < mid && ((i1 >= right) || (a[i0] <= a[i1]))) {
                b[i] = a[i0];
                i0++;
            } else {
                if (a[i1] < a[i0]) {
                    inv += mid - i0;
                }
                b[i] = a[i1];
                i1++;
            }
        }
    }

    static void copy(int source[], int left, int right, int result[]) {
        System.arraycopy(source, left, result, left, right - left);
    }

    static void mergeSort(int array[], int left, int right, int aux[]) {

        if (right - left == 1) {
            return;
        }

        int mid = (left + right) / 2;
        mergeSort(array, left, mid, aux);
        mergeSort(array, mid, right, aux);
        merge(array, left, mid, right, aux);
        copy(aux, left, right, array);
    }

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(new File("date.in"));

        int n = sc.nextInt();

        int[] list = new int[n];
        int[] aux = new int[n];

        for (int i = 0; i < n; i++) {
            list[i] = sc.nextInt();
        }

        mergeSort(list, 0, n, aux);

        System.out.println(inv);
        System.out.println(Arrays.toString(aux));
    }

}
