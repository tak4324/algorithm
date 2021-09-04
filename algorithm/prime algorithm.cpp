#include <iostream>
#include <math.h>
using namespace std;

bool isprime(int n)
{
	for(int i=2;i<n;i++)
	{
		if(n % i == 0)
		{
			return false;
		}
	}
	return true;
}

bool isprime1(int n)
{
	//symmetry
	int end=(int)sqrt(n);
	for(int i=2;i<=end;i++)
	{
		if(n%i==0)
		{
			return false;
		}
	}
	return true;
}

int number=100000;
int a[100001];

void prime2(){
	
	for(int i=2;i<=number;i++)
	{
		a[i]=i; //a[2]=2, a[3]=3... 
	}
	
	for(int i=2;i<=number;i++)
	{
		if(a[i]==0)continue; // pass 
		
		for(int j= i + i ;j<=number;j  + =i)
		{
			a[j]=0; // false  
		}
	}
	
	for(int i=2;i<=number;i++)
	{
		if(a[i]!=0)
		{
			cout<<a[i]<<" ";
		}
	}
} 
int main(void)
{
	
	 prime2();
	 
	
	return 0;
}
