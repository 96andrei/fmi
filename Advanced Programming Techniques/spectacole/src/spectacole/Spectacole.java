package spectacole;

import java.io.File;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class Spectacole {
    
    public static class Range implements Comparable<Range>{
        int from, to, value;
        int index;
        public Range(int f, int t, int v){
            from = f;
            to = t;
            value = v;
        }

        @Override
        public int compareTo(Range t) {
            return to - t.to;
        }
        
        @Override
        public String toString(){
            return from + " " + to;
        }
    }

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(new File("date.in"));
        int n = sc.nextInt();
        
        Range[] list = new Range[n];
        int[] p = new int[n];
        for(int i=0; i<n; i++)
            list[i] = new Range(sc.nextInt(), sc.nextInt(), sc.nextInt());
        
        Arrays.sort(list);
        
        for(int i = 0; i<n; i++){
            p[i] = Arrays.binarySearch(list, new Range(0,list[i].from,0));
            if(p[i] < 0){
                p[i] = ~p[i] - 1;
                if(p[i]==-1)
                    p[i]=0;
            }
        }
        
        int max = 0;
        int sol[] = new int[n];
        int father[] = new int[n];
        for(int i=1; i<n; i++){
            if(list[i].value + sol[p[i]] >= sol[i-1]){
                father[i] = father[p[i]];
                sol[i] = list[i].value + sol[p[i]];
                max = i;
            }else{
                father[i] = i-1;
                sol[i] = sol[i-1];
            }
        }
        
        System.out.println(Arrays.toString(sol));
        
        
        /*for(int i=1; i<n; i++)
            if(sol[i] > sol[max])
                max = i;*/
        
        System.out.println(sol[max]);
        
        while(max != 0){
            System.out.println(list[max]);
            max = father[max];
        }
        
    }
    
}
