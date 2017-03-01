#ifndef _MY_MUTEXLOCK_H_
#define _MY_MUTEXLOCK_H_

#include "Noncopyable.h"
#include <pthread.h>
namespace yc
{
class MutexLock : Noncopyable
{
public:
	MutexLock();
	~MutexLock();
	void lock();
	void unlock();
	pthread_mutex_t* getMutexLockPtr();
	
private:
	pthread_mutex_t _mutex;
	bool _isLocking;
};
}

#endif
