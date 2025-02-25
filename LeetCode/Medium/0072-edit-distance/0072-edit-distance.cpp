class Solution {
public:
    int minDistance(string word1, string word2) {
        int dist[501][501];
        
        for(int i = 1; i <= word1.size(); i++){
            dist[i][0] = i;
        }

        for(int i = 1; i <= word2.size(); i++){
            dist[0][i] = i;
        }

        for(int i = 1; i <= word1.size(); i++){
            for(int j = 1; j <= word2.size(); j++){
                if(word1[i - 1] == word2[j - 1]){
                    dist[i][j] = dist[i - 1][j - 1];
                }else{
                    dist[i][j] = min(dist[i - 1][j], min(dist[i][j - 1], dist[i - 1][j - 1])) + 1;
                }
            }
        }


        return dist[word1.size()][word2.size()];
    }
};