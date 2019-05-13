package com.cr1tterp0wer.linkedlist;

public class LinkedList<T> {

	Node head;
	Node current;
	private int size;
	
	public LinkedList( T p ) {
	
		head = new Node( p );
		current = null;
		size = 0;
	}
	
	public void add( T p ) {
		
		Node node = new Node( p );
		current = head;
		
		while( current != null ) {
		
			if( current.getNext() == null ) {
				current.setNext( node );
				size++;
				break;
			}
			
			current = current.getNext();
		}
		current = null;
	}
	
	public void add( String n, String addr, char s, int a, String p, float h ) {
		 add( (T) new Person( n, addr, s, a, p, h) );
	}
	
	public void removeAt( int i ) {
		
		if( i > size || i < 0 )
			return;
		
		current = head;
		if( i == 0 )
			head = head.getNext();
		
		for( int k = 0; k < i-1; k++ ) {
			current = current.getNext();
		}
		
		current.setNext( current.getNext().getNext() ); //remove the thing
		size--;
	}
	
	public T getAt( int i ) {
		if( i > size || i < 0 )
			return null;
		
		current = head;
		if( i == 0 )
			head = head.getNext();
		
		for( int k = 0; k < i; k++ ) {
			current = current.getNext();
		}
		
		return (T) current.getData();
	}
	
	public void printAll() {
		current = head;
		while( current != null ) {
			System.out.println( current.getData() );
			current = current.getNext();
		}
		current = null;
	}
}