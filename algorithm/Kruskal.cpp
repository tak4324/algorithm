#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

class Edge{
	public:
		int node[2];
		int distance;
		Edge(int a,int b,int distance){
			this->node[0]=a;
			this->node[1]=b;
			this->distance=distance;
		}
	bool operator<(Edge &edge)
	{
		return this->distance < edge.distance;
	}
};



int parent[11];

int getParent(int x)//�θ� ��� ã��  
{
	if(parent[x]==x) //����������  
	{
		return x;
	}
	
	return parent[x]= getParent(parent[x]); //��� �̿� 

}

void unionParent(int a,int b)// ��ġ��  
{
	a=getParent(a);
	b=getParent(b);
	 
	if(a<b)//�� ���� ���� �θ���  
	{
		parent[b]=a;
	}else
	{
		parent[a]=b;
	}
}

bool findParent(int a,int b) //���� ��������  
{
	a=getParent(a);
	b=getParent(b);
	if(a==b)
	{
		return true;
	}else
	{
		return false;
	}
}

int main(void)
{
	int n=7;
	int m=11;
	
	vector<Edge> v;
	v.push_back(Edge(1,7,12));	
	v.push_back(Edge(1,4,28));
	v.push_back(Edge(1,2,67));
	v.push_back(Edge(1,5,17));
	v.push_back(Edge(2,4,24));
	
	v.push_back(Edge(2,5,62));
	v.push_back(Edge(3,5,20));
	v.push_back(Edge(3,6,37));
	v.push_back(Edge(4,7,13));
	v.push_back(Edge(5,6,45));
	
	v.push_back(Edge(5,7,73));
	
	//kruskal must sort  
	sort(v.begin(),v.end());
	
	for(int i=0;i<n;i++)
	{
		parent[i]=i;
	}
	
	int sum=0;
	
	for(int i=0;i<v.size();i++)
	{
		//only No cycle
		if(findParent(v[i].node[0]-1,v[i].node[1]-1)==false)
		{
			sum+=v[i].distance;
			unionParent(v[i].node[0]-1,v[i].node[1]-1);
		}
	}
	
	cout<<"shortes path:  "<<sum;
	
	return 0;
}
