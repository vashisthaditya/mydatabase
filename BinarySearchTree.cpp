#include<iostream>
#include<stdlib.h>
#include<queue>
//basic Node definition
struct Node
   {
       int data;
       Node* left;
       Node* right;
   };

//func to create new node
Node* newNode(int data)
{
  Node* newroot = new() Node;
  newroot->left = NULL;
  newroot->right = NULL;
  newroot->data = data;
  return newroot;
}
// func to insert new in Binary tree
Node* Insert(Node* root,int data)
{
  if(root==NULL)
    root=newNode(data);
  else if(data <= root->data)
    root->left=Insert(root->left,data);
  else
    root->right=Insert(root->right,data);
  return root;
}
//Func to search a node in tree
bool SearchNode(Node* root,int data)
{
  if(root == NULL )
    return false;
  else if(root->data == data){
    return true;
  }
  else if(data <= root->data) {
    return SearchNode(root->left,data);
  }
  else  {
    return SearchNode(root->right,data);
  }
}

int FindMin(Node* root)                 //to find minimum element in BST
{
  Node* curr = root;
  if(root == NULL){
    std::cout<<"Tree is Empty";
    return -1;
  }
  while(curr->left != NULL)
  {
    curr = curr->left;
  }return curr->data;
}

int FindMax(Node* root)                //to find minimum element in BST
{
  Node* curr = root;
  while(curr->right != NULL)
  {
    curr = curr->right;
  }return curr->data;
}

Node* LevelOrder(Node* root)                                //  This is Level Order Traversal of BST                                          
{                                                           // Here we are using STL so we have inlcuded queue template ,here we are using pointer to node Q                                                 
  std::queue<Node*> Q;                                                                      
  Q.push(root);                                                                                                  
  if(root == NULL)                                          //Initial condition        
    return 0;                                                                                                    
  Node* curr = root;
  std::cout<<"\nLevel Order Traversal of BST: ";                                                                                            
  while(!Q.empty()){                                                                                             
    curr = Q.front();                                                                                         
    std::cout<<" "<<curr->data;                                                                
    if(curr->left != NULL)                                                                                                       
      Q.push(curr->left);                                                                                                         
    if(curr->right != NULL)                                                                                                     
      Q.push(curr->right);                                                                                                 
    Q.pop();                                                //Deleting the elements from queue
  } 
}

Node* preOrder(Node* root)
{
  if(root == NULL)
    return 0;
  std::cout<<" "<<root->data;
  preOrder(root->left) ;
  preOrder(root->right);
}

Node* inOrder(Node* root)
{
  if(root == NULL)
    return 0;
  inOrder(root->left);
  std::cout<<" "<<root->data;
  inOrder(root->right);
}

Node* postOrder(Node* root)
{
  if(root == NULL)
    return 0;
  postOrder(root->left);
  postOrder(root->right);
  std::cout<<" "<<root->data;
}

Node* DeleteNode(Node* root ,int data)
{
  
  //base condition for recursion
  if(root == NULL)
    return root;
  
  else if(data < root->data){
    root->left = DeleteNode(root->left,data);
  }
  
  else if(data > root->data){
    root->right = DeleteNode(root->right,data);
  }
  
  else{
    //case 1: Node having no child
    if(root->left == NULL && root->right ==NULL)
    {
      delete root;
      root = NULL;
    }
    //case 2: Node Having one child
    else if(root->left == NULL){
      Node* temp = root;
      root = root->right;
      delete temp;
      temp = NULL;
    }
    //case 2: Node Having one child
    else if(root->right == NULL){
      Node* temp = root;
      root = root->left;
      delete temp;
      temp = NULL;
    }
    //Case 3: Node having two children
    else{
      Node* temp = root;
      temp->data  = FindMin(root->right);
      root->data  = temp->data;
      root->right = DeleteNode(root->right,temp->data);
    }
  
  }return root;
}

int main()
{
  
  Node* root = NULL;
  int del;
  root = Insert(root,10);
  root = Insert(root,15);
  root = Insert(root,20);
  root = Insert(root,9);
  root = Insert(root,4);
  root = Insert(root,13);
  root = Insert(root,11);
  
  int num,Minnum,Maxnum;
  std::cout<<"Enter Number to search[10,15,20,9,4,13,11]\n";
  std::cin>>num;
  if(SearchNode(root,num) == true){
    std::cout<<"Number Found.\n";
  }
  else{
    std::cout<<"Number not found!!Try Again...\n";
  }
  
  Minnum = FindMin(root);
  std::cout<<"Minimum element of BST is:"<<Minnum<<"\n";
  Maxnum = FindMax(root);
  std::cout<<"Maximum element of BST is:"<<Maxnum<<"\n";
  
  //Level Order Traversal Calling
  LevelOrder(root);
  std::cout<<"\nPre-order Traversal of BST is: ";
  
  //Pre Order Traversal Calling
  preOrder(root);
  std::cout<<"\nIn-order Traversal of BST is: ";
  
  //In Order Traversal Calling
  inOrder(root);
  std::cout<<"\nPost-order Traversal of BST is: ";
  
  //Post Order Traversal Calling
  postOrder(root);
  std::cout<<"\n\nEnter Number to Delete from BST: ";
  std::cin>>del;
  
  //Calling of Delete Function
  DeleteNode(root,del);
  std::cout<<"\nTree After Deletion: ";
  inOrder(root);
  return 0;
}
