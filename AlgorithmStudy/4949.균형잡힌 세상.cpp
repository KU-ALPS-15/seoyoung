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
		return (front == NULL && rear==NULL);
	}
	void enqueue(Data d) {
	
		node* temp = new node();
		temp->data = d;
		temp->next = NULL;
	
		if (empty()) {
			front = back=temp;
			return;
		}
		rear->next = temp;
		rear = temp;
	}
	Data dequeue() {
		
		if (empty())
			return -1;

		node* temp = front;

		front = front->next;
		free(temp);

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
	Data front() { //먼저나올애
		if (empty())
			return -1;

		return front->data;
	}
	Data back() {// 
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
			print("%d\n", queue.dequeue());
		}
		else if (str == "front") {
			printf("%d\n", queue.back());
		}
		else if (str == "back") {
			printf("%d\n", queue.front());
		}
		else if (str == "empty")
			printf("%d\n", queue.empty());
		else if (str == "size")
			printf("%d\n", queue.size());
	}

}