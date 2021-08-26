#include <iostream>

using namespace std;

/*dynamic programing 
  one problem only one solution 
  
  top down:recursive -> bad 
   
  bottom up:memoization -> good ->space complex
  
  example: pibonacci  

*/

int fibonacci_recursive(int a)
{
	if(a<=2&&a>0)
	{
		return 1;
	}
	return fibonacci_recursive(a-1)+fibonacci_recursive(a-2);
}

int dp[100];
int fibonacci_dp(int a)
{
	if(a<=2&&a>0)
	{
		return 1;
	}
//	if(dp[a]!=0)
//	{
//		return dp[a];
//	}
	return dp[a]=fibonacci_dp(a-1)+fibonacci_dp(a-2);
}


int main(void)
{
	cout<< fibonacci_recursive(3)<<endl ;
	cout<<fibonacci_dp(10)<<endl;

	return 0;
}
