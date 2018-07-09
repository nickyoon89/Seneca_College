// Workshop 4 - Containers
// Message.h
// Jihyun Yoon(Nick)
// 124558172
// 2018-06-09

#ifndef SICT_MESSAGE_H
#define SICT_MESSAGE_H
namespace sict {
	class Message {
		std::string user;
		std::string reply;
		std::string tweet;
	public:
		//default constructor
		Message();
		//constructor with fstream and delimit. It will store the message in specific format.
		Message(std::ifstream& in, char c);
		// displays the Message objects within the container
		void display(std::ostream&) const;
	};
}
#endif // !SICT_MESSAGE_H
