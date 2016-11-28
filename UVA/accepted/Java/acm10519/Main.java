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
       BigInteger a,b,c,gcd,x,y;
       str=inp();
       while(str!=null)
        {
           if(str.equals("0"))
               System.out.println("1");
           else
           {
               if (str .equals("1"))
                   System.out.println("2");
               else
               {

                    a=new BigInteger(str);
                    b=a.multiply(a);
                    a=b.subtract(a);
                    a=a.add(new BigInteger("2"));
                    System.out.println(a);
               }
            }
                    
           
          str=inp();
        }
    }
}
