
#include "Player.h"
#include "TrackFactory.h"

std::shared_ptr<Playable> Player::openFile(const File& file) {
	if (file.empty())
		throw CorruptedTitleException();
	std::shared_ptr<Track> track = TrackFactory::create(file);
	if (!track)
		throw UnsupportedTypeException();
	else
		return std::static_pointer_cast<Playable>(track);
}