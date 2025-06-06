#include <iostream>
#include <stack>

using namespace std;
// Node using struct
struct Node {
    int data;
    Node* left;
    Node* right;

    Node (int val ){
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

Node** createNodes (int n) {
    Node** nodes = new Node*[n];
    for(int i = 0; i < n; i++) {
        nodes[i] = new Node(i);
    }

    return nodes;
}

/**
 * Time Complexity: O(n)
 * Auxiliary Space: O(h), h is the height of the tree
 *  In the worst case, h can be the same as n (when the tree is a skewed tree)
 * In the best case, h can be the same as log n (when the tree is a complete tree)
 */
void preorderUsingRecurr (Node* root) {
    if(root == nullptr)
        return;
    
    cout << root->data << " ";
    preorderUsingRecurr(root->left);
    preorderUsingRecurr(root->right);
}

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

/**
 * Time: O(n), Space: O(n)
 * In the previous solution we can see that the left child is popped as soon as it is pushed to the stack, therefore it is not required to push it into the stack. 
 The idea is to start traversing the tree from the root node and keep printing the left child while exists and simultaneously, push the right child of every node in an auxiliary stack. Once we reach a null node, pop a right child from the auxiliary stack and repeat the process while the auxiliary stack is not empty. 
 */
void preorderUsingStackAndCurr (Node* root){
    if(root == nullptr) return;

    stack<Node*> st;
    Node* curr = root;

    while(!st.empty() || curr != nullptr) {
        while(curr != nullptr) {
            cout << curr->data<<" ";
            if(curr->right != nullptr)
                st.push(curr->right);
            curr = curr->left;
        }

        if(!st.empty()) {
            curr = st.top();
            st.pop();
        }
    }
}

/**
 * Pre Order Morris Traversal
 * Time: O(n), Space : O(1)
 */
void preorderMorrisTraversal(Node* root) {
    // NOT IMPLEMENTED
}

int main() {

    Node** nodes = createNodes(7);

    // Connect binary tree nodes
    nodes[0]->left = nodes[1];
    nodes[0]->right = nodes[2];
    nodes[1]->left = nodes[3];
    nodes[1]->right = nodes[4];
    nodes[4]->left = nodes[5];
    nodes[4]->right = nodes[6];

    cout << "Pre Order (using recurrsion) : "<<endl;
    preorderUsingRecurr(nodes[0]);
    cout << endl;
    
    cout << "Pre Order (using Stack) : "<<endl;
    preorderUsingStack(nodes[0]);
    cout << endl;
    
    cout << "Pre Order (using Stack + Current ptr) : "<<endl;
    preorderUsingStackAndCurr(nodes[0]);
    cout << endl;


}