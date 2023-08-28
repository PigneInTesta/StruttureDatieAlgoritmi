#include "concatena.h"
#include "list.h"

Item* Concatena(Item* i1, Item* i2, enum ConcType c) {
	if (ListIsEmpty(i1) && ListIsEmpty(i2)) {
		return ListCreateEmpty();
	} else if (ListIsEmpty(i1) && c == kNoCopy) {
		return i2;
	}

	Item* res = ListCreateEmpty();
	Item fake_head = { .next = i1 };

	if (c == kCopy) {
		while (!ListIsEmpty(i1)) {
			res = ListInsertBack(res, ListGetHeadValue(i1));
			i1 = ListGetTail(i1);
		}

		while (!ListIsEmpty(i2)) {
			res = ListInsertBack(res, ListGetHeadValue(i2));
			i2 = ListGetTail(i2);
		}
	} else {
		
		Item* prev = i1;

		while (!ListIsEmpty(i1)) {
			prev = i1;
			i1 = ListGetTail(i1);
		}
		
		prev->next = i2;
	}

	if (c == kCopy) {
		return res;
	} else {
		ListDelete(res);
		return fake_head.next;
	}
}