#include<stdio.h>
#include<iostream>
using namespace std;
long long gcd(long long x , long long y)
{
   if(x < y)
      return gcd(y , x) ;
   if(y == 0)
      return x ;
    if(x % 2 == 1) //x为奇
    {
      if(y % 2 == 1) //y为奇           
         return gcd(x - y, y) ;         
      else         //y为偶
         return gcd(x , y >>1) ;            
    }    
    else         //x为偶
    {
       if(y % 2 == 1) //y为奇数            
         return gcd(x >> 1, y) ;         
      else         //y为偶
         return 2 * gcd(x >> 1, y >> 1) ;      
          
    }
     
 }
int main()
{
   long long n;
    while(cin >> n)
    {
	
	    if(n < 3)
	    {
	        cout << n << endl;
	        continue;
	    }
	    if(n%2==1)
	        cout << n*(n-1)*(n-2) << endl;
	    else
	    {
	       	long long tot = (n-1) * (n-2) * (n-3);
	   	long long max = (n - 2) / 2;
	        for(long long j = n - 3; ;j -= 2)
	        {
	            if(gcd(j, n) > 1)
	                continue;
	            if(gcd(j, n) > 1)
	                continue;
	            max = j;
	            break;
	        }
	        long long tmp = n * (n-1) * max ;
	        if(tmp > tot)
	            tot = tmp;
	        cout << tot << endl;
	    }
	}
	
    return 0;
}
