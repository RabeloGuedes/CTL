#ifndef ASSERT_HPP
# define ASSERT_HPP

# include <exception>
# include <iostream>

using namespace std;

class	Assert {
	private:
		string	_it;
		bool	_condition;
		Assert(void);
	public:
		Assert(string it, bool condition);
		~Assert(void);
		void	execute(void) const;
		class	FalseAssert: public exception {
			private:
				string	_message;
			public:
				FalseAssert(const string &it);
				virtual const char	*what(void) const throw();
		};
};

#endif