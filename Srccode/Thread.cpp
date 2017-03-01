#include "Thread.h"
#include <iostream>

namespace yc
{
Thread::Thread()
:_pthreadId(0)
,isRunning(false)
{
}

Thread::~Thread()
{
	if(isRunning)
	{
		pthread_detach(_pthreadId);
	}
}

void Thread::start()
{
	pthread_create(&_pthreadId,NULL,&Thread::threadFunc,this);
	isRunning = true;
}

void Thread::join()
{
	if(isRunning)
		pthread_join(_pthreadId,NULL);
}

void* Thread::threadFunc(void* arg)
{
	Thread* pThread = static_cast<Thread*>(arg);
	if(pThread)
	{
		pThread->run();
	}
}

}
