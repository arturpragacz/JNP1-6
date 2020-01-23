#ifndef INC_6_SONG_H
#define INC_6_SONG_H

#include "Playable.h"
#include "Track.h"
#include <iostream>
#include <utility>

class Song : public Track {
private:
	std::string name;
	std::string artist;
	std::string data;
	static bool registered;

	Song(std::string name, std::string artist, std::string data) :
			name(std::move(name)), artist(std::move(artist)), data(std::move(data)) {}

public:
	static std::string get_type() {
		return "audio";
	}

	static std::shared_ptr<Track> create(const File& file) {
		if (!file.contains("artist") || !file.contains("title"))
			throw CorruptedContentException();
		if (!std::regex_match(file.get_data(), std::regex(
				"[ qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM1234567890\\,\\.\\!\\?\\'\\:\\;\\-]+")))
			throw CorruptedContentException();
		std::shared_ptr<Song> song {new Song{file.get_token("title"), file.get_token("artist"), file.get_data()}};
		return std::static_pointer_cast<Track>(song);
	}

	/*
	 *  Odtworzenie piosenki polega na wypisaniu na standardowe wyjście napisu "Song",
	 *  wykonawcy piosenki, tytułu piosenki oraz treści; treść piosenek może zawierać tylko znaki
	 *  alfanumeryczne, białe znaki oraz następujące znaki specjalne: ,.!?':;-.
	 */
	void play() override {
		std::cout << "Song [" + artist + ", " + name + "]: " + data << std::endl;
	}
};


#endif //INC_6_SONG_H
