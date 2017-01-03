
public class Interval implements Comparable<Interval> {
    int x, y;
    public Interval(int x, int y){
        this.x = x;
        this.y = y;
    }
    
    int getX(){
        return x;
    }
    
    int getY(){
        return y;
    }   

    @Override
    public int compareTo(Interval t) {
        if(x == t.y)
            return y - t.y;
        return x - t.x;
    }
}
