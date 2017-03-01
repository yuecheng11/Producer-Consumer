#include "Producer.h"
#include "buffer.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <iostream>

using namespace std;

namespace yc
{
Producer::Producer(buffer & buf)
:_buff(buf)
{}

void Producer::run()
{
	srand(time(NULL));
	while(true)
	{
		int num = rand() % 100;
		cout<<"Producer a num : "<<num<<endl;
		_buff.push(num);

		sleep(1);
	}
}
}