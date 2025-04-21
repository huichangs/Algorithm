class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int answer = 0;
        int len = bombs.size();

        for(int i = 0; i < len; i++){
            int tmp_answer = 0;
            vector<bool> visited(len, false);
            deque<int> queue;
            queue.push_back(i);
            visited[i] = true;

            while(!queue.empty()){
                int curr = queue.front();
                queue.pop_front();
                tmp_answer++;

                for(int j = 0; j < visited.size(); j++){
                    if(reachable(bombs[curr][0], bombs[curr][1], bombs[j][0], bombs[j][1], bombs[curr][2]) && !visited[j]){
                        queue.push_back(j);
                        visited[j] = true;
                    }
                }
            }

            answer = max(tmp_answer, answer);
        }

        return answer;
    }

    bool reachable(int x1, int y1, int x2, int y2, int rad){
        long long dist = (long long)(x1 - x2) * (x1 - x2) + (long long) (y1 - y2) * (y1 - y2);
        long long bombDist = (long long) rad * rad;
        if(dist <= bombDist){
            return true;
        }else{
            return false;
        }
    }
};