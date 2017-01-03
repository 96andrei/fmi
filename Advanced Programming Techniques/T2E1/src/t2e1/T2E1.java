package t2e1;

import java.io.File;
import static java.lang.Math.sqrt;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
import javafx.util.Pair;

public class T2E1 {
    
    public static void main(String[] args) throws Exception{
        
        Scanner sc = new Scanner(new File("f1.txt"));
        sc.useDelimiter("[ ,.]+");
        
        HashMap<String, Pair<Integer, Integer>> v = new HashMap<>();
        
        while(sc.hasNext()){
            String s = sc.next();
            if(!v.containsKey(s)){
                v.put(s, new Pair<>(1,0));
            }else{
                int size = v.get(s).getKey();
                Pair<Integer, Integer> p = new Pair(size + 1, v.get(s).getValue());
                v.put(s,p );
            }
        }
        sc.close();
        
        sc = new Scanner(new File("f2.txt"));
        sc.useDelimiter("[ ,.]+");
        
        while(sc.hasNext()){
            String s = sc.next();
            if(!v.containsKey(s)){
               v.put(s, new Pair<>(0,1));
            }else{
                int size = v.get(s).getValue();
                Pair<Integer, Integer> p = new Pair(v.get(s).getKey(), size + 1);
                v.put(s, p);
            }
        }
        sc.close();
        
        float productSum = 0;
        float sqrV1 = 0;
        float sqrV2 = 0;
        
        //v.entrySet().forEach((Map.Entry<String, Pair<Integer, Integer>> entry) -> {
        for(Map.Entry<String, Pair<Integer,Integer>> entry : v.entrySet()){
            //System.out.println(entry.getKey() + " " + entry.getValue());
            int v1 = entry.getValue().getKey();
            int v2 = entry.getValue().getValue();
            productSum += v1 * v2;
            sqrV1 += v1 * v1;
            sqrV2 += v2 * v2;
        }
        
        
        float result = (float) (productSum / (sqrt(sqrV1) * sqrt(sqrV2)));
        
        System.out.println(result);
        
    }
    
}
