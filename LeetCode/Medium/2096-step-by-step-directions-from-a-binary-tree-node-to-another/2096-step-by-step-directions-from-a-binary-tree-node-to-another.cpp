/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
string rTos, rTod;
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string answer = "";
        string tmp;
        search(root, startValue, destValue, tmp);
        
        int i = 0;
        int j = 0;
        while(i < rTos.size()){
            if(rTos[i] != rTod[j]){
                while(i < rTos.size()){
                    answer += 'U';
                    i++;
                }
            }
            else{
                i++;
                j++;
            }
        }
        answer += rTod.substr(j);

        return answer;
    }

    void search(TreeNode* curr, int start, int dest, string& s){
        if(curr->val == start){
            rTos = s;
        }
        if(curr->val == dest){
            rTod = s;
        }
        
        if(curr->left != NULL){
            search(curr->left, start, dest, s += 'L');
            s.pop_back();
        }
        if(curr->right != NULL){
            search(curr->right, start, dest, s +='R');
            s.pop_back();
        }

        return;
    }

};