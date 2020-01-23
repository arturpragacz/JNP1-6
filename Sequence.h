#ifndef INC_6_SEQUENCE_H
#define INC_6_SEQUENCE_H

class SeqMode : public Playmode {
public:
	SeqMode() = default;

	VectorType permutation(VectorType elements) override {
		return elements;
	}
};

inline std::shared_ptr<Playmode> createSequenceMode() {
	return std::static_pointer_cast<Playmode>(std::make_shared<SeqMode>());
}

#endif // INC_6_SEQUENCE_H
