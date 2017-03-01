#include "Consumer.h"
#include "buffer.h"
#include <stdio.h>
#include <unistd.h>
#include <iostream>

using namespace std;

namespace yc
{
Consumer::Consumer(buffer& buf)
:_buff(buf)
{}

void Consumer::run()
{
	while(true)
	{
		cout<<"Consumer a num : "<< _buff.pop()<<endl;
		sleep(2);
	}
}
}
