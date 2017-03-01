#include "buffer.h"
#include "Producer.h"
#include "Consumer.h"


int main()
{
	yc::buffer buf(10);
	yc::Thread *pProduct = new yc::Producer(buf);
	yc::Thread *pConsume = new yc::Consumer(buf);

	pProduct->start();
	pConsume->start();
	pProduct->join();
	pConsume->join();

	return 0;
}
