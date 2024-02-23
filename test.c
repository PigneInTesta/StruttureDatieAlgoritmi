//da aggiungere nelle liste di esempio per l'esame

//Liste
Item* list_A = NULL;
Item* list_B = NULL;

ElemType a[] = { 1, 2, 3, 4, 5, 6, 7 };
size_t dim_A = sizeof(a) / sizeof(ElemType);
for (size_t i = 0; i < dim_A; i++) {
	list_A = ListInsertBack(list_A, a + i);
}

ListDelete(list_A);
ListDelete(list_B);

//Alberi
ElemType a[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
ElemType b[] = { 12, 4, 21, 0, 5, 18, 77, 2, 8, 9 };
ElemType c[] = { 10, 2, 20, 6, 5, 7, 8, 4, 18, 3 };

Node* Tree_A = TreeCreateEmpty();
Node* Tree_B = TreeCreateEmpty();
Node* Tree_C = TreeCreateEmpty();

//NO BST
Tree_A = TreeCreateRoot(a + 4,	//4
	TreeCreateRoot(a + 3,	//3
		TreeCreateRoot(a + 1,	//1
			TreeCreateRoot(a + 1, NULL, NULL),	//1
			TreeCreateRoot(a + 2, NULL, NULL)),	//2
		NULL),
	TreeCreateRoot(a + 7,	//7
		TreeCreateRoot(a + 5, NULL, NULL),	//5
		TreeCreateRoot(a + 8, NULL, NULL)));//8
//NO BST
Tree_B = TreeCreateRoot(c + 0,	//10
	TreeCreateRoot(c + 1,	//2
		TreeCreateRoot(c + 3,	//6
			TreeCreateRoot(c + 7, NULL, NULL),	//4
			TreeCreateRoot(c + 8, NULL, NULL)),	//18
		TreeCreateRoot(c + 4, NULL, NULL)),	//5
	TreeCreateRoot(c + 2,	//20
		TreeCreateRoot(c + 5, NULL,	//7
			TreeCreateRoot(c + 9, NULL, NULL)),	//3
		TreeCreateRoot(c + 6, NULL, NULL)));	//8
//BST
Tree_C = TreeCreateRoot(b + 0,	//12
	TreeCreateRoot(b + 1,	//4
		TreeCreateRoot(b + 3, NULL, //0
			TreeCreateRoot(b + 7, NULL, NULL)),  //2
		TreeCreateRoot(b + 4, NULL, //5
			TreeCreateRoot(b + 8, NULL, //8
				TreeCreateRoot(b + 9, NULL, NULL)))), //9
	TreeCreateRoot(b + 2, //21
		TreeCreateRoot(b + 5, NULL, NULL), //18
		TreeCreateRoot(b + 6, NULL, NULL))); //77

TreeDelete(Tree_A);
TreeDelete(Tree_B);
TreeDelete(Tree_C);

//Heap

Heap* Heap_A = HeapCreateEmpty();
ElemType a[] = { 1, 5, 4, 6, 12, 23 };
size_t dim_A = sizeof(a) / sizeof(ElemType);
for (size_t i = 0; i < dim_A; i++) {
	HeapMinInsertNode(Heap_A, &a[i]);
}

Heap* Heap_B = HeapCreateEmpty();
ElemType b[] = { 1, 3, 2, 4, 5, 6, 7 };
size_t dim_B = sizeof(b) / sizeof(ElemType);
for (size_t i = 0; i < dim_B; i++) {
	HeapMinInsertNode(Heap_B, &b[i]);
}

Heap* Heap_C = HeapCreateEmpty();
ElemType c[] = { 0, 12, 4, 21, 2, 18, 77, 8, 9 };	//non � ancora una min-heap
size_t dim_C = sizeof(c) / sizeof(ElemType);
for (size_t i = 0; i < dim_C; i++) {				
	HeapMinInsertNode(Heap_C, c + i);				
}																			 
														//			0
														//		   / \
														//		  /   \		
														//		 2	   4	
														//		/ \   / \
														//	   8  12 18 77
														//    / \
														//   21  9
HeapDelete(Heap_A);									
HeapDelete(Heap_B);
HeapDelete(Heap_C);