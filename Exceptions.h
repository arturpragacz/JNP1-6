#ifndef INC_6_EXCEPTIONS_H
#define INC_6_EXCEPTIONS_H

#include <exception>

class PlayerException : public std::exception {

};

class CycleException : public PlayerException {
	const char* what() const noexcept override {
		return "Playlist cycles to itself!";
	}
};

class UnsupportedTypeException : public PlayerException {
	const char* what() const noexcept override {
		return "unsupported type";
	}
};

class CorruptedFileException : public PlayerException {
	const char* what() const noexcept override {
		return "corrupt file";
	}
};

class CorruptedContentException : public PlayerException {
	const char* what() const noexcept override {
		return "corrupt content";
	}
};

#endif // INC_6_EXCEPTIONS_H
