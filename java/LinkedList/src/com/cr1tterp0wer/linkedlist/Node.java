package com.cr1tterp0wer.linkedlist;

public class Node<T> {

	private T d;
	
	private Node next;
	
	public Node( T p ) {
		d =  p;
	}
	public void setNext( Node n ) {
		next = n;
	}
	public Node getNext() {
		return next;
	}
	public T getData() {
		return d;
	}
}
