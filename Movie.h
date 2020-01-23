#ifndef INC_6_MOVIE_H
#define INC_6_MOVIE_H
#include "Playable.h"
#include "Track.h"

class Movie : public Track {
private:
    std::string name;
    std::string year;
    std::string data;

private:
    std::string rot13(std::string s) {
        std::string result;
        for(size_t i = 0; i < s.length(); i++) {
            if(s[i] >= 'A' && s[i] <= 'Z')
                result += ((s[i] - 'A' + 13) % 26 + 'A');
            else if(s[i] >= 'a' && s[i] <= 'z')
                result += ((s[i] - 'a' + 13) % 26 + 'a');
            else
                result += s[i];
        }
        return result;
    }

public:
    Movie(std::string name, std::string year, std::string data) {
        if(!std::regex_match(data, std::regex("[ qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM1234567890\\,\\.\\!\\?\\'\\:\\;\\-]+")))
            throw CorruptedContentException();
        this->name = name;
        this->year = year;
        this->data = data;
    }

	/*
	 *  Odtworzenie filmu polega na wypisaniu na standardowe wyjście napisu "Movie",
	tytułu filmu, roku produkcji oraz treści; treść filmów zakodowana jest w ROT13 i może
	zawierać tylko znaki alfanumeryczne, białe znaki oraz następujące znaki specjalne: ,.!?':;-.
	 */
	virtual void play() {
        std::cout<<"Movie [" + name + ", " + year + "]: " + rot13(data)<<std::endl;
    }
};


#endif //INC_6_MOVIE_H
