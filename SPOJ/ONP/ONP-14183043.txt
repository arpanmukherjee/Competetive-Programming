import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.util.Stack;
 
public class Main{
    public static void main(String args[]) throws Exception{
        int t;
		String str;
		int len = 0;
		Stack stack = new Stack();
		char temp[] = new char[401];
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		t = Integer.parseInt(br.readLine());		
			for(int i=0; i<t; i++){
				str = br.readLine();
				temp = str.toCharArray();
				len = temp.length;
				for(int j=0; j<len; j++){
					if(temp[j] > 96 && temp[j] <=122)
						System.out.print(temp[j]);
					else if(temp[j] == ')')
						System.out.print(stack.pop());
					else if(temp[j] != '(')
						stack.push(temp[j]);
				}
				System.out.println("");
			}
    }	
}