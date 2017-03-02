 ///
 /// @file    test_pc.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-03-18 15:54:42
 ///
 

#include "Buffer.h"
#include "Thread.h"
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <iostream>

using std::cout;
using std::endl;

struct Product
{
	void produce(wd::Buffer & buff)
	{
		srand(time(NULL));
		while(true)
		{
			int num = rand() % 100;
			buff.push(num);
			cout << "produce a num:" << num << endl;
			sleep(1);
		}
	}
};

struct Consumer
{
	void consume(wd::Buffer & buff)
	{
		while(true)
		{
			cout << "consume a num:" << buff.pop() << endl;
			sleep(2);
		}
	}
};

int main(void)
{
	wd::Buffer buffer(10);
	Product product;
	Consumer consumer;
	wd::Thread producerThread(
			std::bind(&Product::produce, 
					  &product, 
					  std::ref(buffer)));
	wd::Thread consumerThread(
			std::bind(&Consumer::consume,
					  &consumer,
					  std::ref(buffer)));

	producerThread.start();
	consumerThread.start();
	producerThread.join();
	consumerThread.join();
	return 0;
}
