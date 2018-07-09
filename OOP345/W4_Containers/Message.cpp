// Workshop 4 - Containers
// Message.cpp
// Jihyun Yoon(Nick)
// 124558172
// 2018-06-09
#include <fstream>
#include <iostream>
#include <string>
#include "Message.h"
namespace sict {
	//default constructor
	Message::Message() {
		user = "";
		reply = "";
		tweet = "";
	}
	//constructor with fstream and delimit. It will store the message in specific format.
	Message::Message(std::ifstream& in, char c) {
		size_t pos = 0u;
		size_t count = 0u;
		std::string line;
		std::getline(in, line);
		while ((pos = line.find(c)) != std::string::npos) {
			if (count == 0u) {
				user = line.substr(0, pos);
			}
			else if (count == 1u) {
				if (line.substr(0, 1) == "@") {
					reply = line.substr(1, pos-1);
				}
				else {
					tweet = line;
					break;
				}
			}
			else {
				tweet = line;
				break;
			}
			line.erase(0, pos + 1);
			count++;
		}
	}
	// displays the Message objects within the container
	void Message::display(std::ostream& os) const {
		if (user.length() != 0&&tweet.length() != 0) {
			os << "Message" << std::endl;
			os << " User  : "<<user << std::endl;
			if (reply.length() != 0) os << " Reply : " << reply << std::endl;
			os << " Tweet : " << tweet << std::endl << std::endl;
			if (reply.length() != 0) os << std::endl;
		}
	}
}