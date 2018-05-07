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

#ifndef AMA_ERRORSTATE_H
#define AMA_ERRORSTATE_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <iomanip>
#include <sstream>
//#pragma warning(disable:4996)

namespace AMA{
	class ErrorState {
		char* _errorMessage;
	public:
		explicit ErrorState(const char* errorMessage = nullptr);
		ErrorState(const ErrorState& em) = delete;
		ErrorState& operator=(const ErrorState& em) = delete;
		virtual ~ErrorState();
		void clear();
		bool isClear() const;
		void message(const char* str);
		const char* message() const;
	};
	std::ostream& operator<< (std::ostream& os, const ErrorState& e);
}

#endif // !AMA_ERRORSTATE_H
