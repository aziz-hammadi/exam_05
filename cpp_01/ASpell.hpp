#pragma once
#include <string>
#include <iostream>
#include "ATarget.hpp"

class ATarget;
class ASpell
{
    public:
    ASpell();
    ASpell(const ASpell &src):name(src.getName()), effects(src.getEffects()){}
    ASpell &operator=(const ASpell &other) {name = other.getName(); effects=other.getEffects(); return *this;}
    virtual ~ASpell(){}
    protected :
    std::string name;
    std::string effects;

    public:
    std::string const & getName() const
    {
        return name;
    }
    std::string const &getEffects() const 
    {
        return effects;
    }
    virtual ASpell *clone() const = 0;
    ASpell(std::string name, std::string effects): name(name), effects(effects)
    {}

    void launch(const ATarget &at) const;

};