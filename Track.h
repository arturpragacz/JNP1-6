#ifndef INC_6_TRACK_H
#define INC_6_TRACK_H

#include "Playable.h"
#include "Exceptions.h"
#include <regex>

class Track : public Playable {
private:
	std::list<std::shared_ptr<Playable>> dummy;

public:
	std::list<std::shared_ptr<Playable>>& get_children() override {
		return dummy;
	}
};


#endif //INC_6_TRACK_H
