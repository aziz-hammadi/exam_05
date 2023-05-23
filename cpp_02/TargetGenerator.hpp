#pragma once

# include <map>
# include "ASpell.hpp"

class TargetGenerator 
{
	public :
	TargetGenerator() {}
	~TargetGenerator() {}

	private :
	TargetGenerator(const TargetGenerator &src);
	TargetGenerator &operator=(const TargetGenerator &other);

	public :
	void learnTargetType(ATarget*target)
	{
        book.insert(std::make_pair(target->getType(), target));
	}

	void forgetTargetType(std::string const &target)
	{
		std::map<std::string, ATarget *>::iterator it(book.find(target));
		if (it == book.end())
			return;
		else
			book.erase(it);
	}
	ATarget* createTarget(std::string const &target)
	{
		std::map<std::string, ATarget *>::iterator it(book.find(target));
		if (it == book.end())
			return NULL;
		else
			return (*(*it).second).clone();
	}
	std::map<std::string, ATarget *> book;
};
