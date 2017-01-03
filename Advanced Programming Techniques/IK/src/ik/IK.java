package ik;

import java.io.File;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Scanner;

public class IK {

    public static class EL{
        int value;
        int from;
        int startValue;
        public EL(int v, int f, int s){
            value = v;
            from = f;
            startValue = s;
        }
        
        @Override
        public String toString(){
            return Integer.toString(value);
        }
    }
    
    public static void main(String[] args) throws Exception{
        Scanner sc = new Scanner(new File("date.in"));
        
        int n = sc.nextInt();
        int k = sc.nextInt();
        
        List<Integer>[] list = new List[n];
        for(int i=0; i<n; i++)
            list[i] = new ArrayList<>();
        
        for(int i=0; i<n; i++){
            String l = sc.nextLine();
            String[] ar = l.split("[ ]+");
            //System.out.println(l);
            for(String s : ar){
                if(s.isEmpty()){
                    i--;
                    continue;
                }
                list[i].add(Integer.parseInt(s));
            }
        }
        
        HashMap<Integer, EL> current[] = new HashMap[n];
        current[0] = new HashMap<>();
        list[0].forEach((i) -> {
            current[0].put(i, new EL(i,-1, i));
        });
        
        //i - linie
        for(int i=1; i<n; i++){
           current[i] = new HashMap<>();
           for(int j : list[i]){
               for(int t : current[i-1].keySet()){
                   int val = j + t;
                   //int val = j + current[i-1].get(t).value;
                   //System.out.println(t + " " + current[i-1].get(t).value);
                   if(val <= k && !current[i].containsKey(val))
                        current[i].put(val, new EL(val, t, j));
               }
           }
        }
        
        int target = -1;
        for(int i : current[n-1].keySet())
            if(i == k)
                target = i;
        
        if(target == -1){
            System.out.println(0);
            return;
        }
        
        for(int i=n-1; i>=0; i--){
            System.out.print(current[i].get(target).startValue + " ");
            target = current[i].get(target).from;
        }
        //System.out.println(current[n-1]);
        
    }
    
}
