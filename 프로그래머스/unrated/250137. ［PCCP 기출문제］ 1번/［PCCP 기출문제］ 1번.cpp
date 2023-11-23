#include <string>
#include <vector>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = 0;
    int time =1,maxtime = attacks.back()[0], idx=0, con=0, maxhealth = health;
    while(time <= maxtime)
    {            
        con++;
        if(attacks[idx][0] == time)
        {
            health -= attacks[idx][1];
            con = 0;
            idx++;
        }
        else
        {
            health += bandage[1];
            if(con == bandage[0])
            {
                health += bandage[2];
                con =0;
            }
            if(health > maxhealth) health = maxhealth;
            if(health < 0) 
            {
                health = -1;
                break;
            }
        }
        time++;
    }
    
    health > 0 ? answer = health : answer = -1;
    return answer;
}