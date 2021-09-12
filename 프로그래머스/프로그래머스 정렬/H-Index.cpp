#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int solution(vector<int> citations) {
    int answer = 0;
	
	sort(citations.begin(),citations.end());
	
	int n=citations.size();
	
	for(int i=0;i<citations.size();i++)
	{
		int index=n-i;
		
		if(citations[i]>=index)
		{	
			answer=index;
			cout<<answer<" ";
		}
	}
	
    return answer;
}

int main(void)
{
	vector<int> citations;
	
	citations.push_back(3);
	citations.push_back(0);
	citations.push_back(6);
	citations.push_back(1);
	citations.push_back(5);
	
	
	int sol=solution(citations);
	cout<<sol<<endl;
	
	
	return 0;
}
