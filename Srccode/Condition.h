#ifndef __MY_CONDITION_H_
#define __MY_CONDITION_H_
#include "Noncopyable.h"
#include <pthread.h>

namespace yc
{
class MutexLock;

class Condition:Noncopyable
{
public:
	Condition(MutexLock& mutex);
	~Condition();
	void wait();
	void notify();
	void notifyAll();
private:
	pthread_cond_t _cond;
	MutexLock& _mutex;
};

}

#endif
