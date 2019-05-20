package com.cr1tterp0wer.BinaryTree;

public class BTNode {

	private String text;  //DATA
	public  BTNode no;  // Left node
	public  BTNode yes; // Right node
	
	public BTNode() {
		text  = "";
		no    = null;
		yes   = null;
	}
	public BTNode( String name ) {
		text = name;
		no    = null;
		yes   = null;
	}
	
	public boolean isLeaf() {
		return ( no == null && yes == null );
	}
	
	public BTNode getNo() {
		return no;
	}
	public BTNode getYes() {
	    return yes;
	}
	public void setNo( BTNode n ) {
		no = n;
	}
	public void setYes( BTNode y ) {
		yes = y;
	}
	public String getText() {
		return text;
	}
	public void setText( String name ) {
		this.text = name;
	}
}
