package t2e3;

import java.io.File;
import java.io.PrintStream;
import java.util.Scanner;

public class T2E3 {

    public static void main(String[] args) throws Exception {
            AQueue<Integer> qi = new AQueue<>();
            qi.add(1);
            qi.add(3);
            qi.add(8);
            qi.remove();
            for(Integer i : qi){
                System.out.println(i);
            }
            
            AQueue<String> qs = new AQueue<>();
            qs.add("Ana");
            qs.add("are");
            qs.add("mere");
            qs.remove();
            for(String s : qs){
                System.out.println(s);
            }
            
            AQueue<AQueue<Integer>> qq = new AQueue<>();
            
            qq.add(qi);
            qq.add(qi);
            qq.remove();
            for(AQueue<Integer> q : qq){
                System.out.println(q);
            }
            
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
