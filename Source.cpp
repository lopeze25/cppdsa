#include <iostream>
#include <vector>
/* 
struct Node {
	int data;
	Node* next;
	Node(int val) {
		data = val;
		next = nullptr;
	}


};


int main() {

	Node* head = new Node(20);
	head->next


}
*/

// A N-ary tree
struct Node {
	int data;
	std::vector<Node*> children; 
	
	Node(int val) {
		data = val; 
	}
};

// A single linked list 
struct ListNode {
	int data;
	ListNode* next;
	ListNode(int val = 0) { data = val, next = nullptr; }
};

int main() {

	// Create nodes
	ListNode* LinkedList = new ListNode(10);         
	LinkedList->next = new ListNode(20);           
	LinkedList->next->next = new ListNode(30);      

	ListNode* current = LinkedList; 

	Node* head = new Node(20);
	Node* node1 = new Node(30); 

	head->children.push_back(node1); 

	Node* node2 = new Node(40);
	node1->children.push_back(node2);

	Node* node3 = new Node(50);
	node1->children.push_back(node3);

	while (current != nullptr) {
		current = current->next;
	
	}

}


