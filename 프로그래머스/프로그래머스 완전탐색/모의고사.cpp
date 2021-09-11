#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
   	
   	vector<int>math_std;
   	
   	for(int i=0;i<3;i++)
   	{
   		math_std.push_back(0);	
	}
    int std1[5]={1,2,3,4,5};
    int std2[8]={2,1,2,3,2,4,2,5};
    int std3[10]={3,3,1,1,2,2,4,4,5,5};
    
	for(int i=0;i<answers.size();++i)
	{
		if(answers[i]==std1[i%5])
		{
			math_std[0]++;
		}
		if(answers[i]==std2[i%8])
		{
			math_std[1]++;
		}
		if(answers[i]==std3[i%10])
		{
			math_std[2]++;
		}	
	}
	
	
	int maximum=*max_element(math_std.begin(),math_std.end());
	if(maximum==0)
	{
		return answer;
	}
	
	for(int i=0;i<math_std.size();i++)
	{
		if(maximum==math_std[i])
		{
			answer.push_back(i+1);	
		}
		
	}

    	return answer;
	
}

int main(void)
{
	vector<int> answers;
	answers.push_back(1);
	answers.push_back(3);
	answers.push_back(2);
	answers.push_back(4);
	answers.push_back(2);
	
	vector<int> result=solution(answers);
	
	for(int i=0;i<result.size();i++)
	{
		cout<<result[i]<<" ";
	}
	

	return 0;
}

