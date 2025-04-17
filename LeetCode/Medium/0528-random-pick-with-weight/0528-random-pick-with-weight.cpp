class Solution {
private:
    int sum;
    vector<int> probability;

public:
    Solution(vector<int>& w) {
        sum = 0;
        for(int i = 0; i < w.size(); i++){
            sum += w[i];
            probability.push_back(sum);
        }
    }
    
    int pickIndex() {
        int random = rand() % sum;
        int answer = -1;
        
        for(int i = 0; i < probability.size(); i++){
            if(random < probability[i]){
                answer = i;
                break;
            }
        }

        return answer;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */