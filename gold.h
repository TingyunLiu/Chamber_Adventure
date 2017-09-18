
#ifndef _GOLD_H_
#define _GOLD_H_
#include "item.h"

class Gold : public Item{
	bool pickable; // whether the gold can be picked up
	public:
		Gold(Game *,const int,const int,const int,bool); // ctor
		~Gold(); // dtor
		bool getPickable(); // getter for pickable
		void setPickable(bool); // setter for pickable
};



#endif
