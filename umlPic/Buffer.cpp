 ///
 /// @file    Buffer.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2016-03-18 15:13:00
 ///
 
#include "Buffer.h"


namespace wd
{

Buffer::Buffer(int size)
: _size(size)
, _mutex()
, _notFull(_mutex)
, _notEmpty(_mutex)
{
	
}

Buffer::~Buffer()
{}

bool Buffer::full()
{
	return _size == _que.size();
}

bool Buffer::empty()
{
	return 0 == _que.size();
}

void Buffer::push(int num)
{
	//MutexLockGuard mlg(_mutex);
	_mutex.lock();
	while(full()) //为了避免被异常唤醒
		_notFull.wait();
	_que.push(num);
	
	_mutex.unlock();
	_notEmpty.notify();
}

int Buffer::pop()
{
	//MutexLockGuard mlg(_mutex);
	_mutex.lock();
	while(empty())
		_notEmpty.wait();

	int num = _que.front();
	_que.pop();
	_mutex.unlock();
	_notFull.notify();
	return num;
}

}//end of namespace wd
