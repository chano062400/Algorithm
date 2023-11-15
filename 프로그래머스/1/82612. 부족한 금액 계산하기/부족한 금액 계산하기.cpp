using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = -1;
    long long mul = (count * (count-1)) / 2;
    answer = (mul * price) + (price * count) - money;
    return answer <= 0 ? 0 : answer;
}