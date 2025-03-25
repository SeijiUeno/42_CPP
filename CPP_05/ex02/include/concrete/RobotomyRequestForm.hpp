#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "../AForm.hpp"
#include <string>

class RobotomyRequestForm : public AForm {
private:
    std::string _target;
public:
    RobotomyRequestForm(const std::string &target);
    RobotomyRequestForm(const RobotomyRequestForm &src);
    RobotomyRequestForm &operator=(const RobotomyRequestForm &src);
    virtual ~RobotomyRequestForm();

    virtual void action() const;
};

#endif // ROBOTOMYREQUESTFORM_HPP
