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
        BigInteger fn[]=new BigInteger[300],tw=new BigInteger("2");
        int i;
        fn[0]=new BigInteger("1");
        fn[1]=new BigInteger("1");
        for(i=2;i<251;i++)
            fn[i]=fn[i-1].add(tw.multiply(fn[i-2]));

        st=inp();
        while(st!=null)
        {
            System.out.println(fn[Integer.valueOf(st)]);
            st=inp();
        }
    }
}