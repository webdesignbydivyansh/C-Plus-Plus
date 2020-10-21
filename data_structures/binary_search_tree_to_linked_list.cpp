//*This program demonstrates how to convert a binary search tree into a singly linked list.*//
#include<iostream>
#include<cassert>
using namespace std;

/*
	This class creates a new node every time
	it is called and assigns the the value of 
	data, left and right
*/
class node
{
	public:
		int data;	//the value of the root
		node*left,*right;	//left & right denotes the left and right part of the tree
		node(int d)
		{
			data=d;
			left=right=NULL;	
		}
};
/*
	This function creates a binary search tree
	***Note: The input must be of the form from root, left and then right
			 If a node is not present, then user must input -1
	For example if we want a binary search tree of the form
	5
	3 7		(this example is printed in bfs form)
	1 6 8
	then input should be : 5 3 1 -1 -1 -1 7 6 -1 -1 8 -1 -1
	***Note: The user must input a binary search tree
			 in order to get the correct output in sorted form.
*/ 
node*build()
{
	int d;					//variable to get the value of node of tree
	cin>>d;
	if(d==-1)
	return NULL;
	node*root=new node(d);
	root->left=build();		//call on left part of tree
	root->right=build();	//call on right part of tree
	return root;
}
/*
	This class will help in creating a linked list
*/
class linkedlist
{
	public:
		node*head,*tail; //Head and tail represent the head and tail of the linked list
						 
};
/*
	This function accepts the root node and converts
	the binary search tree in the form of linked list
*/
linkedlist flat(node*root)
{
	linkedlist l;
	if(root==NULL)
	{
		l.head=l.tail=NULL;
		return l;
	}
	if(root->left==NULL and root->right==NULL)
	{
		l.head=l.tail=root;
		return l;
	}
	if(root->left!=NULL and root->right==NULL)
	{
		linkedlist lll=flat(root->left);
		lll.tail->right=root;
		l.head=lll.head;
		l.tail=root;
		return l;
	}
	if(root->right!=NULL and root->left==NULL)
	{
		linkedlist llr=flat(root->right);
		root->right=llr.head;
		l.head=root;
		l.tail=llr.tail;
		return l;
	}
	linkedlist lll=flat(root->left);
	linkedlist llr=flat(root->right);
	lll.tail->right=root;
	root->right=llr.head;
	l.head=lll.head;
	l.tail=llr.tail;
	return l;
}
/*
	This function is used for testing
	sample test cases
*/
static void test()
{
	//*Example 1*//
	/*
		Example test case
		Input:
		5 3 1 7 6 8
		Output:
		1->3->5->6->7->8->NULL
	*/
	node*root=new node(5);
	root->left=new node(3);
	root->right=new node(7);
	root->left->left=new node(1);
	root->right->left=new node(6);
	root->right->right=new node(8);
	linkedlist l=flat(root);
	node*t=l.head;
	while(t!=NULL)
	{
		cout<<t->data<<"->";
		t=t->right;
	}
	cout<<"NULL"<<endl;
}
int main()
{
	test();
	node*root=build(); 			//It is a variable of type node
	linkedlist l=flat(root);	//Variable of type linked list
	node*temp=l.head;			//Temporary variable to store the head of linked list
	while(temp!=NULL)
	{
		cout<<temp->data<<"->";
		temp=temp->right;
	}
	cout<<"NULL";
	return 0;
}
