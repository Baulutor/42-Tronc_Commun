//
// Created by dbaule on 3/28/24.
//

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"


class Intern {
public:
    Intern();
    Intern(Intern &src);
    Intern &operator=(Intern &rhs);
    ~Intern();
    //METHOD
    AForm *makeForm(std::string name, std::string target);
};


#endif
