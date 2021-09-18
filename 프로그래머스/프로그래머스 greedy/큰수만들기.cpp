#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

string solution(string number, int k) {
	string answer = "";
	stack<char> s;
	int cnt=0;
	s.push(number[0]);
	int i;

	for (i = 0; i < number.size(); i++)
	{
		char t = s.top();
		if (t < number[i + 1]) //최근 데이터 보다 값이 작으면 pop
		{
			for (int j = i; j >= 0; j--)
			{
				if (s.empty()||cnt==k)
				{
					break;
				}
				char tmp = s.top();
				if (tmp < number[i + 1])
				{
					//cout << "pop: " << s.top()<<endl;
					s.pop();
					cnt++;
				}
				else 
				{
					break;
				}
			}
			//cout << "push" << number[i + 1] << endl;
			
			s.push(number[i + 1]);
		}
		else
		{
			//cout << "push" << number[i + 1]<<endl;
			s.push(number[i+1]);
		}
	}

	for (int t = i+2; t < number.size(); t++)
	{
		s.push(number[t]);
	}
	
	if (cnt == 0)
	{
		while (cnt != k )
		{
			s.pop();
			cnt++;
		}
	}

	string tmp="";
	while (!s.empty())
	{
		char top = s.top();
		tmp += top;
		s.pop();
	}

	for (int j = tmp.length() - 1; j > 0; j-- )
	{
		answer.push_back(tmp[j]);
	}
	//cout << answer.size();
	return answer;
}

string solution1(string number, int k)
{
	string answer = "";
	int size = number.size() - k; // 5 
	int index = -1;

	for (int i = 0; i < size; i++)
	{
		char temp = ' ';
		for (int j = index + 1; j < k + i + 1; j++)
		{
			if (number[j] > temp)
			{
				temp = number[j];
				index = j;
			}
		}
		answer.push_back(temp);
	}
	
	return answer;
}
int main(void)
{
	string number = "1000";
	 int k = 1;
	//775841
	string sol = solution(number, k);
	
	cout << sol << endl;

	return 0;
}
