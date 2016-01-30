#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <string>
#include <iostream>
using namespace std;
extern "C" {
	#include "lexer.h"
}

class list {
private:
	class node {
	public:
		int line;
		string token_type_string;
		string token_value;
		node *next = NULL;
		node(int line, string token_type_string, string token_value) {
			this->token_type_string = token_type_string;
			this->line = line;
			this->token_value = token_value;
		}
		void print() {
			cout << line << " " << token_type_string << " " << token_value;
		}
	};
	node *root = NULL;
public:
	void insert(int line, string token_type_string, string token_value) {
		node *newNode = new node(line, token_type_string, token_value);
		if (root == NULL) {
			root = newNode;
		}	
		if (root != NULL) {
			newNode->next = root->next;
			root = newNode;
		}
	}	
	void print() {
		node *iterator;
		iterator = root;
		while (iterator != NULL) {
			iterator->print();
			cout << "\n";
		}
	}
};

int main() {
	string current_token;
	string token_type_string;
	list *linkedlist = new list();
	
	while (getToken() != END_OF_FILE) {
		if (t_type = NUM) {
			linkedlist->insert(line, "NUM", string(current_token));
		}	
		if (t_type = ID) {
			if (current_token == "cse340") {
				linkedlist->insert(line, "ID", string(current_token));	
			}
			if (current_token == "programming") {
				linkedlist->insert(line, "ID", string(current_token));
			}
			if (current_token == "language") {
				linkedlist->insert(line, "ID", string(current_token));	
			}
		}
	}
	linkedlist.print();
	return 0;
}
