#ifndef INC_6_MOVIE_H
#define INC_6_MOVIE_H

#include <utility>

#include "Playable.h"
#include "Track.h"

class Movie : public Track {
private:
	std::string name;
	std::string year;
	std::string data;
	static bool registered;

	std::string rot13(const std::string& s) {
		std::string result;
		for (char i : s) {
			if (i >= 'A' && i <= 'Z')
				result += ((i - 'A' + 13) % 26 + 'A');
			else if (i >= 'a' && i <= 'z')
				result += ((i - 'a' + 13) % 26 + 'a');
			else
				result += i;
		}
		return result;
	}

	Movie(std::string name, std::string year, std::string data) :
			name(std::move(name)), year(std::move(year)), data(std::move(data)) {}

public:
	static std::string get_type() {
		return "video";
	}

	static std::shared_ptr<Track> create(const File& file) {//TODO: check year
		if (!file.contains("title") || !file.contains("year"))
			throw CorruptedContentException();
		if (!std::regex_match(file.get_data(), std::regex(
				"[ qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM1234567890\\,\\.\\!\\?\\'\\:\\;\\-]+")))
			throw CorruptedContentException();
		std::shared_ptr<Movie> movie{new Movie{file.get_token("title"), file.get_token("year"), file.get_data()}};
		return std::static_pointer_cast<Track>(movie);
	}

	/*
	 *  Odtworzenie filmu polega na wypisaniu na standardowe wyjście napisu "Movie",
	 *  tytułu filmu, roku produkcji oraz treści; treść filmów zakodowana jest w ROT13 i może
	 *  zawierać tylko znaki alfanumeryczne, białe znaki oraz następujące znaki specjalne: ,.!?':;-.
	 */
	void play() override {
		std::cout << "Movie [" + name + ", " + year + "]: " + rot13(data) << std::endl;
	}
};


#endif //INC_6_MOVIE_H
