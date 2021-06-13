/*
This Program is Binary search tree implemenation with following operations:
1.Insert
2.Delete
3.Invert Tree
4.Pre/Post/In Order Traversal

*/


#include<bits/stdc++.h>
#include "BSTheader.h"

using namespace std;

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

//Shows Number of childrens nodes for all nodes
void NumofChildNodes(struct BST* root){
    if(root!=NULL){
        cout << "For Node: " << root->val << " Number of childrens are: " << root->NumChild << ":" << root << endl;
        NumofChildNodes(root->left);
        NumofChildNodes(root->right);
    }
}

int main(){
    int size,key,IVTflag=0;
    cout << "Enter N: " << endl;
    cin >> size;
    struct BST* root = NULL;
    cout << " Enter N numbers with space between: " << endl;
    for(int i=0;i<size;i++){
        cin >> key;
        root = insert(root,key,IVTflag);
   }
   int opt,flag=1,ele;
   while(flag){
   cout << "\nSelect Operation \n 1.Insert Number \n 2.Delete Number \n 3.InOrder Traversal \n 4.PostOrder Traversal \n 5.PreOrder Traversal \n 6.Invert Tree \n 7.Exit Program \n";
   cin >> opt;
   switch(opt){
   case 1 : 	cout << " Enter Element to be inserted : \n";
   		cin >> ele;
   		root = insert(root,ele,IVTflag);
		cout << ele << " is inserted\n";
		break;
   case 2 : 	cout << "Enter element to be deleted : \n";
		cin >> ele;
   		root = DeleteNode(root,ele);
		cout << ele << " is deleted\n";
		break;
   case 3 :	cout << "InOrder Traversal is : ";
		order(root,opt);
   		break;
   case 4 :	cout << "PostOrder Traversal is : ";
		order(root,opt);
   		break;
   case 5 :	cout << "PreOrder Traversal is : ";
		order(root,opt);
   		break;
   case 6 :	if(IVTflag==0){IVTflag=1;}else{IVTflag=0;}
   		root = IVT(root);
   		cout << "Tree is Inverted, Check InOrder Traversal for confirmation\t It should print sorted output(decreasing)\n";
   		break;
   case 7 :	flag = 0;
   		break;
   default :    flag = 0;
   }
   }
    return 0; 
   }
