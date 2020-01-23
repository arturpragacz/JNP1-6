#ifndef INC_6_PLAYMODE_H
#define INC_6_PLAYMODE_H

#include "Playable.h"
#include <memory>
#include <vector>

class Playmode {
public:
	using VectorType = std::vector<const std::shared_ptr<Playable>*>;
	virtual VectorType permutation(VectorType elements) = 0;
};

#endif //INC_6_PLAYMODE_H
