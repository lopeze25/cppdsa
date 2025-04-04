#include <iostream>
#include <vector>
#include <queue>
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

	void BFS() {
		std::queue<Node*> q;
		q.push(this);

		while (!q.empty()) {
			Node* current = q.front();
			q.pop();
			std::cout << current->data << " ";  

			for (Node* child : current->children) {
				q.push(child);
			}
		}
		std::cout << std::endl; 
	}
	// dfs = stack
	void DFS() {
		std::stack<Node*> s;
		s.push(this);

		while (!s.empty()) {
			Node* current = s.top();
			s.pop();
			std::cout << current->data << " "; 

			// Push children onto the stack
		}
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


	head->BFS(); 

	//prevent memory leaks

	delete node3;  
	delete node2;  
	delete node1;  
	delete head;  

}



