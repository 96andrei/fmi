package partinterval;

public class Interval implements Comparable<Interval>{
    
    int s, f;
    int index;
    
    public Interval(int index, int s, int f){
        this.index = index;
        this.s = s;
        this.f = f;
    }
    
    public int getS(){
        return s;
    }
    
    public int getF(){
        return f;
    }
    
    public int getIndex(){
        return index;
    }
    
    @Override
    public int compareTo(Interval t) {
        return s - t.s;
    }
    
}
