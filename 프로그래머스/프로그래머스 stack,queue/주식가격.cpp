#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> prices) {
   
    vector<int> answer;
    
    for(int i=0;i<prices.size();i++)
    {
    	answer.push_back(0);
	}
 
    for(int i=0;i<prices.size();i++)
    {
    	for(int j=i+1;j<prices.size();j++)
    	{
    		answer[i]++;
    		if(prices[i]>prices[j])
			{
				break;
			}		
		}
	}
    return answer;
}

vector<int> solution1(vector<int> prices) {
   
    vector<int> answer;
	stack<int> s;
	
	int size=prices.size();
	for(int i=0;i<prices.size();i++)
    {
    	answer.push_back(0);
	}
 
	for(int i=0;i<size;i++)
	{
		while(!s.empty() && prices[s.top()] > prices[i])
		{
			
			answer[s.top()]=i-s.top();
			s.pop();
		}
		s.push(i);
		
	}

	while(!s.empty())
	{
		answer[s.top()]=size-s.top()-1;
		s.pop();
	}
    return answer;
}

int main(void)
{
	vector <int>prices;
	
	prices.push_back(1);
	prices.push_back(2);
	prices.push_back(3);
	prices.push_back(2);
	prices.push_back(3);
	
	vector<int> res=solution1(prices);
	
	for(int i=0;i<res.size();i++)
	{
		cout<<res[i]<<endl;
		
	} 
	return 0;
}
