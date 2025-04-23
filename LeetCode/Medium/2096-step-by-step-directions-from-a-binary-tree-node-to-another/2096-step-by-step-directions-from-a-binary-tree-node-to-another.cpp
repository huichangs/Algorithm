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
    bool flag = false;
    string rTo = "";
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string answer = "";
        flag = false;
        search(root, startValue, "");
        string rTos = rTo;

        flag = false;
        search(root, destValue, "");
        string rTod = rTo;

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

    void search(TreeNode* curr, int dest, string s){
        if(curr->val == dest){
            rTo = s;
            flag = true;
            return;
        }
        
        if(curr->left != NULL && !flag){
            search(curr->left, dest, s + 'L');
        }
        if(curr->right != NULL && !flag){
            search(curr->right, dest, s + 'R');
        }

        return;
    }

};