#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int answer;
int sum;
void dfs(vector<int> number,int sum,int target,int index,int n)
{

	if(n==index)
	{
		if(sum==target)
		{
			answer++;
			cout<<"answer: "<<answer;
		}
	}
	else
	{
		dfs(number,sum+number[index],target,index+1,number.size());
		dfs(number,sum-number[index],target,index+1,number.size());
	}
}
int solution(vector<int> number,int target)
{
	//int answer=0;
	dfs(number,sum,target,0,number.size());
	
	return answer;
}
int main(void)
{
	int target=3;
	vector<int> number;
	
	number.push_back(1);
	number.push_back(1);
	number.push_back(1);
	number.push_back(1);
	number.push_back(1);
	
	for(int i=0;i<number.size();i++)
	{
		cout<<number[i];
	}
	int sol=solution(number,target);
	cout<<"sol: "<<sol;
	return 0;
}

