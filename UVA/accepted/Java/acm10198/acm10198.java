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

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
       String st;
       BigInteger pr[] =new BigInteger[1005];
       pr[1]=new BigInteger("2");
       pr[2]=new BigInteger("5");
       pr[3]=new BigInteger("13");
       int i;
        for(i=4;i<1001;i++)
            pr[i]=(pr[i-3].add(pr[i-2])).add(pr[i-1].multiply(new BigInteger("2")));
       st=inp();
       while(st!=null)
       {
           i=Integer.valueOf(st);
           System.out.println(pr[i]);
           st=inp();
       }
    }

}