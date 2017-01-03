package planminmax;

public class Interval implements Comparable<Interval> {
    int l, t, index;
    
    public Interval(int index, int x, int y){
        this.l = x;
        this.t = y;
        this.index = index;
    }
    
    public int getL(){
        return l;
    }
    
    public int getT(){
        return t;
    }  
    
    public int getIndex(){
        return index;
    }

    @Override
    public int compareTo(Interval other) {
        if(t == other.t)
            return other.l - l;
        return t - other.t;
    }
}
