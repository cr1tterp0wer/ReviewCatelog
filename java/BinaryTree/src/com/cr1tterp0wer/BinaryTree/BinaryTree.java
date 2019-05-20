package com.cr1tterp0wer.BinaryTree;
import java.util.Scanner;

public class BinaryTree {

	public static void main(String[] args) {
	  
	  Scanner scan = new Scanner( System.in );
	  BTNode  root = new BTNode( "Elephant" );
	  BTNode  p    = root;
	  
	  boolean isPlaying = true;
	  boolean isOn      = true;
	  String animal;
	  
	  String playerAnimal;
	  String playerQuestion;
	  String playerAnswer;
	  
	  while( isOn ) {
		  System.out.println( "Welcome to ANIMAL GUESSER!" );
		  System.out.println( "Would you like to play? (y/n)" );
		  
		  playerAnswer = scan.nextLine();
		  if( playerAnswer.toLowerCase().equals("n") ) {
			  isOn      = false;
		      isPlaying = false;
		  }else
			  isPlaying = true;
		  
		  p = root;
		  
		  while( isPlaying ) {
			  
			  //check if current node 'p' is a leaf
			  if( p.isLeaf() ){
				  System.out.println( "The animal you're thinking of is a(n) " + p.getText() + "? y/n" );
				  playerAnswer = scan.nextLine();
				  
				  if( playerAnswer.toLowerCase().equals( "y" ) ) {
					  System.out.println( "HAHA, I WIN!" );
				  } else {
					  System.out.println( "What was your animal?" );
					  playerAnimal = scan.nextLine();
					  System.out.println( "Please enter a y/n question that differentiates your "
					  		            + " animal from my guess!" );
					  playerQuestion = scan.nextLine();
					  System.out.println( "Does your animal answer your question? y/n" );
					  playerAnswer   = scan.nextLine();
					  
					  animal = p.getText();
					  p.setText( playerQuestion );
					  
					  if( playerAnswer.toLowerCase().equals( "y" ) ) {
						  
						  BTNode yes = new BTNode( playerAnimal );
						  BTNode no  = new BTNode( animal );
						  
						  p.setNo( no );
						  p.setYes( yes );
					  }else {
						 
						  BTNode no = new BTNode( playerAnimal );
						  BTNode yes  = new BTNode( animal );
						  
						  p.setNo( no );
						  p.setYes( yes );
					  }
				  }
				  isPlaying = false;
			  } else {
				  System.out.println( p.getText() + " (y/n)" );
				  playerAnswer = scan.nextLine();
				  
				  if( playerAnswer.toLowerCase().equals( "y" ) ) {
					  p = p.getYes();
				  }else {
					  p = p.getNo();
				  }
			  }
			  
		   }
	  }
	}
}
