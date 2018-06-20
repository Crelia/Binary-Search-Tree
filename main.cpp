#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

#include "bst.h"
#include "functions.h"

using namespace std;

int main () {
	ofstream out_s; //out file
	ifstream in_s; //in file

	bst b; //declaration of bst

	int choice = -1;
	int tmp, rem;

	while(choice != 0) {
		cout << "What do you want to do?\n";
		cout << " 0 - Quit\n 1 - Insert\n 2 - Print in-order\n 3 - Remove\n\n";
		cout << "Enter your selection: ";
		cin >> choice;

		switch (choice) {
			case 1: get_stream(in_s, out_s); //get instream file

				while(in_s >> tmp) { //while there is something to red

					//cout << endl << tmp << endl;
					//in_s >> tmp;
					b.insert(tmp); //insert  values into tree
				}

				in_s.close(); //close input file
				break;
			case 2: cout << endl;
				b.prt_inorder(); //print inorder list
				cout << endl << endl;
				break;
			case 3: cout << "Please enter what you want deleted: " << endl;
				cin >> rem;
				b.remove(rem); //remove given value
				break;
		}
	}

	return 0;
}
