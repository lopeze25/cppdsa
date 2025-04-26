
#include <vector>


struct LinkedList {

	int data;
	LinkedList* next;
	LinkedList (int value = 0) {
		this->data = value;
		next = nullptr;
	}

};

struct Node {
	int data;
	std::vector<Node*> children; 
	Node(int val) {
		data = val;
	}

};