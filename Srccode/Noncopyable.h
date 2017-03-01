#ifndef _NONCOPYABLE_H_
#define _NONCOPYABLE_H_
namespace yc
{
class Noncopyable
{
protected:
	Noncopyable(){}
private:
	Noncopyable(Noncopyable& rhs);
	Noncopyable& operator=(const Noncopyable& rhs);
};

}


#endif