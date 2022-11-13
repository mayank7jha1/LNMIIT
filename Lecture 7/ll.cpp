#include<bits/stdc++.h>
using namespace std;

class node {
public:
	int  data;
	node* next;//Self referencing pointer
	//Constructor
	node(int inputdata) {
		data = inputdata;
		next = NULL;
	}
};


void InsertAtHead(node* &head, int value) {
	node* n = new node(value);
	n->next = head;
	head = n;
}


void InsertAtTail(node* &head, int value) {
	if (head == NULL) {
		head = new node(value);
		return;
	}

	node* temp = head;

	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = new node(value);
	return;
}


int length(node* head) {
	node* temp = head;
	int count = 0;
	while (temp != NULL) {
		temp = temp->next;
		count++;
	}
	return count;
}

node* midPoint1(node* head) {
	int mid = length(head) / 2;//O(n)
	node* temp = head;
	while (mid > 0) {
		temp = temp->next;//O(mid)
		mid--;
	}
	return temp;

	//Iteration 2 times: O(2n):==O(n+mid);===O(n)
	//Single iteration
}

node* midPoint2(node* head) {
	node* slow = head;
	node* fast = head;//This gives you first mid point in the case of even LL.
//	node* fast = head->next;//This gives you second mid point
	while (fast != NULL and fast->next != NULL) {
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}


bool searchIterative(node* head, int x) {
	node* temp = head;
	while (temp != NULL) {
		if (temp->data == x) {
			return true;
		}
		temp = temp->next;
	}
	return false;
}


bool searchRecursive(node* head, int x) {
	node* temp = head;
	//Base case:
	if (temp == NULL) {
		return false;
	}


	//Task Kya karna hain:

	if (temp->data == x) {
		return true;
	} else {
		return searchRecursive(head->next, x);
	}

}


void ReverseLL(node* &head) {
	node* current = head;
	node* prev = NULL;
	node* n;
	while (current != NULL) {
		n = current->next;
		current->next = prev;
		prev = current;
		current = n;
	}
	//Current is NULL, prev is last element and n obviously doesn't exist
	head = prev;
}
node* reverseLink_List(node* &head) {
	//Base Case:

	if (head == NULL or head->next == NULL) {
		return head;
	}

	node* next_head = reverseLink_List(head->next);

	node* current = head;
	current->next->next = current;
	current->next = NULL;

	return next_head;
}


void cycle_creation(node* head) {
	node* temp = head;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = head->next->next->next;
}

bool iscycle(node* head) {
	node* fast = head;
	node* slow = head;

	while (fast != NULL and fast->next != NULL) {
		fast = fast->next->next;
		slow = slow->next;
		if (slow == fast) {
			return true;
		}
	}
	return false;
}

void break_cycle(node* head) {
	//Step 1: Find the meeting point
	node* fast = head;
	node* slow = head;

	while (fast != NULL and fast->next != NULL) {
		fast = fast->next->next;
		slow = slow->next;
		if (slow == fast) {
			break;
		}
	}

	//At this point slow and fast are pointing
	//to the same point.

	//Step 2: Put slow at head and create
	//a new pointer prev which will point to
	//the prev element of fast.

	slow = head;
	node* prev = head;
	while (prev->next != fast) {
		prev = prev->next;
	}

	//Now fast is at meeting point,
	//prev is at one element before fast and
	// slow is at head.

	//Step 3:MOve all three of them one step
	//at a time and whenever fast and s
	//slow meets prev will be at the last element.

	while (slow != fast) {
		slow = slow->next;
		fast = fast->next;
		prev = prev->next;
	}

	// cout << slow->data << endl; Origin of cycle
	prev->next = NULL;
}
void print(node* &head) {
	node* temp = head;

	while (temp != NULL) {
		cout << temp->data << " -> ";
		temp = temp->next;
	}
	cout << "NULL" << endl;
}



int main() {
	node* head = NULL;
	node* head1 = NULL;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		InsertAtHead(head, x);
		InsertAtTail(head1, x);
	}
	// print(head);
	// print(head1);
	// print(head);

	// cout << length(head) << " " << length(head1) << endl;
	// node* p = midPoint1(head1);
	// cout << p->data << endl;

	// node* s = midPoint2(head);
	// cout << s->data << endl;
	// cout << searchIterative(head, 5) << endl;
	// cout << searchRecursive(head1, 15) << endl;
	// print(head1);
	// ReverseLL(head1);
	// print(head1);

	// node* head2 = reverseLink_List(head1);
	// print(head2);
	cout << iscycle(head1) << endl;
	cycle_creation(head1);
	cout << iscycle(head1) << endl;
	break_cycle(head1);
	cout << iscycle(head1) << endl;
}


//Kth node from the end.
//You have to find this in single iteration.