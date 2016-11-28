/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author SHOJIB
 */
import java.io.*;
import java.util.Scanner;
import java.math.BigInteger;
public class Main {
     static   String str;
     static BigInteger dp[]=new BigInteger[1050],one=new BigInteger("1");
     static BigInteger two=new BigInteger("2"),three=new BigInteger("3");

    static Scanner in = new Scanner(System.in);

    public static BigInteger rec(int p)
    {
        if(dp[p].compareTo(new BigInteger("-1"))>0)
            return dp[p];
        else
            return dp[p]=(two.multiply(rec(p-1))).add(rec(p-2)).add(rec(p-3));
    }

    public static void main(String args[])
    {
        int n;
        for(n=0;n<1001;n++)
            dp[n]=new BigInteger("-2");
        dp[0]=one;
        dp[1]=two;
        dp[2]=new BigInteger("5");
        rec(1000);
        while(in.hasNextInt())
        {
            n=in.nextInt();
            System.out.println(dp[n]);
        }
    }
}