#ifndef INC_6_PLAYER_H
#define INC_6_PLAYER_H

#include "Playlist.h"
#include "File.h"
#include "Track.h"
#include "Song.h"
#include "Movie.h"


class Player {
public:
	/*
	 *  Tworzy i zwraca utwór na podstawie pliku; utwór może być odtworzony
	 *  samodzielnie albo dodany do listy odtwarzania;
	 */
	std::shared_ptr<Playable> openFile(const File& file);

	/*
	 *  Tworzy i zwraca listę odtwarzania o podanej nazwie wraz
	 *  z ustawioną domyślną (sekwencyjną) kolejnością odtwarzania; lista może zostać odtworzona
	 *  samodzielnie albo dodana do innej listy odtwarzania; cykle w listach odtwarzania nie powinny
	 *  być dopuszczalne.
	 */
	std::shared_ptr<Playlist> createPlaylist(const char* name) {
		return createPlaylist(std::string(name));
	}

	std::shared_ptr<Playlist> createPlaylist(std::string name) {
		return std::make_shared<Playlist>(Playlist(name));
	}
};


#endif //INC_6_PLAYER_H
