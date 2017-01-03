import java.util.Scanner;

//add, remove, element
class AQueue{
	
	public class Node{
	int info;
	Node next;
	
	public Node(){
		
	}
	
	public Node(int info){
		setInfo(info);
	}
	
	public Node(int info, Node next){
		setInfo(info);
		setNext(next);
	}
	
	public Node getNext(){
		return next;
	}
	
	public void setNext(Node next){
		this.next = next;
	}
	
	public String toString(){
		return Integer.toString(info);
	}
	
	public int getInfo(){
		return info;
	}
	
	public void setInfo(int info){
		this.info = info;
	}
}
	
	Node first;
	
	//ctor
	public AQueue(){
		first = null;
	}
	
	public void add(int info){
		if(first == null){
			first = new Node(info);
			return;
		}
		
		Node newNode = new Node(info);
		
		Node current = frist;
		
		while(current.getNext != null){
			current = current.getNext();
		}
		
		current.setNext(newNode);
		
	}
	
	public int remove(){
		int i = first.getInfo();
		first = first.getNext();
		return i;
	}
	
	public int element(){
		return first.getInfo();
	}
	
	public int elementAt(int i){
		Node current = first;
		while(i!=0){
			current = first.getNext();
			i--;
		}
		return current.getInfo();
	}
	
	public String toString(){
		return first.toString();
	}
	
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		
		int n;
		
		n = sc.nextInt();
		
		AQueue q = new AQueue();
		
		for(int i=0; i<n; i++){
			q.add(sc.nextInt());
		}
		
		System.out.println(q.toString());
		System.out.println(q.element());
		System.out.println(q.elementAt(n-1));
		System.out.println(q.remove());
		System.out.println(q.element());
		
	}
	
}