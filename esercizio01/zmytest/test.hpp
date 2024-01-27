#ifndef MYTEST_HPP
#define MYTEST_HPP

#include "../list/list.hpp"
#include "../vector/vector.hpp"
#include "../stack/lst/stacklst.hpp"
#include "../stack/vec/stackvec.hpp"
#include "../queue/lst/queuelst.hpp"
#include "../queue/vec/queuevec.hpp"

void mytest();

void startTest(int struct, int type, ulong size);

int chooseStructure();
int chooseType();

#endif