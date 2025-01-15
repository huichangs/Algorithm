import java.util.*;
import java.io.*;

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    
    public List<TreeNode> generateTrees(int n) {
        if(n == 0){
            List<TreeNode> tree = new ArrayList<>();
            return tree;
        }
        return backTrack(1, n);

        
    }

    ArrayList<TreeNode> backTrack(int i, int j){
        ArrayList<TreeNode> tree = new ArrayList<>();
        if(i > j){
            tree.add(null);
            return tree;
        }

        for(int a = i; a <= j; a++){
            ArrayList<TreeNode> leftTree = backTrack(i, a - 1);
            ArrayList<TreeNode> rightTree = backTrack(a + 1, j);

            for(int left = 0; left < leftTree.size(); left++){
                for(int right = 0; right < rightTree.size(); right++){
                    TreeNode curr = new TreeNode(a, leftTree.get(left), rightTree.get(right));
                    tree.add(curr);
                }
            }
        }

        return tree;
    }
}