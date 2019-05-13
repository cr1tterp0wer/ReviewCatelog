
public class MCTree implements MCInterface{
	private MCNode root;
	private MCNode searchResult;
	
	public MCTree() {
		
		root = new MCNode();
		searchResult = new MCNode();
		makeMCtree();
	}
    
	private void makeMCtree() {
		
		char[] alphabet = { 'e', 't', 'i', 'a', 'n', 'm', 's', 'u', 'r', 'w', 
							'd', 'k', 'g', 'o', 'h', 'v', 'f', 'l', 'p', 
							'j', 'b', 'x', 'c', 'y', 'z', 'q' };

		for( int i = 0; i < alphabet.length; i++ ) {
			switch( alphabet[i] ) {
			  case 'e': 
				  root.setLeft( new MCNode( 'e' ) );
				  root.left.code = ".";
			  break;
			  case 't': 
				  root.setRight( new MCNode( 't' ) );
				  root.right.code = "-";
			  break;
			  case 'i': 
				  root.left.setLeft( new MCNode( 'i' ) );
				  root.left.left.code = "..";
			  break;
			  case 'a': 
				  root.left.setRight( new MCNode( 'a' ) );
				  root.left.right.code = ".-";
			  break;
			  case 'n': 
				  root.right.setLeft( new MCNode( 'n' ) );
				  root.right.left.code = "-.";
			  break;
			  case 'm': 
				  root.right.setRight( new MCNode( 'm' ) );
				  root.right.right.code = "--";
			  break;
			  case 's': 
				  root.left.left.setLeft( new MCNode( 's' ) );
				  root.left.left.left.code = "...";
			  break;
			  case 'u': 
				  root.left.left.setRight( new MCNode( 'u' ) );
				  root.left.left.right.code = "..-";
			  break;
			  case 'r': 
				  root.left.right.setLeft( new MCNode( 'r' ) );
				  root.left.right.left.code = ".-.";
			  break;
			  case 'w': 
				  root.left.right.setRight( new MCNode( 'w' ) );
				  root.left.right.right.code = ".--";
			  break;
			  case 'd': 
				  root.right.left.setLeft( new MCNode( 'd' ) );
				  root.right.left.left.code = "-..";
			  break;
			  case 'k': 
				  root.right.left.setRight( new MCNode( 'k' ) );
				  root.right.left.right.code = "-.-";
			  break;
			  case 'g': 
				  root.right.right.setLeft( new MCNode( 'g' ) );
				  root.right.right.left.code = "..-";
			  break;
			  case 'o': 
				  root.right.right.setRight( new MCNode( 'o' ) );
				  root.right.right.right.code = "---";
			  break;
			  case 'h': 
				  root.left.left.left.setLeft( new MCNode( 'h' ) );
				  root.left.left.left.left.code = "....";
			  break;
			  case 'v': 
				  root.left.left.left.setRight( new MCNode( 'v' ) );
				  root.left.left.left.right.code = "...-";
			  break;
			  case 'f': 
				  root.left.left.right.setLeft( new MCNode( 'f' ) );
				  root.left.left.right.left.code = "..-.";
			  break;
			  case 'l': 
				  root.left.right.left.setLeft( new MCNode( 'l' ) ); 
				  root.left.right.left.left.code = ".-..";
			  break;
			  case 'p': 
				  root.left.right.right.setLeft( new MCNode( 'p' ) );
				  root.left.right.right.left.code = ".--.";
			  break;
			  case 'j': 
				  root.left.right.right.setRight( new MCNode( 'j' ) );
				  root.left.right.right.right.code = ".---";
			  break;
			  case 'b': 
				  root.right.left.left.setLeft( new MCNode( 'b' ) );
				  root.right.left.left.left.code = "-...";
			  break;
			  case 'x':
				  root.right.left.left.setRight( new MCNode( 'x' ) );
				  root.right.left.left.right.code = "-..-";
			  break;
			  case 'c': 
				  root.right.left.right.setLeft( new MCNode( 'c' ) );
				  root.right.left.right.left.code = "-.-.";
			  break;
			  case 'y': 
				  root.right.left.right.setRight( new MCNode( 'y' ) );
				  root.right.left.right.right.code = "-.--";
			  break;
			  case 'z': 
				  root.right.right.left.setLeft( new MCNode( 'z' ) );
				  root.right.right.left.left.code = "--..";
			  break;
			  case 'q': 
				  root.right.right.left.setRight( new MCNode( 'q' ) );
				  root.right.right.left.right.code = "--.-";
			  break;
			  
			  default: break;
			}
		}
	}
	
	@Override
	public void Inordertraverse( MCNode node ) {
		
		if( node.left != null ) {
			Inordertraverse( node.left );
		}
		
		System.out.println(  node.getLetter() + " : " + node.code );
		
		if( node.right != null ) {
			Inordertraverse( node.right );
		}
	}

	@Override
	public void Preordertraverse( MCNode node ) {
		
		System.out.println(  node.getLetter() + " : " + node.code );
		
		if( node.left != null ) {
			Preordertraverse( node.left );
		}
		if( node.right != null ) {
			Preordertraverse( node.right );
		}
	}

	@Override
	public void Postordertraverse( MCNode node ) {
		
		if( node.left != null ) {
			Postordertraverse( node.left );
		}
		if( node.right != null ) {
			Postordertraverse( node.right );
		}
		System.out.println(  node.getLetter() + " : " + node.code );
	}

	public void searchPostOrder( MCNode root, char c ) {
		
		if( root.getLetter() == c )
			searchResult = root;
		
		if( root.getLetter() != c && root.left != null ) {
			searchPostOrder( root.left, c );
		}
		if( root.getLetter() != c && root.right != null ) {
			searchPostOrder( root.right, c );
		}
	}
	public void searchPostOrder( MCNode root, String s ) {
		
		if( root.code.equals(s) )
			searchResult = root;
		
		if( root.code != s && root.left != null ) {
			searchPostOrder( root.left, s );
		}
		if( root.code != s && root.right != null ) {
			searchPostOrder( root.right, s );
		}
		
	}
	public MCNode searchTree( char c ) { //searches the letter
		
		searchResult = new MCNode();
		searchPostOrder( root, c );
		return searchResult;
	}
	public MCNode searchTree( String s ) { //searches codes
		
		searchResult = new MCNode();
		searchPostOrder( root, s );
		return searchResult;
	}
	
	@Override
	public String encode( String s ) {
		String encoded = "";
		
		for( int i = 0; i < s.length(); i++) {
			encoded = encoded.concat( searchTree( s.charAt( i ) ).code + " " );
		}
		
		return encoded;
	}

	@Override
	public String decode( String message ) { 
		String decoded = "";
		
		String[] chunks = message.split( " " );
		
		for( int i = 0; i < chunks.length; i++) {
			decoded = decoded.concat( searchTree( chunks[i] ).getLetter() + " " );
		}
		
		return decoded;
	}

	public void traverseInOrder() {
		Inordertraverse( root );
	}
	public void traversePreOrder() {
		Preordertraverse( root );
	}
	public void traversePostOrder() {
		Postordertraverse( root );
	}
}
