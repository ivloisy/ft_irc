//
// Created by user42 on 27/06/22.
//

#ifndef FT_IRC_REPLY_HPP
#define FT_IRC_REPLY_HPP

std::string RPL_WELCOME(std::string prefix) {                           //001
    return (":Welcome to the Internet Relay Network " + prefix);
}

std::string RPL_YOURHOST(std::string servername, std::string ver) {     //002
    return (":Your host is " + servername + ", running version " + ver);
}

std::string RPL_CREATED(std::string date) {                             //003
    return (":This server was created " + date);
}
std::string RPL_MYINFO(std::string servername, std::string version,
                       std::string umodes, std::string cmodes) {        //004
    return (servername + " " + version + " " + umodes + " " + cmodes);
}

class Reply {

private:
    User                        _user;
    Server                      _server;

    std::string                 _prefix;
    std::vector<std::string>    _parameters;
    std::string                 _trailer;
    std::string                 _query;

public:
    Reply(User user, Server server, std::string msg);

    User                        getUser();
    Server                      getServer();
    std::string                 getPrefix();
    std::vector<std::string>    getParameters();
    std::string                 getTrailer();
    std::string                 getQuery();

};


#endif //FT_IRC_REPLY_HPP
