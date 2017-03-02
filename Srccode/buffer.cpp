#include "buffer.h"
#include <iostream>


using namespace std;
namespace yc
{

buffer::buffer(int size)
:_size(size)
,_mutex()
,_notFull(_mutex)
,_notEmpty(_mutex)
{
}

buffer::~buffer()
{

}

bool buffer::full()
{
	return _size == _q.size();
}

bool buffer::empty()
{
	return 0 == _q.size();
}

void buffer::push(int data)
{
	//_mutex.lock();
	MutexLockGuard mlg(_mutex);
	while(full())
	{
		//cout<<"buffer is full ,wait...."<<endl;
		_notFull.wait();
	}
	_q.push(data);
	//_mutex.unlock();
	_notEmpty.notify();
}

int buffer::pop()
{
	//_mutex.lock();
	MutexLockGuard mlg(_mutex);
	while(empty())
	{
		//cout<<"buffer is empty, wait..."<<endl;
		_notEmpty.wait();
	}
	int num = _q.front();
	_q.pop();
	//_mutex.unlock();
	_notFull.notify();
	return num;
}
}