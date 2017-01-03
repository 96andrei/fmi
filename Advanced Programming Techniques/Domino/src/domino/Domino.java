package domino;

import java.io.File;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Scanner;

public class Domino {
            
    public static class DP{
        int left, right;
        int index;
        
        public DP(int left, int right, int index){
            this.left = left;
            this.right = right;
            this.index = index;
        }
        
        @Override
        public String toString(){
            String s = "";
            s += left + " " + right;
            return s;
        } 
        
    }
            
    public static void main(String[] args) throws Exception{
        HashMap<Integer, DP> hm = new HashMap<>();
        List<DP> list = new ArrayList<>();
        int[] count;
        
        Scanner sc = new Scanner(new File("date.in"));
        int n = sc.nextInt();
        count = new int[n];
        
        for(int i=0; i<n; i++){
            list.add(new DP(sc.nextInt(), sc.nextInt(), i));
        }
        
        for(int i=0; i<n; i++){
            DP dp = list.get(i);
            int value = 0;
            if(hm.containsKey(dp.left)){
                value = count[hm.get(dp.left).index] + 1;
            }
            count[i] = value;
            
            if(hm.containsKey(dp.right)){
                if(count[hm.get(dp.right).index] < value)
                    hm.put(dp.right, dp);
            }else
                hm.put(dp.right, dp);
        }
        
        //System.out.println(Arrays.toString(freq));
        
        int max = 0;
        for(int i=0; i<n; i++)
            if(count[max] < count[i])
                max = i;
        
        DP current = list.get(max);
        List<DP> result = new ArrayList<>();
        while(current != null){
            result.add(current);
            current = hm.get(current.left);
        }
        
        for(int i=result.size()-1; i>=0; i--){
            System.out.println(result.get(i));
        }
        
        int maxCount = 0;
        for(int i=0; i<n; i++)
            if(count[i]==count[max])
                maxCount++;
        System.out.println(maxCount);
    }
        
}
