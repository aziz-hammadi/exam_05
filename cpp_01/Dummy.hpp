#pragma once
#include "ATarget.hpp"
class Dummy : public ATarget
{
    public :
    Dummy() : ATarget("Target Practice Dummy"){}
    virtual ATarget *clone() const {return new Dummy;} 
    virtual ~Dummy(){}
};