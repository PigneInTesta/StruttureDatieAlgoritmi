#include "list.h"

Item* Rotate(Item* i, int n) {
	if (ListIsEmpty(i)) {
		return i;
	}

	Item fake_head_i;
	Item* tmp = i;
	Item fake_head_tmp = { .next = tmp };
	int cnt = 0;

	while (cnt != n) {
		i = ListGetTail(i);
		if (cnt + 1 < n) {
			tmp = ListGetTail(tmp);
		}
		cnt++;
	}
	fake_head_i.next = i;
	tmp->next = NULL;
	while (!ListIsEmpty(i)) {
		if (i->next == NULL) {
			break;
		}
		i = ListGetTail(i);
	}

	i->next = fake_head_tmp.next;

	return fake_head_i.next;
}

//int main(void) {
//
//	Item* list_A = NULL;
//
//	ElemType a[] = { 1, 3, 4, 7, 8};
//	size_t dim_A = sizeof(a) / sizeof(ElemType);
//	for (size_t i = 0; i < dim_A; i++) {
//		list_A = ListInsertBack(list_A, a + i);
//	}
//
//	Item* res = Rotate(list_A, 2);
//	ListDelete(res);
//
//	res = Rotate(list_A, 1);
//	ListDelete(res);
//
//	ListDelete(list_A);
//}