#include <iostream>


struct ListNode {


	ListNode* next;
	int data;

	ListNode(int val = 0) {
		next = nullptr;
		data = val;
	}

};

int main() {

	ListNode* LinkedList = new ListNode(10);
	LinkedList->next = new ListNode(30);
	LinkedList->next->next = new ListNode(20);


	


}.
