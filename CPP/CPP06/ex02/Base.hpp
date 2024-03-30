//
// Created by dbaule on 3/30/24.
//

#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>
# include <cstdlib>
# include <ctime>


class Base {
public :
    Base();
    virtual ~Base();
};

    Base *generate(void);

    void    identify(Base *p);
    void    identify(Base &p);

#endif
