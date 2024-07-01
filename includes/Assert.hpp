#ifndef ASSERT_HPP
# define ASSERT_HPP

# include <exception>
# include <iostream>
# include <map>
# include <functional>
# include <type_traits>
# include <utility>
# include <tuple>

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
				~FalseAssert(void) throw();
				virtual const char	*what(void) const throw();
		};
};

#endif