#ifndef INC_6_EVEN_ODD_H
#define INC_6_EVEN_ODD_H

#include "Playmode.h"

class EvenOddMode : public Playmode {
public:
	EvenOddMode() = default;

	VectorType permutation(VectorType elements) override {
		if (elements.empty())
			return elements;
		VectorType buffer;
		for (size_t i = 1; i < elements.size(); i += 2) {
			buffer.push_back(elements[i]);
		}
		for (size_t i = 0; i < elements.size(); i += 2) {
			buffer.push_back(elements[i]);
		}
		return buffer;
	}
};

inline std::shared_ptr<Playmode> createOddEvenMode() {
	return std::static_pointer_cast<Playmode>(std::make_shared<EvenOddMode>());
}

#endif // INC_6_EVEN_ODD_H
