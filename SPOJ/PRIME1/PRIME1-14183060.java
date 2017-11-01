import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.BitSet;
 
/**
 * Created by Surya Vamsi on 24-Mar-15.
 */
public class Main {
    static BitSet primes = new BitSet(31622);
 
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out, true);
        StringBuilder sb=new StringBuilder();
        primeset();
        int t = Integer.parseInt(in.readLine());
        while (t-- > 0) {
            String[] temp = in.readLine().split(" ");
            int m = Integer.parseInt(temp[0]);
            int n = Integer.parseInt(temp[1]);
            if (m == 1) m++;
            boolean[] reqset = new boolean[n - m + 1];
            for (int i = 0; i <= 31622; i++) {
                if (primes.get(i)) {
                    int p = m - m % i;
                    if (p < m) p += i;
                    if (p == i) p += i;
                    while (p <= n) {
                        reqset[p - m] = true;
                        p += i;
                    }
 
                }
            }
            for (int i = m; i <= n; i++) {
                if (reqset[i - m]) continue;
                else sb.append(i).append('\n');
            }
            sb.append('\n');
 
 
        }
        out.print(sb);
        out.close();
    }
 
    static void primeset() {
        for (int i = 2; i < 31622; i++) primes.set(i);
        for (int i = 2; i < 177; i++) {
            if (primes.get(i)) {
                for (int j = 2 * i; j <= 31622; j += i) {
                    primes.set(j, false);
                }
            }
        }
    }
}