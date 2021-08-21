#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>


using namespace std;

int solution(vector<int> scoville, int K) {
	 int answer=0;
	 priority_queue< int,vector<int>,greater<int> > pq;

	for(int i=0;i<scoville.size();i++)
	{
		pq.push(scoville[i]);
	}
	
	while(pq.top()<=K)
	{
		if(pq.size()==2&&pq.top()<=K)
		{
			return -1;
		}
		answer++;
		int p=pq.top();
		pq.pop();
		int q=pq.top();
		pq.pop();
		
		int sol=p+(q*2);
		pq.push(sol);	
	}
	
	return answer;
    
}


int main(void)
{
	vector<int> scoville;
	int K=7;
	
	scoville.push_back(1);
	scoville.push_back(2);
	scoville.push_back(3);
	scoville.push_back(9);
	scoville.push_back(10);
	scoville.push_back(12);
	
	int sol=solution(scoville,K);
	
	cout<<sol<<" ";

	

	return 0;
}

