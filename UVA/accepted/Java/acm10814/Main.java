import java.io.*;
import java.util.Scanner;
import java.math.BigInteger;
public class Main {
     static   String str;

    static Scanner in = new Scanner(System.in);
    public static String inp()
    {
        try
        {
            str=in.nextLine();
            return str;
        }
        catch (Exception e)
        {
            return null;
        }
    }


    public static void main(String args[])
    {
        str=inp();
        long n=Long.valueOf(str);

       BigInteger a,b,c,gcd,x,y;
        while(n-->0)
        {
            str=in.next();
            a=new BigInteger(str);
            in.next();
            str=in.next();
            b=new BigInteger(str);
            gcd=new BigInteger("1");
            x=a;y=b;
            while(true)
            {
                c=b.mod(a);
                if(c.equals(new BigInteger("0")))
                {
                    gcd=a;
                    break;
                }

                b=a;
                a=c;
            }
            System.out.println(x.divide(gcd)+" / "+y.divide(gcd));
        }
    }
}
