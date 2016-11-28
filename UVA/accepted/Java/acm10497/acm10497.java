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
            st=in.next();
            return st;
        }
        catch (Exception e)
        {
            return null;
        }
    }
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        BigInteger fn[]=new BigInteger[900],sum;
        int i,d=1,n;
        fn[0]=new BigInteger("0");
        fn[1]=new BigInteger("0");
        fn[2]=new BigInteger("1");
        fn[3]=new BigInteger("2");
        d=1;
        for(i=4;i<801;i++,d*=-1)
            fn[i]=fn[i-1].multiply(new BigInteger(String.valueOf(i))).add(new BigInteger(String.valueOf(d)));

        st=inp();

        while(st!=null)
        {
            n=Integer.valueOf(st);
            if(n<0)
                break;

            System.out.println(fn[n]);
            st=inp();
        }
    }

}
