package planminmax;

import java.io.File;
import java.util.ArrayList;
import java.util.Scanner;

public class PlanMinMax {


    public static void main(String[] args) throws Exception{
        
       Scanner sc = new Scanner(new File("date.in"));
        
        int n;
        n = sc.nextInt();
        
        ArrayList<Interval> list = new ArrayList<>();
        for(int i=0; i<n; i++){
            int x = sc.nextInt();
            int y = sc.nextInt();
            Interval in = new Interval(i+1, x,y);
            list.add(in);
        }
        
        list.sort(null);
        
        int currentTime = 0;
        
        int maxDelay = 0;
        
         for(Interval i : list){
             System.out.print("activitatea " + i.getIndex() + ": intervalul " + currentTime + " ");
             currentTime += i.getL();
             int delay = Math.max(0, currentTime - i.getT());
             if(delay > maxDelay)
                 maxDelay=delay;
             System.out.println(currentTime + " intarziere " + delay);
         }
         
         System.out.println("Intarziere planificare " + maxDelay);
    }
    
}
