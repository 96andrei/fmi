package levenstein;

import java.io.File;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class Levenstein {
    
    static class LP{
        int value;
        int move;
        public LP(int a,int b){
            value = a;
            move = b;
        }
        
        @Override
        public boolean equals(Object t){
           return value == ((LP)t).value;
        }

        @Override
        public int hashCode() {
            int hash = 7;
            hash = 53 * hash + this.value;
            return hash;
        }
        
        @Override
        public String toString(){
            return Integer.toString(value);
        }
    }
    
    static LP min(int a, int b, int c, int c1, int c2, int c3){
        LP m = new LP(a + c1, 1);
        if(b + c2 <= a + c1 && b + c2 <= c+c3)
            m = new LP(b + c2, 2);
        if(c + c3 <= b + c2 &&  c+c3 <= a + c1)
            m = new LP(c + c3, 3);
        
        return m;
    }

    public static void main(String[] args) throws Exception{
        Scanner sc = new Scanner(new File("date.in"));
        
        String s1 = " " + sc.next();
        String s2 = " " + sc.next();
        
        int c1 = sc.nextInt();
        int c2 = sc.nextInt();
        int c3 = sc.nextInt();
        
        LP[][] d = new LP[s1.length()][s2.length()];
        
        d[0][0]= new LP(0,0);
        
        for(int i=1; i<s1.length(); i++){
            d[i][0] = new LP(d[i-1][0].value + c1, 1);
        }
        for(int i=1; i<s2.length(); i++){
            d[0][i] = new LP(d[0][i-1].value + c2, 2);
        }
        
        for(int i=1; i<s1.length(); i++)
            for(int j=1; j<s2.length(); j++){
                if(s1.charAt(i)== s2.charAt(j)){
                    d[i][j] = new LP(d[i-1][j-1].value, 6);
                    continue;
                }
                
                d[i][j] = min(d[i-1][j].value, 
                          d[i][j-1].value, 
                          d[i-1][j-1].value, 
                          c1,c2,c3);
            }
        
        for(int i=0; i<s1.length(); i++)
            System.out.println(Arrays.toString(d[i]));
        
        List<Integer> list = new ArrayList<>();
        List<Integer> listI = new ArrayList<>();
        List<Integer> listJ = new ArrayList<>();
        int i = s1.length()-1;
        int j = s2.length()-1;
        int move = d[i][j].move;
        
        while(move != 0){
            list.add(move);
            listI.add(i);
            listJ.add(j);
            if(move == 1)
                i--;
            if(move == 2)
                j--;
            if(move == 3 || move == 6){
                i--;
                j--;
            }
                
            move = d[i][j].move;
        }
        
        for(int k = list.size()-1; k>=0; k--){
            move = list.get(k);
            if(move == 1)
                System.out.println("stergem " + s1.charAt(listI.get(k)));
            if(move == 2)
                System.out.println("inseram " + s2.charAt(listJ.get(k)));
            if(move == 3)
                System.out.println("inlocuim " + s1.charAt(listI.get(k)) + "-" + s2.charAt(listJ.get(k)));
            if(move >= 4)
                System.out.println("pastram " + s2.charAt(listJ.get(k)));
        }
        //System.out.println(d[s1.length()-1][s2.length()-1].value);
    }
    
}
