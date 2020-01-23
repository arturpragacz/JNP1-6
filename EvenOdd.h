#ifndef INC_6_EVEN_ODD_H
#define INC_6_EVEN_ODD_H

#include "Playmode.h"

class EvenOddMode : public Playmode {
public:
	EvenOddMode() = default;

	std::vector<std::list<std::shared_ptr<Playable>>::iterator>
	permutation(std::vector<std::list<std::shared_ptr<Playable>>::iterator> elements) override {
		if (elements.empty())
			return elements;
		std::vector<std::list<std::shared_ptr<Playable>>::iterator> buffer1;
		std::vector<std::list<std::shared_ptr<Playable>>::iterator> buffer2;
		for (size_t i = 0; i < elements.size(); i += 2) {
			buffer1.push_back(elements[i]);
		}
		for (size_t i = 1; i < elements.size(); i += 2) {
			buffer2.push_back(elements[i]);
		}
		for (size_t i = 0; i < elements.size() / 2; i++) {
			elements[i] = buffer2[i];
		}
		for (size_t i = elements.size() / 2; i < elements.size(); i++) {
			elements[i] = buffer1[i - elements.size() / 2];
		}
		return elements;
	}
};

std::shared_ptr<Playmode> createOddEvenMode() {
	return std::dynamic_pointer_cast<Playmode>(std::make_shared<EvenOddMode>(EvenOddMode()));
}

#endif // INC_6_EVEN_ODD_H
