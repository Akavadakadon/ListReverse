#include "List.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

string ReadLine() {
    string s;
    getline(cin, s);
    return s;
}
vector<int> SplitIntoInts(const string& text) {
    vector<int> vals;
    string val;
    stringstream ss(text);
    int numbersuka;
    while (getline(ss, val, ' ')) {
        istringstream tmp(val);
        if (tmp >> numbersuka)
            vals.push_back(numbersuka);
    }

    return vals;
}
ListNode* MakeList(vector<int> nums)
{
    ListNode* head = NULL, * temp = head;
    for (int val : nums)
    {
        ListNode* next = new ListNode(val);
        if (head == NULL)
            temp = head = next;
        temp->next = next;
        temp = next;
    }
    return head;
}
int main()
{
    string input = "123 asd 312   321 2 ! dad 32 "; //ReadLine();
    Solution sln;
    vector<int> nums = SplitIntoInts(input);
    ListNode* head = MakeList(nums), * revers1, * revers2;
    cout << "orig: ";
    PrintList(head);
    cout << endl;
    revers1 = sln.reverseList1(head);
    cout << "reverseList1: ";
    PrintList(revers1);
    cout << endl;
    revers2 = sln.reverseList2(head);
    cout << "reverseList2: ";
    PrintList(revers2);
    cout << endl;
    PrintList(sln.reverseList2(head));
}

