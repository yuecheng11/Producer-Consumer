 ///
 /// @file    ConsumerThread.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-03-18 15:30:15
 ///

#ifndef __MY_CONSUMERTHREAD_H_
#define __MY_CONSUMERTHREAD_H_
#include "Thread.h"


namespace wd
{
class Buffer;
class ConsumerThread : public Thread
{
public:
	ConsumerThread(Buffer & buff);
	void run();
private:
	Buffer & _buff;
};

}//end of namespace wd


#endif

