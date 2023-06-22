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
        book.insert(std::make_pair(ls->getType(), ls));
    }
    void forgetTargetType(std::string const & fg)
    {
        std::map<std::string, ATarget*> ::iterator it = book.find(fg);
        if (it == book.end())
            return;
        else
            book.erase(it);
    }
    ATarget* createTarget(std::string const &cs)
    {
        std::map<std::string, ATarget *> ::iterator it = book.find(cs);
        if (it == book.end())
            return NULL;
        else
            return (*(*it).second).clone();
    }

    private : 
    std::map<std::string, ATarget *> book;
};