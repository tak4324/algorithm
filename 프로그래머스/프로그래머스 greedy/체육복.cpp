#include <iostream>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve)
{
	int answer=0;

	vector<int>temp;	
	for(int i=0;i<n;i++)
	{
		temp.push_back(1);
	} 
	
	for(int i=0;i<n;i++)
	{
		if(i==lost.size())
		{
			break;
		}
		temp[lost[i]-1]--;
	}
	
	for(int i=0;i<n;i++)
	{
		if(i==reserve.size())
			break;
		temp[reserve[i]-1]++;
	}
	
	 for(int i = 0; i < n; i++){
        if(i > 0 && temp[i] == 0 && temp[i-1] == 2){
        	temp[i-1]--; 
			temp[i]++;
        }
        if(i<n-1 &&temp[i]==0 && temp[i+1]==2)
        {
        	temp[i+1]--;
        	temp[i]++;

		}
       
    }
	
	for(int i=0;i<n;i++)
	{
		if(temp[i]!=0)
		{
			answer++;
		}
	}

	return answer;
	
}
int main(void)
{
	int n=5;
	vector<int> lost;
	lost.push_back(2);
	lost.push_back(4);	
	

	vector<int>reserve;
	
	reserve.push_back(1);
	reserve.push_back(3);s
	reserve.push_back(5);
	
	int answer=solution(n,lost,reserve);
	
	cout<<answer<<endl;
	
		
	return 0;
}
