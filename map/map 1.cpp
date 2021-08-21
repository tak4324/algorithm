#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    //이중 for문으로 돌릴 시 run time error 뜸 

    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());

    for (int i = 0; i < participant.size(); i++)
    {
        if(participant[i]!=completion[i])
        {
            answer = participant[i];
            return answer;
        }
    }

}

int main(void)
{
    vector<string> participant = { "leo", "kiki", "eden"};
    vector<string> completion = { "eden", "kiki" };

    string sol = solution(participant, completion);

    cout << sol;

    return 0;
}