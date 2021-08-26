#include <iostream>

using namespace std;

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
