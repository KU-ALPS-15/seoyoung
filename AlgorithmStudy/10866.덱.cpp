#include<iostream>
#include <string>

using namespace std;

typedef struct Node {
	int data;
	struct Node* next;
	struct Node* prev;
}node;

class Deque {
private:
	node* front;
	node* rear;


public:
	Deque() {
		front = rear = NULL;
	}
	bool empty() {
		return front == NULL;
	}

	void push_front(int x) {
		node* temp = new node();
		temp->next = NULL;
		temp->prev = NULL;
		temp->data = x;

		if (empty()) {
			front = rear = temp;
			return;
		}
		else {
			temp->next = front;
			front->prev = temp;
			temp->prev = NULL;
			front = temp;
		}
	}
	void push_back(int x) {
		node* temp = new node();
		temp->next = NULL;
		temp->prev = NULL;
		temp->data = x;

		if (empty()) {
			front = rear = temp;
			return;
		}
		else {
			temp->prev = rear;
			rear->next = temp;
			temp->next = NULL;
			rear = temp;
		}

	}
	int pop_front() {

		if (empty())
			return -1;

		int data = front->data;
		front = front->next;

		if (front == NULL) {
			rear = NULL;
		}
		else {
			front->prev = NULL;
		}
		return data;
	}

	int pop_back() {
		if (empty())
			return -1;

		int data = rear->data;
		rear = rear->prev;


		if (rear == NULL) {
			front = NULL;
		}
		else {
			rear->next = NULL;
		}
		return data;
	}
	int size() {
		int count = 1;
		if (empty())
			return 0;

		node* ptr = front;
		while (ptr->next != NULL) {
			ptr = ptr->next;
			count++;
		}
		return count;
	}

	int frontp() {
		if (empty()) {
			return -1;
		}
		return front->data;
	}
	int backp() {
		if (empty()) {
			return -1;
		}
		return rear->data;
	}
};

int main() {
	int num;
	cin >> num;

	Deque deque;
	string str;

	for (int i = 0; i < num; i++) {
		cin >> str;

		if (str == "push_back") {
			int n;
			cin >> n;
			deque.push_back(n);
		}
		else if (str == "push_front") {
			int n;
			cin >> n;
			deque.push_front(n);
		}
		else if (str == "pop_front") {
			cout << deque.pop_front() << '\n';
		}
		else if (str == "pop_back") {
			cout << deque.pop_back() << '\n';
		}
		else if (str == "size") {
			cout << deque.size() << '\n';
		}
		else if (str == "empty")
			cout << deque.empty() << '\n';
		else if (str == "front") {
			cout << deque.frontp() << '\n';
		}
		else if (str == "back") {
			cout << deque.backp() << '\n';
		}
	}
}