#ifndef __MY_CONSUMER_H_
#define __MY_CONSUMER_H_
#include "Thread.h"

namespace yc
{
class buffer;

class Consumer:public Thread
{
public:
	Consumer(buffer & buf);
	void run();
private:
	buffer & _buff;
};

}

#endif

