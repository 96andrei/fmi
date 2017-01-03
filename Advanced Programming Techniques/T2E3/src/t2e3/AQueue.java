/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package t2e3;

import java.util.Iterator;
import java.util.NoSuchElementException;

class AQueue<E> implements Iterable<E>{

    @Override
    public Iterator<E> iterator() {
        return new AQueueIterator<>(); 
    }
    
    public class AQueueIterator<E> implements Iterator<E>{
        
        int position = 0;
        
        @Override
        public boolean hasNext() {
            return position < qsize;
        }

        @Override
        public E next() {
            if(hasNext()){
                E element = (E) elementAt(position);
                position++;
                return element;
            }
            throw new NoSuchElementException();
        }
    
    }
	
	public class Node<E>{
	E info;
	Node next;
	
	public Node(){
		
	}
	
	public Node(E info){
		setInfo(info);
	}
	
	public Node(E info, Node next){
		setInfo(info);
		setNext(next);
	}
	
	public Node getNext(){
		return next;
	}
	
	public void setNext(Node next){
		this.next = next;
	}
	
        @Override
	public String toString(){
		return info.toString();
	}
	
	public E getInfo(){
		return info;
	}
	
	public void setInfo(E info){
		this.info = info;
	}
    }
	
	Node first;
	
        int qsize;
        
	//ctor
	public AQueue(){
		first = null;
                qsize = 0;
	}
	
	public void add(E info){
                qsize++;
            
		if(first == null){
			first = new Node(info);
			return;
		}
		
		Node newNode = new Node(info);
		
		Node current = first;
		
		while(current.getNext() != null){
			current = current.getNext();
		}
		
		current.setNext(newNode);
		
	}
	
	public E remove(){
                if(qsize > 0)
                    qsize--;
		E i = (E) first.getInfo();
		first = first.getNext();
		return i;
	}
	
	public E element(){
		return (E) first.getInfo();
	}
	
	public E elementAt(int i){
		Node current = first;
		while(i!=0){
			current = current.getNext();
			i--;
		}
		return (E) current.getInfo();
	}
	
	public String toString(){
		return first.toString();
	}
        
        public int size(){
            return qsize;
        }
	
}
