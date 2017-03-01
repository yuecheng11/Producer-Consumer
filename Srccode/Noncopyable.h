#ifndef _MY_NONCOPYABLE_H_
#define _MY_NONCOPYABLE_H_
namespace yc
{

class Noncopyable
{
protected:
	Noncopyable(){}
private:
	Noncopyable(const Noncopyable & rhs);
	Noncopyable& operator=(const Noncopyable & rhs);
};

}


#endif