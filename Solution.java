
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;
import java.util.List;

public class Solution {

    public List<Integer> preorder(Node root) {
        if (root == null) {
            return new ArrayList<>();
        }

        List<Integer> listPreorder = new ArrayList<>();
        Deque<Node> stack = new ArrayDeque<>();
        stack.push(root);

        while (!stack.isEmpty()) {
            Node node = stack.pop();
            listPreorder.add(node.val);
            final int size = node.children.size();
            for (int i = size - 1; i >= 0; i--) {
                stack.push(node.children.get(i));
            }
        }
        return listPreorder;
    }
}

// Class Node is in-built in the solution file on leetcode.com. 
// When running the code on the website, do not include this class.
class Node {

    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, List<Node> _children) {
        val = _val;
        children = _children;
    }
};
