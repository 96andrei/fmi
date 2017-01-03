package subsirdesc;

import java.io.File;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;
import java.util.Stack;

public class SubsirDesc {
    
    public static class Stiva extends Stack<Integer> implements Comparable<Stiva>{
        
        @Override
        public int compareTo(Stiva t) {
            return this.peek() - t.peek();
        }
        
    }
    
    public static void main(String[] args) throws Exception{
        
        Scanner sc = new Scanner(new File("date.in"));
        
        int n;
        
        n = sc.nextInt();
        
        ArrayList<Stiva> sol = new ArrayList<>();
        
        int[] list = new int[n];
        
        for(int i=0; i<n; i++){
            int x = sc.nextInt();
            list[i] = x;
        }
        
        
        
        for(int i=0; i<n; i++){
            int x = list[i];
            
            Stiva st = new Stiva();
            st.push(x);
            int index = Collections.binarySearch(sol, st);
            
            if(index < 0)
                index = ~index;
            
            if(index == sol.size())
                sol.add(st);
            else{
                sol.get(index).push(x);
            }
        }
        
        for(int i=0; i<sol.size(); i++){
            System.out.println(sol.get(i));
        }
        
        System.out.println("Patience Sort");
       
        for(int i=0; i<n; i++){
            Stiva st = Collections.min(sol);
            System.out.print(st.pop() + " ");
            if(st.isEmpty()){
                sol.remove(st);
            }
        }
        
    }
    
}
