#ifndef INC_6_PLAYER_H
#define INC_6_PLAYER_H

#include <string_view>
#include "Playlist.h"
#include "File.h"
#include "Track.h"


class Player {
public:
	/*
	 *  Tworzy i zwraca utwór na podstawie pliku; utwór może być odtworzony
	 *  samodzielnie albo dodany do listy odtwarzania;
	 */
	Track openFile(File file) {

	}

	/*
	 *  Tworzy i zwraca listę odtwarzania o podanej nazwie wraz
	 *  z ustawioną domyślną (sekwencyjną) kolejnością odtwarzania; lista może zostać odtworzona
	 *  samodzielnie albo dodana do innej listy odtwarzania; cykle w listach odtwarzania nie powinny
	 *  być dopuszczalne.
	 */
	Playlist createPlaylist(std::string_view name) {

	}
};


#endif //INC_6_PLAYER_H
