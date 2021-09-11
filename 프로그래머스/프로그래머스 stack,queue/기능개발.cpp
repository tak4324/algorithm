#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
	vector<int> answer;
	queue<int> queue;
	int limits=100;
	int count=0;
	
	for(int i=0;i<progresses.size();i++)
	{
		queue.push(progresses[i]);
	}
	
	while(!queue.empty())
	{
		
		for(int i=0;i<queue.size();i++)
		{
			int temp=queue.front();
			queue.pop();
			queue.push(temp+speeds[i]);
		}
		
		while(!queue.empty()&&queue.front()>=limits)
		{
			queue.pop();
			count++;
		speeds.erase(speeds.begin());

		}
		
		if(count>0)
		{
			answer.push_back(count);
		}
		count=0;	
	}
	
	return answer;
}

int main(void)
{
	vector<int> progresses;
	vector<int> speeds;
	
	progresses.push_back(93);
	progresses.push_back(30);
	progresses.push_back(55);
	
	speeds.push_back(1);
	speeds.push_back(30);
	speeds.push_back(5);
	
	
	vector<int> answer=solution(progresses,speeds);
	
	for(int i=0;i<answer.size();i++)
	{
		cout<<answer[i]<<" ";

	}
	
	return 0;
}
