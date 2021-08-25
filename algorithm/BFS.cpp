#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int number=10;
bool checked[10]={false,};

vector<int> a[11]; //a[11][11]
 
void bfs(int start)
{
	queue<int> q;
	
	q.push(start); 
	checked[start]=true;
	
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		cout<<x<<" ";
		for(int i=0;i<a[x].size();i++)
		{
			int y=a[x][i];
			if(!checked[y])//not visited
			{
				q.push(y);
				checked[y]=true;
			}
		}
	}
	
}
int main(void)
{
	a[1].push_back(2);
	a[2].push_back(1);
	
	a[1].push_back(3);
	a[3].push_back(1);
	
	a[2].push_back(3);
	a[3].push_back(2);
	
	
	a[2].push_back(4);
	a[4].push_back(2);
	
	a[2].push_back(5);
	a[5].push_back(2);

	a[3].push_back(6);
	a[6].push_back(3);

	a[3].push_back(7);
	a[7].push_back(3);

	a[4].push_back(5);
	a[5].push_back(4);

	a[6].push_back(7);
	a[7].push_back(6);
	
	bfs(1);
	return 0;
}
