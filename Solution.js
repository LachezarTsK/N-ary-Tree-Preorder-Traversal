
// Function Node is in-built in the solution file on leetcode.com. 
// When running the code on the website, do not include this function.
function Node(val, children) {
    this.val = val;
    this.children = children;
}

/**
 * @param {Node|null} root
 * @return {number[]}
 */
var preorder = function (root) {
    if (root === null) {
        return [];
    }

    const listPreorder = [];
    const stack = [];
    stack.push(root);

    while (stack.length > 0) {
        const node = stack.pop();
        listPreorder.push(node.val);
        const size = node.children.length;
        for (let i = size - 1; i >= 0; i--) {
            stack.push(node.children[i]);
        }
    }
    return listPreorder;
};
