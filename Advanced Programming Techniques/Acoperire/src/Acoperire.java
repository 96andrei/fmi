import java.io.File;
import java.util.ArrayList;
import java.util.Scanner;

public class Acoperire {

    public static void main(String[] args) throws Exception {
        
        Scanner sc = new Scanner(new File("date.in"));
        
        int x,y;
        x = sc.nextInt();
        y = sc.nextInt();
        
        Interval target = new Interval(x,y);
        
        int n;
        n = sc.nextInt();
        
        ArrayList<Interval> list = new ArrayList<>();
        for(int i=0; i<n; i++){
            x = sc.nextInt();
            y = sc.nextInt();
            Interval in = new Interval(x,y);
            list.add(in);
        }
        
        list.sort(null);
        
        ArrayList<Interval> sol = new ArrayList<>();
        
        int t = target.getX();
        
        int i=0;
        boolean left = false;
        boolean right = false;
        
        while(i<list.size() && (!left || !right)){
            Interval current = list.get(i);
            int max = i;
            boolean step = false;
            while(current.getX() <= t && i<list.size()){
                step = true;
                if(current.getY() > list.get(max).getY())
                    max = i;
                i++;
                if(i<list.size())
                    current = list.get(i);
            }
            
            if(!step)
                break;
            
            if(list.get(max).getX() <= target.getX())
                left = true;
            if(list.get(max).getY() >= target.getY())
                right = true;
            sol.add(list.get(max));
            t=list.get(max).getY();
        }
        
        
        if(left && right)
            for(i=0; i < sol.size(); i++)
                System.out.println(sol.get(i).x + " " + sol.get(i).y);
        else
            System.out.println(-1);
        
    }
    
}
