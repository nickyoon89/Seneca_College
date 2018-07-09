// Workshop 5 - Lambda Expression
// Grades.h
// Jihyun Yoon
// 124588172
// 2018-06-20

#ifndef SICT_GRADES_H
#define SICT_GRADES_H

namespace sict {
	class Grades {
		std::string* students;
		double* grades;
		int n = 0;
	public:
		//print out student data with grade letter
		template<typename F>
		void displayGrades(std::ostream& os, F f) const {
			for (int i = 0; i < n; i++) {
				auto letter = f(grades[i]);
				os.precision(2);
				os << "   " << students[i].c_str() << " " << std::fixed << grades[i] << " ";
				os.width(4);
				os << std::left << convert(letter) << std::endl;
			}
		}
		//safe empty state
		Grades();
		//receive file name and store the data in the object
		Grades(const char*);
		//Destructor to deallocate dynamic memory
		~Grades();
		//delete copy, assign and move
		Grades(const Grades&) = delete;
		Grades& operator=(const Grades&) = delete;
		Grades(Grades&&) = delete;
		Grades& operator=(Grades&&) = delete;
	};
	//this function return the number of line of the parameter file.
	int getFileLine(std::ifstream& fin);
}
#endif // !SICT_LETTERS_H