#ifndef H_SHUFFLE_MODE
#define H_SHUFFLE_MODE
#include <random>

class ShuffleMode : public Playmode{
private:
    int seed;

public:
    ShuffleMode(int seedd) {
        seed = seedd;
    }

    virtual std::vector<std::list<std::shared_ptr<Playable>>::iterator> permutation(std::vector<std::list<std::shared_ptr<Playable>>::iterator> elements) {
        std::shuffle(elements.begin(), elements.end(), std::default_random_engine(seed));
        return elements;
    }
};

std::shared_ptr<Playmode> createShuffleMode(int seed) {
    return std::dynamic_pointer_cast<Playmode>(std::make_shared<ShuffleMode>(ShuffleMode(seed)));
}

#endif // H_SHUFFLE_MODE
