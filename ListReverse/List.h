#pragma once
#include <stddef.h>
#include <iostream>

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

void PrintList(ListNode* head)
{
	ListNode* temp = head;
	while (temp != NULL)
	{
		std::cout << temp->val << " ";
		temp = temp->next;
	}
}

class Solution {
public:
	ListNode* reverseList1(ListNode* head) {
		ListNode* start = NULL, * temp = head;
		while (temp != NULL)
		{
			ListNode* node = new ListNode(temp->val);
			node->next = start;
			start = node;
			temp = temp->next;
		}
		return start;
	}
	ListNode* reverseList2(ListNode* head) {
		if (head != NULL && head->next != NULL)
		{
			ListNode* node = reverseList2(head->next), *temp = node;
			if (node->next == NULL)
				node->next = head;
			head->next->next = head;
			head->next = NULL;
			return node;
		}
		else
			return new ListNode(head->val);
	}
};

