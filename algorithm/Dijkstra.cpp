#include <iostream>
#include <queue>
#include <vector>

#define MAX 6
#define INF 1000000
//gredy shortest path

using namespace std;

//---------------------time complex n^2  
int graph[MAX][MAX]=
{
	{0, 2, 5, 1, INF, INF},
	{2, 0, 3, 2, INF, INF},
	{5, 3, 0, 3, 1, 5},
	{1, 2, 3, 0, 1, INF},
	{INF, INF, 1, 1, 0, 2},
	{INF, INF, 5, INF ,2, 0}
};

bool visited[MAX];
int dist[MAX];
int getSmallIndex()
{
	int min=INF;
	int index=0;
	
	for(int i=0;i<MAX;i++)
	{
		if(dist[i]<min &&!visited[i])
		{
			min=dist[i];
			index=i;	
		}	
	}
	return index;	
}


void dijkstra(int start)
{
	for(int i=0;i<MAX;i++)
	{
		dist[i]=graph[start][i];
	}
	visited[start]=true;
	
	for(int i=0;i<MAX-2;i++)
	{
		int current=getSmallIndex();
		visited[current]=true;
		for(int j=0;j<MAX;j++)
		{
			if(!visited[j])
			{
				if(dist[current]+graph[current][j]<dist[j])
				{
					dist[j]=dist[current]+graph[current][j];	
				}	
			}	
		}
	}
}
//------------------------------------------- using heap time complex nlogn 

int dist1[7];
vector <pair<int,int> > graph1[7];
void dijkstra1(int start)
{
	dist1[start]=0;
	priority_queue<pair<int, int> > pq;//heap
	pq.push(make_pair(start,0));//  
	
	while(!pq.empty())
	{
		int current=pq.top().first; //
		// shortes (-) 
		int distance=-pq.top().second;
		pq.pop();
		//not shortest -> skip
		if(dist1[current]<distance)
		{
			continue;
		}
		for(int i=0;i<graph1[current].size();i++)
		{
			int next=graph1[current][i].first;
			int nextDistance=distance+graph1[current][i].second;
			
			if(nextDistance<dist1[next])
			{
				dist1[next]=nextDistance;
				pq.push(make_pair(next,-nextDistance));
			}
		}
	}
	
	
}


int main(void)
{
	//dijkstra(0);
	for(int i=1;i<=MAX;i++)
	{
		dist1[i]=INF;
	}
	graph1[1].push_back(make_pair(2,2));
	graph1[1].push_back(make_pair(3,5));
	graph1[1].push_back(make_pair(4,1));	

	graph1[2].push_back(make_pair(1,2));
	graph1[2].push_back(make_pair(3,3));
	graph1[2].push_back(make_pair(4,2));
	
	graph1[3].push_back(make_pair(1,5));
	graph1[3].push_back(make_pair(2,3));
	graph1[3].push_back(make_pair(4,3));
	graph1[3].push_back(make_pair(5,1));
	graph1[3].push_back(make_pair(6,5));
	
	graph1[4].push_back(make_pair(1,1));
	graph1[4].push_back(make_pair(2,2));
	graph1[4].push_back(make_pair(3,3));
	graph1[4].push_back(make_pair(5,1));
	
	graph1[5].push_back(make_pair(3,1));
	graph1[5].push_back(make_pair(4,1));								
	graph1[5].push_back(make_pair(6,2));
	
	graph1[6].push_back(make_pair(3,5));
	graph1[6].push_back(make_pair(5,2));
	
	dijkstra1(1);
	
	for(int i=1;i<=MAX;i++)
	{
		cout<<dist1[i]<<" ";
	}
	cout<<endl;
	
	return 0;
}
