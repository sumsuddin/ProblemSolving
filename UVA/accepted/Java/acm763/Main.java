/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author SHOJIB
 */
import java.io.*;
import java.math.BigInteger;
import java.util.Scanner;
public class Main {

    static int i,j;
    static String str;
    static boolean bu[]=new boolean[250],flag=false;
    static BigInteger ans,fibo[]=new BigInteger[250];

    /**
     * @param args the command line arguments
     */

    static Scanner in=new Scanner(System.in);

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

    public static void main(String[] args) {
        // TODO code application logic here
        fibo[0]=new BigInteger("1");
        fibo[1]=new BigInteger("2");
        for(i=2;i<205;i++)
            fibo[i]=fibo[i-1].add(fibo[i-2]);

        str=inp();
        while(str!=null)
        {
            
            ans=new BigInteger("0");
            
            for(i=0,j=str.length()-1;i<str.length();i++,j--)
                if(str.charAt(i)=='1')
                    ans=ans.add(fibo[j]);
            str=inp();
            for(i=0,j=str.length()-1;i<str.length();i++,j--)
                if(str.charAt(i)=='1')
                    ans=ans.add(fibo[j]);


            for(i=200;i>=0;i--)
            {
                bu[i]=false;
                if(ans.compareTo(fibo[i])>=0)
                {
                    ans=ans.subtract(fibo[i]);
                    bu[i]=true;
                }
            }
            i=200;
            while(i>=0 && bu[i]==false)
                i--;
            
            if(flag)
                System.out.println();
            else
                flag=true;

            str="";
            if(i==-1)
                System.out.println("0");
            else
            {
                while(i>=0)
                {
                    if(bu[i]==true)
                        str+='1';
                    else
                        str+='0'; 
                    i--;
                }
                System.out.println(str);
            }
            str=inp();
        }
    }

}
