#ifndef DESCRIBE_HPP
# define DESCRIBE_HPP

# include <vector>
# include <Assert.hpp>

using namespace std;

class	Describe {
	private:
		static size_t		_numberOfDescriptions;
		size_t				_selfIndex;
		string				_description;
		vector<Assert>		_asserts;
		Describe(void);
	public:
		Describe(string description);
		~Describe(void);
		string	getDescription(void) const;
		void	addAssert(Assert &newAssert);
		void	runAsserts(void) const;
};

#endif