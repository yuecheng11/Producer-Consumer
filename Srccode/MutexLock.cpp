#include "MutexLock.h"
using namespace yc;

MutexLock::MutexLock():_isLocking(false)
{
	pthread_mutex_init(&mutex,NULL);
}

MutexLock::~MutexLock()
{
	pthread_mutex_destroy(&mutex);
}

MutexLock::lock()
{
	pthread_mutex_lock(&mutex);
	_isLocking = true;
}

MutexLock::unlock()
{
	pthread_mutex_unlock(&mutex);
	_isLocking = true;
}
pthread_mutex_t* MutexLock::getMutexLockPtr()
{
	return &_mutex;
}
