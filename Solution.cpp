
#include <queue>
#include <vector>
using namespace std;

// Class Node is in-built in the solution file on leetcode.com. 
// When running the code on the website, do not include this class.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}
    
    Node(int _val) {
        val = _val;
    }
    
    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<int> listPreorder;

    vector<int> preorder(Node* root) {
        if (root == nullptr) {
            return vector<int>();
        }

        vector<int> listPreorder;
        deque<unique_ptr < Node>> stack;
        stack.push_front(unique_ptr<Node>(root));

        while (!stack.empty()) {
            unique_ptr<Node> node = move(stack.front());
            stack.pop_front();
            listPreorder.push_back(node->val);
            const size_t size = node->children.size();
            for (int i = size - 1; i >= 0; i--) {
                stack.push_front(unique_ptr<Node>(node->children[i]));
            }
        }
        return listPreorder;
    }
};
