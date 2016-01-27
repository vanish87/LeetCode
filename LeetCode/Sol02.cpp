/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		if (l1 == NULL)return l2;
		if (l2 == NULL)return l1;

		ListNode* Ret = new ListNode(0);
		ListNode* CurrentRet = Ret;
		int Shift = 0;
		while (true)
		{
			while (Shift > 0)
			{
				CurrentRet->val++;
				Shift--;
			}
			CurrentRet->val += l1->val + l2->val;
			while (CurrentRet->val >= 10)
			{
				CurrentRet->val -= 10;
				Shift++;
			}
			if (l1->next != NULL && l2->next != NULL)
			{
				CurrentRet->next = new ListNode(0);
				CurrentRet = CurrentRet->next;
				l1 = l1->next;
				l2 = l2->next;
			}
			else
			{
				break;
			}
		}
		if (l1->next != NULL) CurrentRet->next = l1->next;
		if (l2->next != NULL) CurrentRet->next = l2->next;

		while (Shift-- > 0)
		{
			if (CurrentRet->next == NULL)
			{
				CurrentRet->next = new ListNode(0);
			}
			CurrentRet = CurrentRet->next;
			CurrentRet->val++;
			while (CurrentRet->val >= 10)
			{
				CurrentRet->val -= 10;
				Shift++;
			}
		}

		return Ret;
	}
};

public class Solution {
	public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
		ListNode c1 = l1;
		ListNode c2 = l2;
		ListNode sentinel = new ListNode(0);
		ListNode d = sentinel;
		int sum = 0;
		while (c1 != null || c2 != null) {
			sum /= 10;
			if (c1 != null) {
				sum += c1.val;
				c1 = c1.next;
			}
			if (c2 != null) {
				sum += c2.val;
				c2 = c2.next;
			}
			d.next = new ListNode(sum % 10);
			d = d.next;
		}
		if (sum / 10 == 1)
			d.next = new ListNode(1);
		return sentinel.next;
	}
}