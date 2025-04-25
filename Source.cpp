#include <iostream>
#include <vector>


struct LinkedNode {

	int data;
	LinkedNode* next;
	LinkedNode(int val = 0) {
		this->data = val;
		next = nullptr;
	}
};

int main() {

	LinkedNode* head = new LinkedNode(10);
	head->next = new LinkedNode(20);
	head->next->next = new LinkedNode(30);
	LinkedNode* current = head; 

	std::vector<int> values; 

	while (current != nullptr) {
		values.push_back(current->data);
		current = current->next; 
	}
	std::vector<int> format; 
	for (int val : values) {

		std::cout << val; 
		int data = values.back();
		values.pop_back();
		format.push_back(data); 

	}


	return 0; 

	}

