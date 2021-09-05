#include <iostream>
#include <vector>
#include <stack>

#define MAX 100001
// strongly Connected Component
// SCC algorithm 
// SCC must emerge cycle 
// Scc direct graph 

// -----Kind-------  
// Kosaraju's Algorithm easy than Tarjhan's

/* 
	Tarjhan's Algoritm 
	union find similar  
	Using DFS 
*/
using namespace std;

int id,d[MAX];
bool finished[MAX];
vector<int> a[MAX];
vector<vector<int> > SCC;
stack<int> s;

int dfs(int x)
{
	d[x]= ++id;
	s.push(x); //insert x in stack 
	
	int parent=d[x]; // myself parent 
	for(int i=0;i<a[x].size();i++)
	{
		int y=a[x][i];
		if(d[y] == 0) //not visited neighbor node
		{
			parent=min(parent,dfs(y));
		}else if(!finished[y]) // process node
		{
			parent=min(parent,d[y]);
		}
	}
	
	if(parent==d[x])//parent node is myself
	{
		vector<int> scc;
		while(1)
		{
			int t=s.top();
			s.pop();
			scc.push_back(t);
			finished[t]=true;
			if(t==x)
			{
				break;
			}
		}
		SCC.push_back(scc);
	}
	//my parent node return 
	return parent;	
}
int main(void)
{
	int v=11;//node num
	
	a[1].push_back(2);
	a[2].push_back(3);
	a[3].push_back(1);
	
	a[4].push_back(2);
	a[4].push_back(5);
	
	a[5].push_back(7);
	
	a[6].push_back(5);
	a[7].push_back(6);
	
	a[8].push_back(5);
	a[8].push_back(9);
	
	a[9].push_back(10);
	a[10].push_back(11);
	
	a[11].push_back(3);
	a[11].push_back(8);
	
	for(int i=1;i<=v;i++)
	{
		if(d[i]==0)
		{
			dfs(i);
		}
	}
	cout<<"SCC NUM: "<<SCC.size()<<endl;
	
	for(int i=0;i<SCC.size();i++)
	{
		cout<<i+1<<"¹ø¤Š SCC: ";
		for(int j=0;j<SCC[i].size();j++)
		{
			cout<<SCC[i][j]<<" ";
		 } 
		 cout<<endl;

	}
	
	
	
	return 0;
}
