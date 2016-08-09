

#include"stdafx.h"
List_insert* Copy_List(List_insert* head1) {
	List_insert* head = head1;
	if (head == NULL || head->next == NULL) return head;
	List_insert *res = new List_insert(0);
	List_insert *r = res;
	while (head)
	{
		List_insert *q = head->next;
		List_insert *temp = new List_insert(head->val);
		/*temp->next = res;
		res = temp;*/
		res->next=temp;
		res = temp;
		head = q;
	}
	List_insert *result = r->next;
	free(r);
	return result;
}