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
    
    for(int i=0; i<priorities.size(); i++)  number[priorities[i]]++;    // �켱�������� ������ ������ ��� 
    for(int i=1; i<=9; i++) // ���� ���� �켱 ���� ã�� 
        if(number[i] != 0 )
            max_priority = i; 
    
    while(true){    
        if(!check[idx]){ // ���� �μ� �� �� ���
            if(priorities[idx] == max_priority){ // ���� ����Ʈ �μ� ������ ��� 
                number[priorities[idx]]--; 
                check[idx] = true; 
                answer++; 
                if(idx == location) break;
                if(number[priorities[idx]] == 0){ // �ش� �켱 ������ ����Ʈ�� ��� ����� ���
                    max_priority = 0;
                    for(int i=1; i<=9; i++) // ���� ���� �켱 ���� ã�� 
                        if(number[i] != 0 )
                            max_priority = i; 
                }
            }
        }
        idx++; 
        if(idx == priorities.size())  // �� ������ ����Ʈ���� Ȯ���� ��� �ٽ� ó������.   
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
