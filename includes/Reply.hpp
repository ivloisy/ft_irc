//
// Created by user42 on 27/06/22.
//

/************* USELESS FOR THE MOMENT *********************/

#ifndef FT_IRC_REPLY_HPP
#define FT_IRC_REPLY_HPP



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
