#ifndef bst_h
#define bst_h

#include <iostream>
#include <cstdlib>

using namespace std;

class bst {
	private:
		struct node {
			node* left; //left sibling
			node* right;//right sibling
			int val; //value of node
		};
		node* root;
	public:
		bst();
		bool checkEmp() const {return root == NULL;}
		void inorder(node*);
		void prt_inorder();
		void insert(int);
		void remove(int);
};

#endif /*bst_h*/
