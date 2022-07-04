NAME = ircserv

SRCDIR = ./sources

#SRCS = $(shell find $(SRCDIR) -name *.cpp -or -name *.c -or -name *.s)
SRCS = 	main.cpp \
		sources/Config.cpp \
		sources/Message.cpp \
		sources/Server.cpp \
		sources/User.cpp \
		sources/utils.cpp

INCDIR = ./includes

INCS = $(shell find $(INCDIR) -type d)

OBJDIR = ./objects

OBJS = $(SRCS:%.cpp=$(OBJDIR)/%.o)

DEPS = $(OBJS:.o=.d)

CXX = c++

CXXFLAGS = -I $(INCDIR) -MMD -MP

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)

$(OBJDIR)/%.o: %.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) -r $(OBJDIR)

fclean: clean
	$(RM) -r $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re
