#ifndef INC_6_PLAYABLE_H
#define INC_6_PLAYABLE_H

#include <list>
#include <memory>
#include <iostream>

class Playable {
public:
	virtual std::list<std::shared_ptr<Playable>>& get_children() = 0;

	virtual void play() = 0;
};


#endif //INC_6_PLAYABLE_H
