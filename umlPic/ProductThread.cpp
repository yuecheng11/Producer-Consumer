 ///
 /// @file    ProductThread.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-03-18 15:25:01
 ///
 
#include "ProductThread.h"
#include "Buffer.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <iostream>
using std::cout;
using std::endl;

namespace wd
{

ProductThread::ProductThread(Buffer & buff)
: _buff(buff)
{}

void ProductThread::run()
{
	srand(time(NULL));
	while(true)
	{
		int num = rand() % 100;
		cout << "produce a num:" << num << endl;
		//flockfile(stdout);
		//printf("produce num:%d\n", num);
		//funlockfile(stdout);
		_buff.push(num);
		sleep(1);
	}
}

}//end of namespace wd
