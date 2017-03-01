 ///
 /// @file    ProductThread.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-03-18 15:22:40
 ///
 
#ifndef __MY_PRODUCTThread_H_
#define __MY_PRODUCTThread_H_
#include "Thread.h"

namespace wd
{

class Buffer;

class ProductThread : public Thread
{
public:
	ProductThread(Buffer & buff);
	void run();
private:
	Buffer & _buff;
};

}//end of namespace wd

#endif
