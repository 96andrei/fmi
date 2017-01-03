package partinterval;

import java.io.File;
import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.Scanner;
import java.util.Stack;

public class PartInterval {
    
    public static class Stiva extends Stack<Interval> implements Comparable<Stiva>{

        @Override
        public int compareTo(Stiva t) {
            return this.peek().getF() - t.peek().getF();
        }
        
        @Override 
        public String toString(){
            String s = "";
            
            for(Interval i : this){
                s+= i.getIndex() + " ";
            }
            
            return s;
        }
        
    }
    
    public static void main(String[] args) throws Exception{
        
        Scanner sc = new Scanner(new File("date.in"));
        
        int n = sc.nextInt();
        
        ArrayList<Interval> list = new ArrayList<>();
        
        for(int i=0; i<n; i++){
            int x,y;
            x = sc.nextInt();
            y = sc.nextInt();
            
            list.add(new Interval(i+1, x, y));
        }
        
        list.sort(null);
        
        /*list.forEach((i) -> {
            System.out.println(i.getS() + " " + i.getF());
        });*/
        
        PriorityQueue<Stiva> q = new PriorityQueue<>();
        
        for(Interval i : list){
            
            Stiva st = new Stiva();
            st.add(i);
            
            if(q.isEmpty())
                q.add(st);
            else if(q.peek().peek().getF() < i.getS()){
                q.peek().add(st.pop());
                q.add(q.poll());
            }
            else
                q.add(st);
        }
        
        for(Stiva s : q){
            System.out.println(s);
        }
        
    }
    
}
