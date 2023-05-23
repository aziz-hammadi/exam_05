#pragma once

#include <string>
#include <iostream>

class ATarget;
class ASpell
{
    ASpell();
    ASpell(const ASpell &src);
    ASpell & operator=(const ASpell &other);
protected :
    std::string name;
    std::string effects;

public :
    std::string const & getName(void) const {return name;}
    std::string const & getEffects(void) const {return effects;}
    virtual ASpell * clone() const = 0;
    ASpell(std::string n, std::string e) : name(n), effects(e){}


    void launch(const ATarget & at) const;
    virtual ~ASpell(void){}
};
#include "ATarget.hpp"