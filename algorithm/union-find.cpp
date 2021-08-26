#include <iostream>

using namespace std;

int parent[11];

int getParent(int x)//부모 노드 찾기  
{
	if(parent[x]==x) //속해있으면  
	{
		return x;
	}
	
	return parent[x]= getParent(parent[x]); //재귀 이용 

}

void unionParent(int a,int b)// 합치기  
{
	a=getParent(a);
	b=getParent(b);
	 
	if(a<b)//더 작은 숫자 부모노드  
	{
		parent[b]=a;
	}else
	{
		parent[a]=b;
	}
}

bool findParent(int a,int b) //같은 집합인지  
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
int main()
{
	//1={1} 2={2} 3={3}... 
	for(int i=i;i<=10;i++)
	{
		parent[i]=i;
	} 
	
	unionParent(1,2);
	unionParent(1,11);
	unionParent(5,11);
	unionParent(6,7);
	
	
	
	return 0;
}
