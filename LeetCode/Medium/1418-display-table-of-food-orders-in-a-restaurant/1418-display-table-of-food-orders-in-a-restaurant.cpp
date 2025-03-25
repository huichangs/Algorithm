#include <map>

class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        vector<vector<string>> answer;
        map<int, unordered_map<string, int>> table;
        set<string> menu;

        for(auto i : orders){
            int tableNum = stoi(i[1]);
            string tableMenu = i[2];
            table[tableNum][tableMenu]++;
            menu.insert(tableMenu);
        }

        vector<string> menuTemp;
        menuTemp.push_back("Table");
        for(auto s : menu){
            menuTemp.push_back(s);
        }

        answer.push_back(menuTemp);

        for(auto t : table){
            vector<string> temp;
            temp.push_back(to_string(t.first));
            
            for(auto s: menu){
                if(t.second[s] == 0){
                    temp.push_back("0");
                }else{
                    temp.push_back(to_string(t.second[s]));
                }
            }

            answer.push_back(temp);
        }

        return answer;
    }
};