import java.io.*;
import java.math.BigDecimal;
import java.util.Scanner;
import java.math.BigInteger;
public class Main {
     static   String str;

    static Scanner in = new Scanner(System.in);
    public static String inp()
    {
        try
        {
            str=in.next();
            return str;
        }
        catch (Exception e)
        {
            return null;
        }
    }


    public static void main(String args[])
    {
       BigDecimal a,b;
       long t,flag;
       int i,j;
       str=inp();
       t=Long.valueOf(str);
       while(t-->0)
       {
          str=inp();
          a=new BigDecimal(str);

          str=inp();
          b=new BigDecimal(str);
          a=a.add(b);
          str=a.toString();
          flag=0;
          
	      for(i=0;i<str.length();i++)
	      {
	        if(str.charAt(i)=='.')
	        {
	            flag=1;
	            break;
	        }
	      }          
          
          if(flag==1)
          {
	          for(i=0;i<str.length();i++)
	          {
	          	System.out.print(str.charAt(i));
	          	  if(str.charAt(i)=='.')
	              {
	                  flag=1;
	                  break;
	              }
	          }
	          for(j=str.length()-1;j>=0;j--)
	          	if(str.charAt(j)!='0')
	          		break;
	          if(str.charAt(j)=='.')
	          	flag=0;
	          for(i=i+1;i<=j;i++)
	          	System.out.print(str.charAt(i));
	          if(flag==1)
	          System.out.println();
	          else
	          	System.out.println("0");
          }
          else
              System.out.println(a+".0");
        }
    }
}
