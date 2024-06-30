#include <Assert.hpp>

Assert::Assert(string it, bool condition): _it(it), _condition(condition) {}

Assert::~Assert(void) {}

void	Assert::execute(void) const {
	if (!_condition)
		throw FalseAssert(_it);
	cout << "✅ " << _it << endl;
}

Assert::FalseAssert::FalseAssert(const string &it): _message("❌ "+ it) {};

Assert::FalseAssert::~FalseAssert(void) throw() {}

const char	*Assert::FalseAssert::what(void) const throw() {
	return (_message.c_str());
}
