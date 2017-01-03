/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package t2e3;

public class Graf {
    
    AQueue<Integer> list[];
    
    public Graf(int n){
        list = new AQueue[n+1];
        for(int i=1; i<=n; i++)
            list[i]=new AQueue<>();
    }
    
    public void add(int n, int to){
        list[n].add(to);
    }
    
    public String getLists(){
        String lists = "";
        
        
        
        
        for(int i=1; i<list.length; i++){
            lists += (i + ": ");
            /*for(int j=0; j<list[i].getSize(); j++){
                lists += (list[i].elementAt(j) + " ");  
            }*/
            for(Integer element : list[i]){
                lists += element + " ";
            }
            
            lists += "\n";
        }
        
        return lists;
    }
    
    public String getBreadth(int start){
        String result = "";
        
        AQueue<Integer> q = new AQueue();
        int visited[] = new int[list.length];
        
        
        q.add(start);
        visited[start] = 1;
        
        while(q.size() > 0){
            int next = q.element();

            /*for(int i=0; i<list[next].getSize(); i++){
                int x = list[next].elementAt(i);
                if(visited[x] == 0){
                    q.add(x);
                    visited[x] = 1;
                }
            }*/
            
            for(Integer x : list[next]){
                if(visited[x] == 0){
                    q.add(x);
                    visited[x] = 1;
                }
            }
            
            next = q.remove();
            result += next + " ";
        }
        
        return result;
    }
    
}
