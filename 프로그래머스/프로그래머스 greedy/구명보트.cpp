#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end());
    int end = people.size() - 1;
    int begin = 0;

    while (1) {

        if (begin > end)
        {
            break;
        }
        if (people[begin] + people[end] <= limit)
        {
            answer++;
            begin++;
            end--;
        }
        else
        {
            end--;
            answer++;
        }
    }
    if (begin == end)
        return answer + 1;

    return answer;
}

int main(void)
{
    vector<int> people;
    people.push_back(70);
    people.push_back(50);
    people.push_back(80);
    people.push_back(50);


    int limit = 100;

    int sol = solution(people, limit);
    
    cout << sol << endl;

    return 0;
}