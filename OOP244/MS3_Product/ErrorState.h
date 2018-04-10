// Final Project Milestone 2
//
// Version 1.0
// Date				2018/03/22
// Author			Jihyun Yoon
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// Jihyun Yoon		2018/03/22			File Made
/////////////////////////////////////////////////////////////////

#ifndef AMA_ERRORSTATE_H
#define AMA_ERRORSTATE_H

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
