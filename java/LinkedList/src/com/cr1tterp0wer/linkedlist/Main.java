package com.cr1tterp0wer.linkedlist;

import java.util.ArrayList;

public class Main {
	
	public static void printPerson( Person p ) {
		if( p == null )
			return;
		
		System.out.println( "Name: " + p.name + " Age: " + 
				p.age + " Address: " + 
				p.address + " Sex: " + 
				p.sex + " Height: " + 
				p.height + " " );
	}
	public static <T> void main(String[] args) {
      
       Person p1 = new Person("Critter", "80 Dorado Terrace",
    		   'm', 18, "(619)786-0010", 6.1f );
       LinkedList<Person> list = new LinkedList( p1 );
       list.add( "Tetka", "186 Brewster st.", 'f', 29,"7415269", 5.8f  );
       list.add( "Doc Brown", "186 Brewster st.", 'f', 29,"7415269", 5.8f  );
       list.add( "Jaymie Lanister", "186 Brewster st.", 'f', 29,"7415269", 5.8f  );
       list.add( "Hodor", "186 Brewster st.", 'f', 29,"7415269", 5.8f  );
       
       
       list.removeAt( -1 );
       
       list.printAll();
       System.out.println();
       printPerson( list.getAt( 0 ) );
       
       LinkedList<Integer> list2 = new LinkedList( 2 );
       LinkedList<String> list3 = new LinkedList( "Tijana is amazing!" );
       list3.add("Critter is a great name!" );
       
       
	}
}


