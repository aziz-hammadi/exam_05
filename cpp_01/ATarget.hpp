#pragma once 
#include <string>
#include <iostream>
#include "ASpell.hpp"
class ASpell;
class ATarget
{
    public:
    ATarget();//{}
    ATarget(const ATarget &src);//{*this=src;}
    ATarget &operator=(const ATarget &other);//{return *this=other;}
    virtual ~ATarget(){}
    protected :
    std::string type;

    public:
    std::string const & getType() const
    {
        return type;
    }

    virtual ATarget *clone() const = 0;
    ATarget(std::string type): type(type)
    {}

    void getHitBySpell(const ASpell &as) const;

};