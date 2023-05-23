#pragma once

#include <string>
#include <iostream>
class ASpell;
class ATarget
{
    ATarget();
    ATarget(const ATarget &src);
    ATarget & operator=(const ATarget &other);
private :
    std::string type;
public :
    std::string const & getType(void)const {return type;}
    virtual ATarget * clone() const = 0;
    ATarget(const std::string t): type(t){}


    void getHitBySpell(const ASpell &spell) const;
    virtual ~ATarget(void){}
};
#include "ASpell.hpp" 
