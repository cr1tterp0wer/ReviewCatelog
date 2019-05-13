
public class MCNode {

	private char letter;
	public MCNode right;
	public MCNode left;
	public String code;
	
	public MCNode() {
	  left   = null;
	  right  = null;
	  code   = "";
	}
	
	public MCNode( char c ) {
		letter = c;
		left   = null;
		right  = null;
		code   = "";
	}
	
	public MCNode( char c, String s ) {
		letter = c;
		left   = null;
		right  = null;
		code   = s;
	}
	
	public MCNode( char c, MCNode l, MCNode r ) {
		letter = c;
		left   = l;
		right  = r;
	}
	
	public void setRight( MCNode r ) {
		right = r;
	}
	
	public void setLeft( MCNode l ) {
		left = l;
	}
	public char getLetter() {
		return letter;
	}
	
}