#include <iostream>
#include <string>

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

int main() {

	while (1) {

		string str;
		getline(cin, str);
		
		int len = (int)str.length();
		Stack stack;
		bool flag = true;

		if (str[0] == '.')
			break;

		for (int i = 0; i < len; i++) {

			if (str[i] == '(')
				stack.push(str[i]);
			else if (str[i] == '[')
				stack.push(str[i]);
			else if (str[i] == ')') {
				if (!stack.empty() && stack.top() == '(') {
					stack.pop();
				}
				else {
					flag = false;
					break;
				}
			}

			else if (str[i] == ']') {
				if (!stack.empty() && stack.top() == '[') {
					stack.pop();
				}
				else {
					flag = false;
					break;
				}
			}
			
		}
		if (flag && stack.empty()) {
			cout << "yes" << endl;
		}
		else {
			cout << "no" << endl;
		}
	}

}