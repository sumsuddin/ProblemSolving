import java.io.*;
import java.lang.*;
import java.util.Scanner;
import java.math.BigInteger;
public class Main {
     static   String st;

    static Scanner in = new Scanner(System.in);
    public static String inp()
    {
        try
        {
            st=in.nextLine();
            return st;
        }
        catch (Exception e)
        {
            return null;
        }
    }


    public static void main(String args[])
    {
        String st;
       BigInteger ct[] =new BigInteger[305],fac[]=new BigInteger[305];
       int i,n;

	ct[0]=fac[0]=ct[1]=new BigInteger("1");
	for(i=1;i<301;i++)
        {
            fac[i] = fac[i - 1].multiply(new BigInteger(String.valueOf(i)));
              ct[i+1] = (ct[i].multiply(new BigInteger(String.valueOf((2 * (2 * i + 1)))))).divide(new BigInteger(String.valueOf((i + 2))));
        }
       st=inp();
       while(st!=null)
        {
          n=Integer.valueOf(st);

          System.out.println(ct[n].multiply(fac[n]));
          st=inp();
          if(st.equals("0"))
              break;
        }
    }
}
