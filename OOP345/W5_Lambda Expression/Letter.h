// Workshop 5 - Lambda Expression
// Letter.h
// Jihyun Yoon
// 124588172
// 2018-06-20

#ifndef SICT_LETTERS_H
#define SICT_LETTERS_H

namespace sict {
	//enumeration to store grades
	enum class Letter{A_, A, B_, B, C_, C, D_, D, F, X};
	std::string ret = "";

	//templated function to convert grades to C-style string
	template<typename T>
	const char* convert(const T& t) {
		
		switch (t) {
			case Letter::A_:
				ret = "A+";
				break;
			case Letter::A:
				ret = "A";
				break;
			case Letter::B_:
				ret = "B+";
				break;
			case Letter::B:
				ret = "B";
				break;
			case Letter::C_:
				ret = "C+";
				break;
			case Letter::C:
				ret = "C";
				break;
			case Letter::D_:
				ret = "D+";
				break;
			case Letter::D:
				ret = "D";
				break;
			case Letter::F:
				ret = "F";
				break;
			default:
				ret = "";
				break;
		}
		return ret.c_str();
	}
}
#endif // !SICT_LETTERS_H



