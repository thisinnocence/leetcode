#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // just BFS, use queue
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans;

        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            size_t queSize = que.size(); // import
            vector<int> ve;
            for (size_t i = 0; i < queSize; i++) {
                ve.push_back(que.front()->val);
                if (que.front()->left) que.push(que.front()->left);
                if (que.front()->right)que.push(que.front()->right);
                que.pop();
            }
            ans.push_back(ve);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};


int main() {
    TreeNode node0(3), node1(9), node2(20), node3(15), node4(7);
    node0.left = &node1;
    node0.right = &node2;
    node2.left = &node3;
    node2.right = &node4;
    Solution sl;
    vector<vector<int>> ans = sl.levelOrderBottom(&node0);
    for (auto ve: ans) {
        for (auto re: ve) {
            cout << re << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}
