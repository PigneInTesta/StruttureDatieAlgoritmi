#ifndef VECTOR_LIST_H_
#define VECTOR_LIST_H_

#include <stdlib.h>

enum ConversionType {
	kInOrder, 
	kReverse
};

extern Item* Vector2List(const ElemType* v, size_t v_size, enum ConversionType c);
extern ElemType* List2Vector(const Item* i, size_t* v_size, enum ConversionType c);

#endif // !VECTOR_LIST_H_