import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.List;
 
class Factorial {
	public static void main(String[] args) throws IOException {
		Factorial fac = new Factorial();
		fac.run();
	}
 
	private BigInteger factorial(BigInteger n) {
		if(n.intValue() <=1){
			return n;
		}
		return n.multiply( factorial(n.subtract(new BigInteger(1+""))));
	}
	
	private void run() throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String line = null;
		int lineCount = 0;
		int maxLines = 0;
		List<BigInteger> resList = new ArrayList<BigInteger>();
		
		while( (line=br.readLine())!=null){
			lineCount++;
			if(lineCount==1){
				maxLines = Integer.parseInt(line);
				continue;
			}
			
			resList.add(factorial(new BigInteger(line)));
			
			if( lineCount > maxLines){
				break;
			}
		}
		
		for (BigInteger integer : resList) {
			System.out.println(integer);
		}
	}
 
}