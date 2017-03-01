 ///
 /// @file    test_pc.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-03-18 15:54:42
 ///
 

#include "Buffer.h"
#include "ProductThread.h"
#include "ConsumerThread.h"


int main(void)
{
	wd::Buffer buffer(10);
	wd::Thread *pProduct = new wd::ProductThread(buffer);
	wd::Thread *pConsume = new wd::ConsumerThread(buffer);
	pProduct->start();
	pConsume->start();
	pProduct->join();
	pConsume->join();

	return 0;
}
