class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int size = grid[0].size();
        if(size == 1){
            return 0;
        }
        if(size == 2){
            return min(grid[0][1], grid[1][0]);
        }
        vector<vector<long long>> arr(2, vector<long long>(size, 0));

        arr[1][0] = grid[1][0];
        arr[0][size - 1] = grid[0][size - 1];

        for(int i = 1; i < size; i++){
            int j = size - i - 1;
            arr[1][i] = arr[1][i - 1] + grid[1][i];
            arr[0][j] = arr[0][j + 1] + grid[0][j];
        }

        arr[1][size - 1] = 0;
        arr[0][0] = 0;

        long long answer = arr[0][1];
        for(int i = 2; i < size; i++){
            long long tmp = max(arr[0][i], arr[1][i - 2]);

            answer = min(tmp, answer);
        }
        answer = min(answer, arr[1][size - 2]);

        return answer;
    }
};