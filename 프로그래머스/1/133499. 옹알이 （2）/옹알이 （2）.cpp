#include <string>
#include <vector>

using namespace std;

string arr[4] = {"aya", "ye", "woo", "ma"};

int solution(vector<string> babbling) {
    int answer = 0;
    for (int i = 0; i < babbling.size(); i++)
    {
        string str = babbling[i];
        int index = 0, cnt=0;
        string prev = "";
        while (true)
        {
            if ((str.substr(0, 3) != arr[index] && str.substr(0, 2) != arr[index])
                || str.substr(0, 3) == prev || str.substr(0, 2) == prev)
            {
                cnt++;
                index++;
            }

            index %= 4;

            if (str.length() >= 3 && str.substr(0, 3) == arr[index] && str.substr(0, 3) != prev)
            {
                prev = arr[index];
                str.erase(0, 3);
            }

            if (str.length() >= 2 && str.substr(0, 2) == arr[index] && str.substr(0, 2) != prev)
            {
                prev = arr[index];
                str.erase(0, 2);
            }

            if (cnt < 25 && str.empty())
            {
                answer++;
                break;
            }
            else if (cnt >= 25 && !str.empty()) break;
        }
        
    }

    return answer;
}