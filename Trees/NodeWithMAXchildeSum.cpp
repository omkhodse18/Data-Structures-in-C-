#include <iostream>
#include <queue>
#include <vector>
using namespace std;

template <typename T>
class TreeNode {
   public:
    T data;
    vector<TreeNode<T>*> children;

    TreeNode(T data) { this->data = data; }

    ~TreeNode() {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }
};

TreeNode<int>* takeInputLevelWise() {
    int rootData;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingNodes;

    pendingNodes.push(root);
    while (pendingNodes.size() != 0) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++) {
            int childData;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }

    return root;
}

int sum(TreeNode<int> *root){
    if(root == NULL) return 0;
    int ans = root->data;
    for(auto &node:root->children) ans += node->data;
    return ans;
}

TreeNode<int>* maxSumNode(TreeNode<int>* root) {
    if(root == NULL) return root;
    int s = sum(root);
    TreeNode<int> *ans = root;
    for(auto &node:root->children){
        TreeNode<int> *temp = maxSumNode(node);
        int tempS = sum(temp);
        if(tempS > s){
            s = tempS;
            ans = temp;
        }
    }
    return ans;
}
int main() {
    TreeNode<int>* root = takeInputLevelWise();

    TreeNode<int>* ans = maxSumNode(root);

    if (ans != NULL) {
        cout << ans->data;
    }
}