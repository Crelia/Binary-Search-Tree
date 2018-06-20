#include <iostream>
#include <cstdlib>
#include "bst.h"

using namespace std;

bst::bst() {
	root = NULL;
}

void bst::insert(int x) {
	node* n = new node; //new node in tree
	node* parent; //parent node

	n->val = x; //set value equal to value given
	n->left = NULL;
	n->right = NULL;
	parent = NULL;//set rest null

	if(root == NULL) {//if root is empty
		root = n;//set node to root
	}
	else {
		node* current; //current node
		current = root; //set to root


		while(current) {//while not null
			parent = current;//parent is the current value

			if(n->val == current->val) {//if equal there is a duplicate
				cout << n->val << " appears multiple times\n\n";
				remove(n->val);//remove duplicate

				break; //break from loop
			}

			if(n->val > current->val) {//if new node is bigger than current node
				current = current->right;//set current node to right sibling;
			}
			else {

				current = current->left;//otherwise set to left sibling
			}
		}

		if(n->val == parent->val) {//if values are equal
			remove(n->val);//remove the duplicate
		}

		if(n->val < parent->val) {//if the value is smaller than the parents
			parent->left = n;//set to left node
		}
		else {
			parent->right = n;//otherwise set to right
		}
	}

}

void bst::remove(int x) {
	bool found = false;

	if(checkEmp()) {//if tree exists
		cout << "The tree does not exist" << endl;
		return;
	}

	node* current;//current node
	node* parent;//parent node
	current = root;//set current to root

	while(current != NULL) {//while current is valid
		if(current->val = x) {//if it is the given value
			found = true;//change bool value
			break;
		}
		else {
			parent = current;//get next
			if(x > current->val) {//if value is greater than
				current = current->right;//go rigth
			}
			else {
				current = current->left;//otherwise go left
			}
		}
	}

	if(!found) {//if no value is found
		cout << "No data found" << endl;
		return;
	}

	if((current->left == NULL && current->right != NULL) || (current->left != NULL && current->right == NULL)) {//if both siblings are null or only right is null
		if(current->left == NULL && current->right != NULL) {//if left is null and right is not
			if(parent->left == current) {//if nodes are equal
				parent->left = current->right;//set parent equal to right current
				delete current;//delet current
			}
			else {
				parent->right = current->right;//otherwise do opposite;
				delete current;
			}
		}
		else {
			if(parent->left == current) {//if  nodes are equal
				parent->left = current->left;//set left to current
				delete current;
			}
			else {//otherwise do opposite
				parent->right = current->left;
				delete current;
			}
		}

		return;//leave

	}

	if(current->left == NULL && current->right == NULL) { //if left is null and right is null
		if(parent->left == current) {//if parent->left is the same as current
			parent->left = NULL;//set = nULL
		}
		else {
			parent->right = NULL;//otherwise set right to null
		}
		delete current;
		return;
	}

	if(current->left != NULL && current->right != NULL) {//if left and right are not null
		node* check;//check node
		check = current->right;//right sibling

		if((check->left == NULL) && (check->right == NULL)) {//if left and right are null
			current = check;//set equal
			delete check;
			current->right = NULL;//set right null
		}
		else {
			if((current->right)->left != NULL) {//if right nodes left is not null
				node* currenta;
				node* currentb;

				currentb = current->right;//placeholder
				currenta = (current->right)->left;//placeholder

				while(currenta->left != NULL) {//while there is still a ndoe
					currentb = currenta;//sqithc
					currenta = currenta->left;
				}
				current->val = currenta->val;//set equal
				delete currenta;
				currentb->left = NULL;//sert left node to null
			}
			else {
				node* temp;
				temp = current->right;
				current->val = temp->val;
				current->right = temp->right;
				delete temp;
			}
		}
		return;
	}
}

void bst::inorder(node* x) {
	if(x != NULL) {//while there is a value
		if(x->left) {
			inorder(x->left);//run inorder on lef tnode
		}
		cout << endl << x->val;//print
		if(x->right) {
			inorder(x->right);//run inorder on right node
		}
	}

	else return;

}

void bst::prt_inorder() {
	inorder(root);//run inorder
}
