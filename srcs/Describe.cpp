# include <Describe.hpp>

Describe::Describe(string description): _description(description) {}

Describe::~Describe(void) {}

string	Describe::getDescription(void) const {
	return (_description);
}

void	Describe::addAssert(Assert &newAssert) {
	_asserts.push_back(newAssert);
}

void	Describe::runAsserts(void) const {
	string	tabForDescription = string(2, ' ');
	string	tabForAssert = string(4, ' ');
	cout << tabForDescription << _description << endl << endl;
	for (vector<Assert>::const_iterator it = _asserts.begin(); it != _asserts.end(); it++) {
		try {
			it->execute();
		} catch (Assert::FalseAssert &error) {
			cerr << tabForAssert << error.what() << endl;
		} catch (exception &error) {
			cerr << tabForAssert << error.what() << endl;
		} catch (...) {
			cerr << tabForAssert << "Undefined error" << endl;
		}
	}
}