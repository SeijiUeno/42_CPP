#include "concrete/PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src)
    : AForm(src), _target(src._target)
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
    if (this != &src)
    {
        AForm::operator=(src);
        _target = src._target;
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::action() const
{
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
