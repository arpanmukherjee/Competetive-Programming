import java.io.*;
import java.util.*;

class BIT
{
    long[] bit = new long[10000007];

    long query(int idx)
    {
        long sum = 0;
        int i=idx;
        while(i>0)
        {
            sum += bit[i];
            i-=(i & (-i));
        }
        return sum;
    }
    void update(int idx, int val)
    {
    	int i=idx;
        while(i<10000007)
        {
            bit[i] += val;
            i+=(i&(-i));
        }
    }
}

class TestClass
{

    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int t,n;
        int[] a = new int[200003];
        t = sc.nextInt();
        while(t-->0)
        {
        	n = sc.nextInt();
            BIT foo = new BIT();
            for(int i = 0; i < n; i++)
                a[i] = sc.nextInt();
            long ans = 0;
            for(int i = 0; i < n; i++)
            {
                ans += i-foo.query(a[i]);
                foo.update(a[i],1);
            }
            System.out.println(ans);
        }
    }
}
