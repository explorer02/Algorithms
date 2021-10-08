#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node *left,*right;
    Node(int data){
        this -> data = data;
        left=right=NULL;
    }
};

Node* insert(Node*root,int data)
{
    if(root==NULL)
        return new Node(data);
    if(root->data>data)
        root->left=insert(root->left,data);
    if(root->data<data)
        root->right=insert(root->right,data);
    return root;
}

void inorder(Node*root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
/*
int height(Node*root)
{
    if(root==NULL)
        return 0;
    return max(height(root->left),height(root->right))+1;
}
*/

int Height(Node*root)
{
    int height=0;
    if(root->left!=NULL)
    {
        height=1+Height(root->left);
    }
    if(root->right!=NULL)
    {
        if(height<Height(root->right)+1)
            height=Height(root->right)+1;
    }
    return height;
}

void print(Node*root)
{
    if(root==NULL)
        return;
    queue<Node*>Q;
    Q.push(root);
    Q.push(NULL);
    int L=Height(root);
    int mspc=0;
    int fspc=pow(2,L)-1;
    Node*Null=new Node(100);
    for(int i=1;i<=fspc;i++)
        cout<<" ";
    while(L>=0)
    {
        Node*temp=Q.front();
        Q.pop();
        if(temp!=Null&&temp->left!=NULL)
            Q.push(temp->left);
        else
        {
            Q.push(Null);
        }
        if(temp!=Null&&temp->right!=NULL)
            Q.push(temp->right);
        else
        {
            Q.push(Null);
        }
        if(temp!=Null)
            cout<<temp->data;
        else
        {
            cout<<" ";
        }
        for(int i=1;i<=mspc;i++)
        {
            cout<<" ";
        }
        if(Q.front()==NULL)
        {
            Q.pop();
            Q.push(NULL);
            cout<<endl;
            L--;
            mspc=fspc;
            fspc=pow(2,L)-1;
            for(int i=1;i<=fspc;i++)
            {
                cout<<" ";
            }
        }
    }
}



Node*leftmost(Node*root)
{
    if(root==NULL||root->left==NULL)
        return root;
    return leftmost(root->left);

}
Node*returnParent(Node*root,int data){
    if(root==NULL)
        return NULL;
    if(root->left!=NULL&&root->left->data==data)
        return root;
    if(root->right!=NULL&&root->right->data==data)
        return root;
    Node*l=returnParent(root->left,data);
    Node*r=returnParent(root->right,data);
    return (l==NULL)?r:l;
}
Node*returnNode(Node*root,int data){
    if(root==NULL)
        return NULL;
    if(root->data==data)
        return root;
    Node*l=returnNode(root->left,data);
    Node*r=returnNode(root->right,data);
    return (l==NULL)?r:l;
}

Node* deleteNode(Node* root, int data)
{
    Node*curr=returnNode(root,data);
    Node*par=returnParent(root,data);
    if(curr==NULL)
        return root;
    //case 1
    if(curr->left==NULL&&curr->right==NULL){
            if(curr==root)
            return NULL;
        if(curr->data<par->data)
            par->left=NULL;
        else par->right=NULL;
        return root;
    }
    //case 2
    if((curr->left!=NULL&&curr->right==NULL)||(curr->right!=NULL&&curr->left==NULL)){

        Node*child=(curr->left==NULL)?curr->right:curr->left;
        if(curr->data<par->data)
            par->left=child;
        else par->right=child;
        return root;
    }
    //case 3
    Node*succ=leftmost(curr->right);
    int val=succ->data;
    succ->data=curr->data;
    curr->data=val;
    return deleteNode(root,data);

}

int main()
{
    Node*root=NULL;
    int choice;

    cout<<"1. Insert Node in BST\n";
    cout<<"2. Delete Node from BST\n";
    cout<<"3. Inorder traversal of BST\n";
    cout<<"4. Lever Order traversal of BST\n";
    cout<<"Enter Choice  ";
    cin>>choice;
    while(choice>0&&choice<5)
    {
        switch(choice)
        {
            case 1:
                int x;
                cout<<"Enter value to insert ";
                cin>>x;
                root=insert(root,x);
                break;
            case 2:
                cout<<"Enter value to delete ";
                cin>>x;
                root=deleteNode(root,x);
                break;
            case 3:
                inorder(root);
                cout<<endl;
                break;
            case 4:
                print(root);
                break;

        }
        cout<<"Enter Choice  ";
        cin>>choice;
    }
}
