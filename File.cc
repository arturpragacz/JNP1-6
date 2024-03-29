#include "File.h"
#include "Exceptions.h"

File::File(const std::string& data) {
	size_t i = 0;
	for (; i < data.length() && data[i] != '|'; ++i) {
		type += data[i];
	}
	if (i == data.length())
		throw CorruptedFileException();
	i++;
	for (; i < data.length(); ++i) {
		std::string buffer;
		std::string buffer2;
		while (data[i] != ':' && data[i] != '|' && i < data.length()) {
			buffer += data[i];
			i++;
		}
		if (i >= data.length()) {
			this->data = buffer;
		}
		else if (data[i] == ':') {
			i++;
			while (i < data.length() && data[i] != '|') {
				buffer2 += data[i];
				i++;
			}
			tokens[buffer] = buffer2;
		}
		else
			throw CorruptedFileException();
	}
}
