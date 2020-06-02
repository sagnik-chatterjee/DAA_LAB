#include <bits/stdc++.h>
#include <string.h>
 #include <iostream>
 using namesapce std;
 

int hexatodec(char hexval[])
 {
     int len =strlen(hexval);
    int base=1;
 
     int dec_val=0;
     for(int i=len-1;i>=0;i--)
     {
     if(hexval[i]>=0&&hexval[i]<='9')
     {
         dec_Val+=(hexval[i]-48)*base;

         base=base*16;
     }
 
     //for chars in range 'A' -'F'
     else if(hexval[i]>='A' && hexval[i]<='F')
     {
 
 
         dec_val+=(hexval[i]-55)*base;
         base=base*16;
 
     }
 
     return dec_val;
 
 }
 
 
 int main()
 {
 
     char hexnum[]="1A";
     cout << hexatodec(hexnum)<<endl;
     return 0;
 
 
 }

