//
// Created by dbaule on 4/3/24.
//

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <vector>
# include <list>
# include <iostream>

# define RED		"\033[31m"
# define RESET		"\033[0m"
# define GREEN		"\033[32m"

template <typename T>
bool easyfind(T &lst, int nbr)
{
    typename T::const_iterator it;
    for (it = lst.begin(); it != lst.end(); it++)
    {
        if (nbr == *it)
            return (true);
    }
    return (false);
}

#endif
