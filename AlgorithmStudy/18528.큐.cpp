#include <iostream>
#include <string>

using namespace std;

typedef char Data;

typedef struct Node {
	Data data;
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
	void enqueue(Data d) {

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

		int dedata = front->data;
		front = front->next;
		return dedata;

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
	Data frontq() { //먼저나올애
		if (empty())
			return -1;

		return front->data;
	}
	Data backq() {// 
		if (empty())
			return -1;

		return rear->data;
	}

};


int main() {

	int num;
	cin >> num;

	Queue queue;
	string str;

	for (int i = 0; i < num; i++) {
		cin >> str;

		if (str == "push") {
			int n;
			cin >> n;
			queue.enqueue(n);
		}
		else if (str == "pop") {
			cout << queue.dequeue() << '\n';
		}
		else if (str == "front") {
			cout<<queue.frontq()<< '\n';
		}
		else if (str == "back") {
			cout<<queue.backq()<< '\n';
		}
		else if (str == "empty")
			cout << queue.empty() << '\n';
		else if (str == "size")
			cout<<queue.size()<< '\n';
	}

}
