/*
Node is defined as 

typedef struct node
{
   int data;
   node *left;
   node *right;
   
}node;

*/
//O(n) solution

bool dfs(node* root, int val){
    if(root == NULL) return false;
    if(root->data == val) return true;
    else if(dfs(root->left, val)) return true;
    else return dfs(root->right, val);
}
node *lca(node *root, int v1,int v2)
{
    stack<node*> stack;
    node* fork;
    node* current = root;
    while(current->data != v1 &&
          current->data != v2){
        if(current==NULL){
            if(stack.top()->right != NULL){
                current = stack.top()->right;
            }
            stack.pop();
        }
        else{
            stack.push(current);
            current = current->left;
        }
    }
                     
    int otherVal = (current->data == v1) ? v2 : v1;
    if(current->left != NULL){
        if (dfs(current->left, otherVal)) return current; 
    }
    if(current->right != NULL){
        if (dfs(current->right, otherVal)) return current;
    }
    while(!stack.empty()){
        fork = stack.top();
        if(current == fork->left && dfs(fork->right, otherVal)) return fork;
        if(current == fork->right && dfs(fork->left, otherVal)) return fork;
        current = stack.top();
        stack.pop();
    }
    return NULL;
}