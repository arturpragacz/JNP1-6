#ifndef INC_6_SEQUENCE_H
#define INC_6_SEQUENCE_H

class SeqMode : public Playmode {
public:
	SeqMode() = default;

	std::vector<std::list<std::shared_ptr<Playable>>::iterator>
	permutation(std::vector<std::list<std::shared_ptr<Playable>>::iterator> elements) override {
		std::cout << "Dupa" << std::endl;
		return elements;
	}
};

std::shared_ptr<Playmode> createSequenceMode() {
	return std::static_pointer_cast<Playmode>(std::make_shared<SeqMode>(SeqMode()));
}

#endif // INC_6_SEQUENCE_H
