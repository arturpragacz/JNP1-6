#ifndef INC_6_SONG_H
#define INC_6_SONG_H

#include "Playable.h"
#include "Track.h"
#include <iostream>

class Song : public Track {
private:
	std::string name;
	std::string artist;
	std::string data;

public:
	Song(const std::string& name, const std::string& artist, const std::string& data) {
		if (!std::regex_match(data, std::regex(
				"[ qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM1234567890\\,\\.\\!\\?\\'\\:\\;\\-]+")))
			throw CorruptedContentException();
		this->name = name;
		this->artist = artist;
		this->data = data;
	}

	/*
	 * Odtworzenie piosenki polega na wypisaniu na standardowe wyjście napisu "Song",
	 * wykonawcy piosenki, tytułu piosenki oraz treści; treść piosenek może zawierać tylko znaki
	 * alfanumeryczne, białe znaki oraz następujące znaki specjalne: ,.!?':;-.
	 */
	void play() override {
		std::cout << "Song [" + artist + ", " + name + "]: " + data << std::endl;
	}
};


#endif //INC_6_SONG_H
