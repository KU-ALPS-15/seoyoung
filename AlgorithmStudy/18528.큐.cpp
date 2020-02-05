#include <iostream>
#include <string>

using namespace std;

typedef struct Node {
	int data;
	struct Node* next;
}node;

class Queue {
private:
	node* front;
	node* rear;

public:
	Queue() {
		front = rear = NULL;
	}
	bool empty() {
		return front == NULL;
	}
	void enqueue(int d) {

		node* temp = new node();
		temp->data = d;
		temp->next = NULL;

		if (empty()) {
			front = rear = temp;
			return;
		}
		rear->next = temp;
		rear = temp;
	}

	int dequeue() {

		if (empty())
			return -1;

		int data = front->data;
		front = front->next;
		return data;

	}
	int size() {
		int count = 1;
		if (empty()) {
			return 0;
		}
		node* ptr = front;
		while (ptr->next != NULL) {

			ptr = ptr->next;
			count++;
		}
		return count;
	}
	int frontq() {
		return front->data;
	}

};


int main() {
	int n, k;
	cin >> n >> k;

	Queue queue;

	for (int i = 1; i <= n; i++) {
		queue.enqueue(i);
	}
	cout << "<";

	while (!queue.empty()) {
		for (int i = 1; i < k; i++) {
			queue.enqueue(queue.frontq());
			queue.dequeue();
		}
		cout << queue.frontq();
		queue.dequeue();

		if (!queue.empty())
			cout << ",";
	}
	cout << ">";

}