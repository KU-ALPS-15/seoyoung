#include <iostream>
#include <string.h>

using namespace std;
typedef char Data;

typedef struct Node {
	Data data;
	struct Node* next;
}node;


class Stack {
private:
	node* front;
public:

	Stack() {
		front = NULL;
	}
	bool empty() {
		return front == NULL;
	}
	void push(Data d) {

		node* temp = new node();
		temp->data = d;
		temp->next = front;

		front = temp;

	}

	void pop() {
		if (empty())
			return;

		Data num = front->data;
		front = front->next;


	}

	Data top() {
		if (empty())
			return -1;
		else {
			return front->data;
		}
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

};

bool check(string str) {
	Stack stack;
	int length = (int)str.length();
	for (int i = 0; i < length; i++) {
		char c = str[i];
		if (c == '(') {
			stack.push(str[i]);
		}
		else {
			if (!stack.empty()) {
				stack.pop();

			}
			else {
				return false;
			}
		}

	}
	return stack.empty();

}
int main() {

	int num;
	cin >> num;

	for (int i = 0; i < num; i++) {
		string str;
		cin >> str;
		
		if (check(str)) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
	return 0;
}