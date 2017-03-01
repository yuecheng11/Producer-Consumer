#ifndef _MY_THREAD_H_
#define _MY_THREAD_H_
#include "Noncopyable.h"
#include <pthread.h>

namespace yc
{
class Thread : private Noncopyable
{
public:
	Thread();
	~Thread();

	void start();
	void join();

	
private:

	virtual void run() = 0;

private:
	static void* threadFunc(void*);
private:
	pthread_t _pthreadId;
	bool isRunning;
};

}

#endif