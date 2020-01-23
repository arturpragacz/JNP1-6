#ifndef INC_6_LIB_PLAYLIST_H
#define INC_6_LIB_PLAYLIST_H

#include "Playlist.h"
#include "Player.h"
#include "EvenOdd.h"
#include "Sequence.h"
#include "Shuffle.h"
#include "TrackFactory.h"

bool Movie::registered = TrackFactory::registerClass(Movie::get_type(), Movie::create);
bool Song::registered = TrackFactory::registerClass(Song::get_type(), Song::create);

#endif //INC_6_LIB_PLAYLIST_H
