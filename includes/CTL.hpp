#ifndef CTL_HPP
# define CTL_HPP

# include <exception>
# include <iostream>
# include <map>
# include <functional>
# include <type_traits>
# include <utility>
# include <tuple>

static size_t	g_tabCounter = 0;

template <typename Func, typename... Args>
auto describe(std::string description, Func func, Args&&... args) {

	g_tabCounter += 2;
	std::string	tabSpaces(g_tabCounter, ' ');
    std::cout << tabSpaces << description << std::endl;

    if constexpr (std::is_void_v<decltype(func(std::forward<Args>(args)...))>) {
        func(std::forward<Args>(args)...);
		g_tabCounter -= 2;
		if (!g_tabCounter)
			std::cout << std::endl;
    } else {
        auto response = func(std::forward<Args>(args)...);
		g_tabCounter -= 2;
		if (!g_tabCounter)
			std::cout << std::endl;
		return response;
    }
}

#endif