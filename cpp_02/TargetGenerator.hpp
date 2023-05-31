#pragma once

#include "SpellBook.hpp"
#include <map>
#include <string>
#include "ATarget.hpp"
class TargetGenerator
{
    public :
    TargetGenerator(){}
    ~TargetGenerator(){}
    private :
    TargetGenerator(const TargetGenerator &src);
    TargetGenerator &operator=(const TargetGenerator &other);

    public:
    void learnTargetType(ATarget* ls)
    {
        b.insert(std::make_pair(ls->getType(), ls));
    }
    void forgetTargetType(std::string const & fg)
    {
        std::map<std::string, ATarget*> ::iterator it = b.find(fg);
        if (it == b.end())
            return;
        else
            b.erase(it);
    }
    ATarget* createTarget(std::string const &cs)
    {
        std::map<std::string, ATarget *> ::iterator it = b.find(cs);
        if (it == b.end())
            return NULL;
        else
            return (*(*it).second).clone();
    }

    private : 
    std::map<std::string, ATarget *> b;
};