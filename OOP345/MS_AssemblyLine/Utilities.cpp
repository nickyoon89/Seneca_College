#include "Utilities.h"

char Utilities::delimiter = ' ';
Utilities::Utilities() {
	field_width = 1;
}
void Utilities::setFieldWidth(size_t fw) {
	field_width = fw;
}
size_t Utilities::getFieldWidth() const {
	return field_width;
}
const std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {
	std::string ret = str.substr(next_pos);
	size_t pos = ret.find(delimiter);
	if (pos != std::string::npos) {
		ret = ret.substr(0, pos);
		next_pos += pos + 1;
		more = true;
	}
	else {
		more = false;
	}
	return ret;

}
void Utilities::setDelimiter(const char d) {
	delimiter = d;
}
const char Utilities::getDelimiter() const {
	return delimiter;
}