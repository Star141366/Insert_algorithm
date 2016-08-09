#pragma once
class List_insert {
	public:
		int val;
		List_insert *next;
		List_insert(int val) {
			this->val = val;
			this->next = NULL;
			
		}
		~List_insert();
};

