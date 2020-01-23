//#ifndef INC_6_PLAYABLE_H
//#define INC_6_PLAYABLE_H

#include "Playlist.h"
class Playlist;

class Playable {
	Playlist* parent;
public:
	virtual void play() const = 0;
};


//#endif //INC_6_PLAYABLE_H
