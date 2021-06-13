//#include<bits/stdc++.h>
//using namespace std;

struct BST *newNode(int item);
struct BST *insert(struct BST *node, int key,int flag);
void order(struct BST* head,int opt);
void NumofChildNodes(struct BST* root);
struct BST* getlast(struct BST* root);
struct BST* DeleteNode(struct BST* root, int data);
struct BST* IVT(struct BST* root);

//BST structure definition
struct BST{
    int val;
    struct BST *left;
    struct BST *right;
    //struct BST *up;
    int NumChild;
};

//Create a Newnode
struct BST *newNode(int item) {
  struct BST *temp = (struct BST *)malloc(sizeof(struct BST));
  temp->val = item;
  temp->left = temp->right = NULL;
  temp->NumChild = 0;
  return temp;
}

//To Insert a element to BST
struct BST *insert(struct BST *node, int key,int flag) {
  // Return a new node if the node is empty
  if (node == NULL) return newNode(key);

  // Traverse to the right place and insert the node
  if(!flag){
  if (key < node->val){
    node->left = insert(node->left, key,flag);
    node->NumChild = node->NumChild+1;
  }
  else{
    node->right = insert(node->right, key,flag);
    node->NumChild = node->NumChild+1;
  }
}else{
if (key < node->val){
    node->right = insert(node->right, key, flag);
    node->NumChild = node->NumChild+1;
  }
  else{
    node->left = insert(node->left, key, flag);
    node->NumChild = node->NumChild+1;
  }
}
  return node;
}
/*
//Gives Pre/Post/In - Order Traversal
void order(struct BST* head,int opt){
    
    if(head!=NULL){
    	if(opt == 5){
        cout << head->val << " "; //Pre order traversal
	}
        order(head->left,opt);
        if(opt == 3){
	cout << head->val << " "; // In Order traversal
        }
	order(head->right,opt);
        if(opt == 4){
	cout << head->val << " "; // Post Order traversal    
	}
	}
}
*/

//Shows Number of childrens nodes for all nodes
/*
void NumofChildNodes(struct BST* root){
    if(root!=NULL){
        cout << "For Node: " << root->val << " Number of childrens are: " << root->NumChild << ":" << root << endl;
        NumofChildNodes(root->left);
        NumofChildNodes(root->right);
    }
}
*/

//To get address of left most node
struct BST* getlast(struct BST* root){
while(root->left!=NULL){
    root = root->left;
}
return root;
}

//Delete a node from Binary Search tree
struct BST* DeleteNode(struct BST* root, int data){
    if(root->val == data){
        if(root->right == NULL && root->left == NULL){root = NULL;return root;}
        if(root->right){
        struct BST* t = getlast(root->right);
        struct BST* t1 = root->left;
        root = root->right;
        t->left = t1;
        return root;
        }
        root = root->left;
        return root;
    }
    else if(data > root->val){
        root->right = DeleteNode(root->right,data);
    }else{
        root->left = DeleteNode(root->left,data);
    }
    return root;
}

//Binary Tree Inversion Function
struct BST* IVT(struct BST* root){
	if(root!=NULL){
	   root->left = IVT(root->left);				
	   root->right = IVT(root->right);				
	if(root->left!=NULL || root->right!=NULL){
	if(root->left==NULL){
	   struct BST* t = root->left;
	   root->left = root->right;
	   root->right = t;
	   return root;
	}else if(root->right==NULL){
	   struct BST* t = root->right;
	   root->right = root->left;
	   root->left = t;
	   return root;
	}
	struct BST* t = root->left;
	root->left = root->right;
	root->right = t;
	return root;
	}
	}
	return root;
}

