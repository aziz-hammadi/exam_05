#pragma once 

#include <string>
#include <iostream>
#include <map>
#include "ASpell.hpp"
#include "ATarget.hpp"
#include "Dummy.hpp"
#include "Fwoosh.hpp"
class Warlock
{
	private:
	Warlock();//{}
	Warlock(const Warlock &src);//{*this=src;}
	Warlock &operator=(const Warlock &other);//{return *this=other;}
	std::string name;
	std::string title;

	public:
	std::string const &getName() const
	{
		return name;
	}
	std::string const &getTitle() const
	{
		return title;
	}
	void setTitle(std::string newtitle)
	{
		this->title=newtitle;
	}
	Warlock(std::string name, std::string title):name(name), title(title)
	{
		std::cout<<name<<": This looks like another boring day."<<std::endl;
	}
	void introduce() const
	{
		std::cout<<name<<": I am "<<name<<", "<<title<<"!"<<std::endl;
	}
	~Warlock()
	{
		std::cout<<name<<": My job here is done!"<<std::endl;
	}

	void learnSpell(ASpell * ls)
	{
		b.insert(std::make_pair(ls->getName(), ls));
	}
	void forgetSpell(std::string fg)
	{
		std::map<std::string, ASpell*> ::iterator it = b.find(fg);
		if (it == b.end())
			return;
		else 
			b.erase(it);
	}
	void launchSpell(std::string ls, ATarget &at)
	{
		std::map <std::string, ASpell*> ::iterator it = b.find(ls);
		if (it == b.end())
			return;
		else
			(*it).second->launch(at);
	}
	private:
	std::map<std::string, ASpell*> b;
};