class RLEIterator {
private:
    deque<pair<int, int>> nums;

public:
    RLEIterator(vector<int>& encoding) {
        for(int i = 0; i < encoding.size(); i += 2){
            if(encoding[i] != 0){
                nums.push_back(make_pair(encoding[i], encoding[i + 1]));
            }
        }
    }
    
    int next(int n) {
        int answer = -1;

        while(n > 0){
            if(nums.size() == 0){
                return -1;
            }

            if(n <= nums[0].first){
                answer = nums[0].second;
                nums[0].first -= n;
                break;
            }
            else{
                n -= nums[0].first;
                nums.pop_front();
            }
        }

        return answer;
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */