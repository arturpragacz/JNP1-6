#ifndef H_EXCEPTIONS_PLAYLIST
#define H_EXCEPTIONS_PLAYLIST
#include <exception>

class PlayerException : public std::exception {

};

class CycleException : public PlayerException {
    const char * what () const throw () {
      return "Playlist cycles to itself!";
    }
};

class UnsupportedException : public PlayerException {
    const char * what () const throw () {
      return "unsupported type";
    }
};

class CorruptedTitleException : public PlayerException {
    const char * what () const throw () {
      return "corrupt file";
    }
};

class CorruptedContentException : public PlayerException {
    const char * what () const throw () {
      return "corrupt content";
    }
};

#endif // H_EXCEPTIONS_PLAYLIST
