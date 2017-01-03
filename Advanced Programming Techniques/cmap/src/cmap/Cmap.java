package cmap;

import java.io.File;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Cmap {

    public static class Vector2 implements Comparable<Vector2> {

        long x, y;

        public Vector2(int x, int y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public int compareTo(Vector2 t) {
            if (x == t.x) {
                return (int) (y - t.y);
            }
            return (int) (x - t.x);
        }

        public long sqrDistance(Vector2 t) {
            long x = this.x - t.x;
            x *= x;
            long y = this.y - t.y;
            y *= y;

            return x + y;
        }

        public double distanceTo(Vector2 t) {
            return Math.sqrt(sqrDistance(t));
        }

        @Override
        public String toString() {
            String s = "";
            s += x + "," + y;
            return s;
        }
    }

    static class MinimalPoint implements Comparable<MinimalPoint> {

        double distance;
        Vector2 p1, p2;

        public MinimalPoint(Vector2 p1, Vector2 p2, double distance) {
            this.p1 = p1;
            this.p2 = p2;
            this.distance = distance;
        }

        @Override
        public int compareTo(MinimalPoint t) {
            if (distance > t.distance) {
                return 1;
            } else if (distance == t.distance) {
                return 0;
            }
            return -1;
        }

        @Override
        public String toString() {
            String s = "";
            s += "[" + p1 + "|" + p2 + "] " + distance;
            return s;
        }
    }

    static MinimalPoint divide(List<Vector2> list) {
        if (list.size() <= 3) {                                                 
            double s = Double.MAX_VALUE;
            MinimalPoint result = new MinimalPoint(null, null, 0);
            //
            for (final Vector2 v1 : list) {                                     //caz (aproape) banal / caz final
                for (final Vector2 v2 : list) {                                 //O(3*3) => O(1)
                    if (v1 == v2) //
                    {
                        continue;                                               
                    }                                                             
                    double d = v1.sqrDistance(v2);
                    if (d < s) {
                        result = new MinimalPoint(v1, v2, d);
                    }
                }                                                               
            }
            result.distance = Math.sqrt(result.distance);
            return result;                                                
        }

        int vX = list.size() / 2;                                               //divide O(1)

        MinimalPoint s1 = divide(list.subList(0, vX));                          //apel recursiv 1
        MinimalPoint s2 = divide(list.subList(vX, list.size()));                //apel recursiv 2

        MinimalPoint s = s1.compareTo(s2) == -1 ? s1 : s2;                      

        double mid = list.size() % 2 != 0 ? list.get(vX).x
                : (list.get(vX).x + list.get(vX + 1).x) / 2;
        
        List<Vector2> l1 = new ArrayList<>();
        List<Vector2> l2 = new ArrayList<>();
        
        for(int i=0; i<vX; i++){
            if(Math.abs(list.get(i).x - mid) <= s.distance)
                l1.add(list.get(i));
        }
        
        for(int i=vX; i<list.size(); i++){
            if(Math.abs(list.get(i).x - mid) <= s.distance)
                l2.add(list.get(i));
        }
        
        List<Vector2> Y = merge(l1,l2);

        for (int i = 0; i < Y.size(); i++) {                                    
            for (int j = i + 1; j < Math.min(Y.size(), i + 8); j++) {              
                double d = Y.get(i).distanceTo(Y.get(j));                       //total combinare O(8n)
                if (d < s.distance)
                {
                    s = new MinimalPoint(Y.get(i), Y.get(j), d);                
                }
            }                                                                   
        }

        return s;
    }

    static List<Vector2> merge(List<Vector2> a, List<Vector2> b) {
        List<Vector2> answer = new ArrayList<>();
        int i = 0, j = 0;
        while (i < a.size() && j < b.size()) {
            if (a.get(i).y < b.get(j).y) {
                answer.add(a.get(i));
                i++;
            } else {
                answer.add(b.get(j));
                j++;
            }
        }

        while (i < a.size()) {
            answer.add(a.get(i));
            i++;
        }

        while (j < b.size()) {
            answer.add(b.get(j));
            j++;
        }

        return answer;
    }

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(new File("cmap.in"));

        int n = sc.nextInt();

        ArrayList<Vector2> list = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            int x = sc.nextInt();
            int y = sc.nextInt();
            list.add(new Vector2(x, y));
        }

        list.sort(null);

        System.out.println(divide(list));
    }

}
