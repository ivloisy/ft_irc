# NAME = ircserv
#
# CXX = c++
#
# CXXFLAGS = -MMD -MP -Wall -Wextra -Werror -std=c++98# -g -fsanitize=address
#
# SRC = sources/main.cpp
#
# INC = ./includes/vector.hpp
#
# OBJ = $(SRC:%.cpp=%.o)
#
# all: $(NAME)
#
# $(NAME): $(OBJ)
# 	$(CXX) $(CXXFLAGS) -o $@ $+
#
# %.o: %.cpp
# 	$(CXX) $(CXXFLAGS) -c $(SRC)
#
# -include $(OBJ:.o=.d)
#
# clean:
# 	/bin/rm -rf $(OBJ) *.d
#
# fclean: clean
# 	/bin/rm -f $(NAME)
#
# re: fclean all
#
# .PHONY: all clean fclean re

# TARGET_EXEC ?= a.out
NAME ?= ircserv

SRCDIR ?= ./sources

SRCS := $(shell find $(SRCDIR) -name *.cpp -or -name *.c -or -name *.s)

INCDIR := $(shell find $(SRCDIR) -type d)

INCFLAGS := $(addprefix -I,$(INCDIR))

OBJDIR ?= ./objects

OBJS := $(SRCS:%.cpp=$(OBJDIR)/%.o)

DEPS := $(OBJS:.o=.d)

CXX = c++

CXXFLAGS ?= $(INCFLAGS) -MMD -MP

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)

# assembly
# $(OBJDIR)/%.s.o: %.s
# 	$(MKDIR_P) $(dir $@)
# 	$(AS) $(ASFLAGS) -c $< -o $@
#
# # c source
# $(OBJDIR)/%.c.o: %.c
# 	$(MKDIR_P) $(dir $@)
# 	$(CXX) $(CXXFLAGS) $(CFLAGS) -c $< -o $@

# c++ source
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
