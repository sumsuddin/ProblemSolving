
import java.math.BigInteger;
import java.util.Scanner;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Shojib
 */
public class Main {
  
    static String str;
    
    static BigInteger  powr(BigInteger bs,int p)
    {
        if(p==0)
            return new BigInteger("1");
        BigInteger x=powr(bs,(int)(p>>1));
        x=x.multiply(x);
        if((p&1)==1)
            x=x.multiply(bs);
  //      System.out.println(p+" is for "+x);
        return x;
    }
    static Scanner in =new Scanner(System.in);
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
        String now;
        str=inp();
        BigInteger ans=new BigInteger("0"),ml,mm=new BigInteger("26");
        while(str.equals("*")==false)
        {
            ans=new BigInteger("0");
            now=str;
            if(now.charAt(0)<='9')
            {
                String pp="";
                BigInteger dd,ddd;
                ans=new BigInteger(now);
                for(int i=23;i>=0;i--)
                {
                    int j;
                    
                    dd=powr(mm, i);
                    ml=dd.divide(mm);
                    ddd=dd.multiply(mm);
                    for(j=26;j>=1;j--)
                    {
                        if(ddd.compareTo(ans)<=0 && ml.compareTo(ans.subtract(ddd))<=0)
                        {
                            pp+=(char)('a'+j-1);
            //                System.out.println(i+" "+ddd+" "+j+" "+dd+" "+ans.subtract(ddd)+" "+ml);
                            ans=ans.subtract(ddd);
                            break;
                        }                        
                        ddd=ddd.subtract(dd);
                    }
                }
                System.out.printf("%-22s",pp);
            }
            else
            {
                int j=0;
                for(int i=now.length()-1;i>=0;i--)
                {
                    String ss= String.valueOf(now.charAt(i)-'a'+1);
                    ml=powr(mm,j);
     //               System.out.println(ml+" "+ss);
                    
                    ml=ml.multiply(new BigInteger(ss));
    //                System.out.println("mul "+ml);
                    ans=ans.add(ml);
                    j++;
                }
                System.out.printf("%-22s",now);
                now=ans.toString();

            }
                int d=now.length()%3;
                for(int i=0;i<d;i++)
                    System.out.printf("%c",now.charAt(i));
                if(d>0 && now.length()!=d)
                    System.out.printf(",");
                int jp=0;
                for(int i=d;i<now.length();i++,jp++)
                {
                    if(jp==3)
                    {
                        System.out.printf(",");
                        jp=0;
                    }
                    System.out.printf("%c",now.charAt(i));
                }
                System.out.printf("\n");            
            str=inp();
        }
    }
}
