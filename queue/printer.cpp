#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    
    priority_queue<int> pq;
    queue<int> q;
    
    for(int i=0;i<priorities.size();i++)
    {
    	q.push(priorities[i]);
	}
	
    
	return answer;
}
int solution1 (vector<int> priorities, int location) {
    int answer = 0;
    int number[10] = {0,}; 
    bool check[101] = {false , }; 
    int max_priority = 0 , idx = 0;
    
    for(int i=0; i<priorities.size(); i++)  number[priorities[i]]++;    // 우선순위마다 프린터 개수를 기록 
    for(int i=1; i<=9; i++) // 가장 높은 우선 순위 찾기 
        if(number[i] != 0 )
            max_priority = i; 
    
    while(true){    
        if(!check[idx]){ // 아직 인쇄 안 한 경우
            if(priorities[idx] == max_priority){ // 현재 프린트 인쇄 가능한 경우 
                number[priorities[idx]]--; 
                check[idx] = true; 
                answer++; 
                if(idx == location) break;
                if(number[priorities[idx]] == 0){ // 해당 우선 순위의 프린트를 모두 출력한 경우
                    max_priority = 0;
                    for(int i=1; i<=9; i++) // 가장 높은 우선 순위 찾기 
                        if(number[i] != 0 )
                            max_priority = i; 
                }
            }
        }
        idx++; 
        if(idx == priorities.size())  // 맨 마지막 프린트물을 확인한 경우 다시 처음으로.   
            idx = 0 ;
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
	  
	int location=1;
	
	int res=solution1(priorities,location);
	cout<<res<<endl;
	
	return 0;
}
