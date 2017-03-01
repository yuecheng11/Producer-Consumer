#ifndef __MY_PRODUCER_H_
#define __MY_PRODUCER_H_
#include "Thread.h"

namespace yc
{

class buffer;

class Producer:public Thread
{
public:
	Producer(buffer & buf);
	void run();
private:
	buffer & _buff;
};

}

#endif