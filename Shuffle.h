#ifndef INC_6_SHUFFLE_H
#define INC_6_SHUFFLE_H

#include <random>

class ShuffleMode : public Playmode {
private:
	int seed;

public:
	explicit ShuffleMode(int seed) {
		this->seed = seed;
	}

	std::vector<std::list<std::shared_ptr<Playable>>::iterator>
	permutation(std::vector<std::list<std::shared_ptr<Playable>>::iterator> elements) override {
		std::shuffle(elements.begin(), elements.end(), std::default_random_engine(seed));
		return elements;
	}
};

std::shared_ptr<Playmode> createShuffleMode(int seed) {
	return std::static_pointer_cast<Playmode>(std::make_shared<ShuffleMode>(ShuffleMode(seed)));
}

#endif // INC_6_SHUFFLE_H
