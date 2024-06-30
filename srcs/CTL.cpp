#include <CTL.hpp>

CTL::CTL(void) {}

CTL::CTL(string testName): _testName(testName) {}

CTL::~CTL(void) {}

void	CTL::addTest(Describe &newDescription) {
	_tests.push_back(newDescription);
}

void	CTL::runTests(void) const {
	cout << _testName << endl << endl;
	for (vector<Describe>::const_iterator it = _tests.begin(); it != _tests.end(); it++) {
		it->runAsserts();
	}
}