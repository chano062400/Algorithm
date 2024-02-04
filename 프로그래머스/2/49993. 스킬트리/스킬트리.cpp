#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    map<char,int> skills;
    for(int i=0; i<skill.length(); i++)
    {
        char ch = skill[i];
        if(skills.count(ch) == 0) skills.insert({ch,i});
    }
    
    int skillnumber;
    bool rightskill;
    for(int i=0; i<skill_trees.size(); i++)
    {
        rightskill = true;
        skillnumber = 0;
        for(int j=0; j<skill_trees[i].length(); j++)
        {
            char ch = skill_trees[i][j], nch = skill_trees[i][j+1];
            if(skills.count(ch) == 1)
            {
                if(skillnumber != skills[ch]) 
                {
                    rightskill= false;
                    break;
                }
                skillnumber++;
            }
        }
        if(rightskill) answer++;
    }
    return answer;
}