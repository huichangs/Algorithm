class Solution {
public:
    bool canTransform(string start, string result) {
        bool answer = true;
        int sPtr = 0;
        int rPtr = 0;

        while(sPtr < start.size() || rPtr < start.size()){
            while(start[sPtr] == 'X') sPtr++;
            while(result[rPtr] == 'X') rPtr++;
            //cout << sPtr << rPtr <<start[sPtr] << result[rPtr] << endl;

            if(start[sPtr] != result[rPtr]) return false;

            if(start[sPtr] == 'R' && sPtr > rPtr) return false;
            if(result[rPtr] == 'L' && sPtr < rPtr) return false;

            sPtr++;
            rPtr++;
        }

        return answer;
    }
};