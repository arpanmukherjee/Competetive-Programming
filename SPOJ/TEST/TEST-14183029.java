import java.util.Scanner;
 
public class Main{
 
	public static void main(String[] args) {
		Scanner S = new Scanner(System.in);
 
		int Num = 0;
 
		while (true) {
			Num = S.nextInt();
			if (Num != 42) {
				System.out.println(Num);
			} else {
				System.exit(0);
			}
		}
 
	}
 
} 