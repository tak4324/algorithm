#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;



bool isprime1(int n)
{
	//symmetry
	if (n == 1)
	{
		return false;
	}
	 
	int end = (int)sqrt(n);
	for (int i = 2; i <= end; i++)
	{
		if (n % i == 0)
		{
			return false;
		}
	}
	return true;
}
bool compare(int num1,int num2)
{
	return num1 > num2;
}

int solution(string numbers) {
    int answer = 0;
	
	sort(numbers.begin(), numbers.end(), compare);

	
	for (int i = 0; i < numbers.size(); i++)
	{
		if (isprime1(numbers[i] - '0'))
		{
			answer++;
		}
		string temp = "";
		temp+=numbers[i];
		for (int j = i; j <= numbers.size(); j++)
		{
			if (i == j)
			{
				continue;
			}
			temp+= numbers[j];
		
		}
	}
    return answer;
}
int main(void)
{
    string numbers = "17";

    int sol = solution(numbers);
    cout << sol << endl;

	return 0;
}
