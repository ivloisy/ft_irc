//
// Created by antoine on 20/06/22.
//

#ifndef FT_IRC_MESSAGE_HPP
#define FT_IRC_MESSAGE_HPP


class Message {
	//sender, receiver, payload, command called
	//variable PASS, 1 if nick and password defined, 0 if not

public:
	Message();
	virtual ~Message();
	Message(Message const &src);
	Message &operator=(Message const &rhs);
};


#endif //FT_IRC_MESSAGE_HPP
