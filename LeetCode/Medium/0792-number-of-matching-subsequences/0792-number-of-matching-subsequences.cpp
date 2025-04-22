class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int answer = 0;
        unordered_map<char, deque<int>> table;

        for(int i = 0; i < s.size(); i++){
            table[s[i]].push_back(i);
        }

        for(string word : words){
            int prevIdx = -1;
            int i = 0;

            for(i = 0; i < word.size(); i++){
                char c = word[i];

                if(table.find(c) != table.end()){
                    auto it = upper_bound(table[c].begin(), table[c].end(), prevIdx);
                    if(it == table[c].end()) break;
                    prevIdx = *it;
                }else{
                    break;
                }
            }
            
            if(i == word.size()){
                answer++;
            }
        }

        return answer;
    }


};