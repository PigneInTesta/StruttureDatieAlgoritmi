#include "list.h"
#ifndef CONCATENA_H_
#define CONCATENA_H_

enum ConcType {
	kCopy,
	kNoCopy
};

#include <stdlib.h>

extern Item* Concatena(Item* i1, Item* i2, enum ConcType c);

#endif // !CONCATENA_H_