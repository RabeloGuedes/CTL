#ifndef CTL_HPP
# define CTL_HPP

# include <Describe.hpp>

using namespace std;

class	CTL {
	private:
		static size_t		_numberOfTests;
		string				_testName;
		vector<Describe>	_tests;
	public:
		CTL(void);
		CTL(string testName);
		~CTL(void);
		void	addTest(Describe &newDescription);
		void	runTests(void) const;
};

#endif