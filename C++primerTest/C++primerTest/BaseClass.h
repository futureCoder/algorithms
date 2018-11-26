#ifndef _BASE_CLASS_H_
#define _BASE_CLASS_H_

class Base
{
public:
	Base() = default;
	~Base() = default;
	Base(const Base&) { std::cout << "copy construct" << std::endl; }
	Base(const Base&&) noexcept { std::cout << "move construct" << std::endl; }
private:
	int	val;
};

#endif // _BASE_CLASS_H_
