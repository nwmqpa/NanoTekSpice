##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## makefile of the source file
##

ROOT		=			.

SUBDIRS_COMP 	:= 			$(wildcard components/*/.)

INSTALL_PATH 	:=			/usr/share/nanotekspice

SRC_DIR		=			sources

CXX		=			g++

NAME		=			nanotekspice

BUILD		=			$(ROOT)/build

SRC		=			$(SRC_DIR)/main.cpp \
					$(SRC_DIR)/Application.cpp \
					$(SRC_DIR)/PluginLoader.cpp \
					$(SRC_DIR)/Utils.cpp \
					$(SRC_DIR)/ComponentFactory.cpp \
					$(SRC_DIR)/Simulation.cpp \
					$(SRC_DIR)/Parser.cpp

CXXFLAGS	=			-g -I $(ROOT)/includes $(WARN) -std=gnu++17 -export-dynamic -Wall -Wextra

LDFLAGS		=			-ldl -lstdc++fs -export-dynamic

LIB		?=			1

TEST		?=			0

DEB		?=			0

G		=			-g -D DEBUG

V		?=			@

OBJS		=			$(patsubst $(SRC_DIR)/%.cpp, $(BUILD)/%.o, $(SRC))

#COLOR

GREEN		=			\e[1;32m

WHITE		=			\e[0m

ORANGE		=			\e[1;33m

RED 		=			\e[1;35m

BLUE		=			\e[1;34m

debug:					CXXFLAGS += $(G)

release:				CXXFLAGS += -D INSTALL_PATH="$(INSTALL_PATH)"

##
## Directives
##

all:					$(NAME) components

$(NAME):				$(OBJS)
					$(V)printf "$(GREEN)Compile sources.$(WHITE)\n"
					$(V)$(CXX) -o $(NAME) $(OBJS) $(LDFLAGS)
					$(V)printf "$(GREEN)Linking obj and Libraries.$(WHITE)\n"

debug: 					fclean echo_d $(NAME)

release: 				fclean echo_r $(NAME)

$(BUILD)/$(NAME):			$(OBJS)
					$(V)printf "$(GREEN)Compile sources.$(WHITE)\n"
					$(V)$(CXX) -o $(BUILD)/$(NAME) $(OBJS) $(LDFLAGS)
					$(V)printf "$(GREEN)Linking obj and Libraries.$(WHITE)\n"

$(BUILD)/%.o:				$(SRC_DIR)/%.cpp
					$(V)mkdir -p $(dir $@)
					$(V)printf "$(BLUE)Compiling [$(GREEN)$(notdir $<)$(BLUE) -> $(RED)$(notdir $@)$(BLUE)]\n$(WHITE)"
					$(V)$(CXX) -o $@ -c $< $(CXXFLAGS) $(LDFLAGS)

clean:
					$(V)for dir in $(SUBDIRS_COMP); do \
						make --no-print-directory -C $$dir clean; \
					done
					$(V)rm -rf $(OBJS)
					$(V)printf "$(ORANGE)Removing object files.$(WHITE)\n"

fclean: 				clean
					$(V)for dir in $(SUBDIRS_COMP); do \
						make --no-print-directory -C $$dir fclean; \
					done
					$(V)rm -f $(BUILD)/$(NAME)
					$(V)rm -f $(ROOT)/$(NAME)
					$(V)printf "$(ORANGE)Removing binary file.$(WHITE)\n"

re:					fclean
					$(V)make --no-print-directory all

echo_build:
					$(V)printf "$(GREEN)Begin of the build !\n$(ORANGE)Warnings : \n$(WHITE)"

echo_d:
					$(V)printf "$(RED)DEBUG MODE initialized.$(WHITE)\n";

echo_r:
					$(V)printf "$(RED)RELEASE MODE initialized.$(WHITE)\n";

components:				$(SUBDIRS_COMP)

$(SUBDIRS_COMP):
					$(V)printf "$(BLUE)Building $@\n$(WHITE)"
					$(V)make --no-print-directory -C $@

install:				release plugins displayers
					$(V)printf "$(GREEN)Installing on the system at $(INSTALL_PATH)\n$(WHITE)"
					$(V)mkdir -p $(INSTALL_PATH)
					$(V)cp -r resources $(INSTALL_PATH)
					$(V)mkdir -p $(INSTALL_PATH)/components
					$(V)cp components/*.so $(INSTALL_PATH)/components
					$(V)cp $(NAME) /usr/bin/$(NAME)
					$(V)printf "$(GREEN)Done installing at $(INSTALL_PATH)\n$(WHITE)"


.PHONY: 				clean fclean debug all re echo_debug buildrepo $(SUBDIRS_COMP) components install
