 ///
 /// @file    ConsumerThread.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-03-18 15:32:06
 ///
 
#include "ConsumerThread.h"
#include "Buffer.h"
#include <stdio.h>
#include <unistd.h>
#include <iostream>

using std::cout;
using std::endl;

namespace wd
{

ConsumerThread::ConsumerThread(Buffer & buff)
: _buff(buff)
{}

void ConsumerThread::run()
{
	while(true)
	{
		cout << "consume num:" << _buff.pop() << endl;
		//flockfile(stdout);
		//printf("consumer num:%d\n", _buff.pop());
		//funlockfile(stdout);
		sleep(2);
	}
}

}// end of namespace wd 
