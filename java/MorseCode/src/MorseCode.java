public class MorseCode {

	public static void main( String[] args ) {
		
		MCTree tree = new MCTree();
		String msg = tree.decode( "..- -.- ---" );
		System.out.println( msg );
	}
}
