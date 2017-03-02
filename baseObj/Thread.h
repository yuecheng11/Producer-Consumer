 ///
 /// @file    thread.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-03-18 10:56:23
 ///

#ifndef _MY_THREAD_H_
#define _MY_THREAD_H_

#include "Noncopyable.h"
#include <pthread.h>
#include <functional>

namespace wd
{
class Thread : private Noncopyable //实现继承== public:接口继承
{
public:
	typedef std::function<void()> ThreadCallback;
	Thread(ThreadCallback cb);
	~Thread();

	void start();
	void join();
private:
	static void * threadFunc(void *);
private:
	pthread_t      _pthId;
	bool	       _isRunning;
	ThreadCallback _cb;
};

}//end of namespace wd

#endif
