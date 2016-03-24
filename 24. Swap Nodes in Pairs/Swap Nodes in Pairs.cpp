#include<iostream>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

void printLList(const ListNode *list) {
	while(list) {
		cout << list->val << ' ';
		list = list->next;
	}
	cout << endl;
}

ListNode* generateLLsit(int *array, int size){
	ListNode *head = new ListNode(array[0]);
	ListNode *pre = head;
	int cur = 1;
	while(cur < size) {
		pre->next = new ListNode(array[cur]);
		pre = pre->next;
		cur++;
	}
	return head;
}

class Solution{
public:
	ListNode* swapPairs(ListNode* head) {
		if (!head) return head;
		ListNode *newhead = new ListNode(0);
		newhead->next = head;
		ListNode *left = head, *pre = newhead;
		while(left && left->next) {
			ListNode *right = left->next;
			left->next = right->next;
			right->next = left;
			pre->next = right;
            
			pre = left;
			left = left->next;
		}
		return newhead->next;
	}
};

int main() {
	int array[] = {1,2,3,4};
	ListNode *list = generateLLsit(array, 4);
	Solution sol;
	printLList(sol.swapPairs(list));
	
	system("pause");
	return 0;
	
}
