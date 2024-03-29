//
// Created by dbaule on 3/28/24.
//

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"


class Intern {
public:
    // CONSTRUCTOR AND DESTRUCTOR
    Intern();
    Intern(Intern &src);
    Intern &operator=(Intern &rhs);
    ~Intern();
    //METHOD
    AForm *makeForm(std::string name, std::string target);

    class NoNameForm : public std::exception
    {
    public :
        virtual const char* what() const throw()
        {
            return ("Intern didn't find the name of the Form");
        }
    };
};


#endif
