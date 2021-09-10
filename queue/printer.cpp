#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    priority_queue<int> pq;
    queue<pair<int,int> > q;

	 // insert q,pq  
    for(int i=0;i<priorities.size();i++)
    {
    	q.push(make_pair(i,priorities[i]));
    	pq.push(priorities[i]);
	}   
	
	while(!q.empty())
	{
		int first=q.front().first; //index
		int second=q.front().second;//priority
		q.pop();
		
		if(second==pq.top())
		{
			pq.pop();
			answer++;
			if(location==first)
			{
				break;
			}
		}else
		{
			q.push(make_pair(first,second));
		}
	}
	
	return answer;
}

int main()
{
	vector<int> priorities;
	
	priorities.push_back(2);
	priorities.push_back(1);
	priorities.push_back(3);
	priorities.push_back(2);
	  
	int location=0;
	
	int res=solution(priorities,location);
	cout<<res<<endl;
	
	return 0;
}
