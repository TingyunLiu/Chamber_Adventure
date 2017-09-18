#ifndef _POISON_H_
#define _POISON_H_
#include "item.h"
#include <string>

class Poison : public Item {
	const std::string type; // poison type
	const bool positive; // whether poison is positive of negative
	public:
		Poison(Game *,const int,const int,const int,const std::string,const bool); // ctor
		~Poison(); // dtor
		std::string getType(); // getter for poison's type
		bool getPositive(); // getter for poison's positivity
};



#endif

