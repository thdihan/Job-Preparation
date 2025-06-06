# Binary Tree

::: info
Full Binary Tree \
A full binary tree, on the other hand, does not have any nodes that have only one child node.\
[GFG-Ref](https://www.geeksforgeeks.org/full-binary-tree/)
:::

## Travarsal Algorithm

### Pre-order using recurrsion:

```cpp
/**
 * Time Complexity: O(n)
 * Auxiliary Space: O(h), h is the height of the tree
 * In the worst case, h can be the same as n (when the tree is a skewed tree)
 * In the best case, h can be the same as log n (when the tree is a complete tree)
 */
void preorderUsingRecurr (Node* root) {
    if(root == nullptr)
        return;

    cout << root->data << " ";
    preorderUsingRecurr(root->left);
    preorderUsingRecurr(root->right);
}
```

### Pre-order using stack:

```cpp
/**
 * Time O(n), Space O(n)
*/
void preorderUsingStack (Node* root) {
    stack<Node*> st;

    if(root == nullptr) return;

    st.push(root);

    while(!st.empty()) {
        Node* front = st.top();
        st.pop();

        cout << front->data<<" ";

        if(front->right != nullptr) {
            st.push(front->right);
        }

        if(front->left != nullptr) {
            st.push(front->left);
        }

    }
}
```
