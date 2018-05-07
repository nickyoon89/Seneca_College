// Final Project Milestone 5
//
// Version 2.0
// Date				2018/04/15
// Author			Jihyun Yoon
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// Jihyun Yoon		2018/03/22			File Made
// Jihyun Yoon		2018/04/15			File Moved
/////////////////////////////////////////////////////////////////

#include "ErrorState.h"

namespace AMA {
	ErrorState::ErrorState(const char* errorMessage) {
		_errorMessage = nullptr;
		if (errorMessage == nullptr) {
			message('\0');
		}
		else {
			message(errorMessage);
		}
	}
	ErrorState::~ErrorState() {
		delete[] _errorMessage;
	}
	void ErrorState::clear() {
		_errorMessage[0] = '\0';
	}
	bool ErrorState::isClear() const{
		return (_errorMessage[0]=='\0');
	}
	void ErrorState::message(const char* str) {
		if (str != nullptr) {
			if (_errorMessage != nullptr) { 
				_errorMessage[0] = '\0';
				delete[] _errorMessage; 
				_errorMessage = nullptr;
			}
			_errorMessage = new char[strlen(str) + 1];
			strncpy(_errorMessage, str, strlen(str));
			if (_errorMessage[strlen(str)] != '\0') _errorMessage[strlen(str)] = '\0';
		}
		else {
			_errorMessage = new char[1];
			_errorMessage[0] = '\0';
		}
	}
	const char* ErrorState::message() const {
		return _errorMessage;
	}
	std::ostream& operator<< (std::ostream& os, const ErrorState& e) {
		if (!e.isClear()) {
			os << e.message();
		}
		return os;
	}
}