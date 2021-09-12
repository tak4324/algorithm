#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


bool compare_num(string a, string b)
{
	return a + b > b + a;
}

string solution(vector<int> numbers) {

	string answer = "";

	vector<string> number_string(numbers.size());
	
	for (int i = 0; i < numbers.size(); i++)
	{
		number_string[i] = to_string(numbers[i]);		
	}
	sort(number_string.begin(), number_string.end(), compare_num);
	
	int temp = 0;
	for (int i = 0; i < number_string.size(); i++)
	{
		if (number_string[i] =="0")
		{
			temp++;
		}
		answer += number_string[i];
	}
	if(temp==number_string.size())
	{
		return "0";
	}

	return answer;
}
int main(void)
{
	vector<int> numbers = { 0, 0, 0, 0, 0 };
	string res = solution(numbers);
	cout << res << endl;
	return 0;
}