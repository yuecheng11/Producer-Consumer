#ifndef __MY_BUFFER_H_
#define __MY_BUFFER_H_

#include "MutexLock.h"
#include "Condition.h"

#include <queue>
using namespace std;

namespace yc
{
class buffer
{
public:
	buffer(int size);
	~buffer();

	void push(int data);
	int pop();

	bool full();
	bool empty();
	
private:
	int _size;
	queue<int> _q;
	MutexLock _mutex;
	Condition _notFull;
	Condition _notEmpty;
};
}


#endif


