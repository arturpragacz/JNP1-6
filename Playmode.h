//
// Created by ap on 20.01.2020.
//

#ifndef INC_6_PLAYMODE_H
#define INC_6_PLAYMODE_H


class Playmode {
public:
	using ListType = std::vector<std::shared_ptr<const Playable>>;
	virtual ListType arrange(ListType list) = 0;
};

class SequencePlaymode : public Playmode {
	ListType arrange(ListType list) {
		return list;
	}
};

class ShufflePlaymode : public Playmode {
	ListType arrange(ListType list) {
		return list;//TODO
	}
};

class OddEvenPlaymode : public Playmode {
	ListType arrange(ListType list) {
		return list;//TODO
	}
};

#endif //INC_6_PLAYMODE_H
