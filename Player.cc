
#include "Player.h"

std::shared_ptr<Playable> Player::openFile(File file) {
	if (file.empty())
		throw CorruptedTitleException();
	if (file.get_type() == "audio") {
		if (!file.contains("artist") || !file.contains("title"))
			throw CorruptedContentException();
		Song s(file.get_token("title"), file.get_token("artist"), file.get_data());
		std::shared_ptr<Song> ptr = std::make_shared<Song>(s);
		return std::dynamic_pointer_cast<Playable>(ptr);
	}
	else if (file.get_type() == "video") {
		if (!file.contains("year") || !file.contains("title"))
			throw CorruptedContentException();
		Movie m(file.get_token("title"), file.get_token("year"), file.get_data());
		std::shared_ptr<Movie> ptr = std::make_shared<Movie>(m);
		return std::dynamic_pointer_cast<Playable>(ptr);
	}
	else
		throw UnsupportedTypeException();
}