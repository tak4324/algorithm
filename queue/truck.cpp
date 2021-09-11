 #include <iostream>
#include <vector>
#include <queue>

using namespace std;

#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<int> q;
    	
	int max=0;

	int i=0;
	
	while(i!=truck_weights.size())
	{
		
		int car=truck_weights[i];
			
		if(q.size()==bridge_length)
		{
			
			max-=q.front();
			q.pop();	
		}
			
		if(max + car<=weight)
		{
			answer++;
			max+=car;
			q.push(car);
			i++;
		}else if(max + car > weight )
		{
			answer++;
			q.push(0); 
		}
		
	}

	return answer+bridge_length;
	 
}

int main(void)
{
	int bridge_length=2;
	int weight=10;
	vector<int> truck_weights;
	
	 truck_weights.push_back(7);
	 truck_weights.push_back(4);
	 truck_weights.push_back(5);
	 truck_weights.push_back(6);
	
	int sol=solution(bridge_length,weight,truck_weights);
	cout<<sol<<endl;
	
	return 0;
}
