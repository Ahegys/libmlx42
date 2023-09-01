
NAME = engine3d
FILES = main.c
OBJS = $(addprefix $(BUILDS)/, $(FILES:.c=.o))
DEP = $(OBJS:.o=.d)
SRCS = ./resources
VPATH = srcs
VPATH := $(SRCS) $(addprefix $(SRCS)/, $(VPATH))
HEADER = ./inc
HEADER := $(addprefix -I, $(HEADER))
BUILDS = ./builds
CC = cc
CFLAGS = -Wall -Werror -Wextra -g
DEPFLAGS = -MMD -MF
DEL = rm -rf
MKDIR = mkdir -p

DEL_MSG = @printf "[-][\e[0;31m DEL \e[0m] "
BIN_MSG = @printf "[*][\e[0;32m BIN \e[0m] $(NAME)"
BLD_MSG = @printf "[+][\e[0;34m BLD \e[0m] "
MKD_MSG = @printf "[+][\e[0;35m MKD \e[0m] "

all: $(NAME)

$(NAME): $(BUILDS) $(OBJS)
	$(BIN_MSG)
	@$(CC) $(CFLAGS) $(OBJS) $(HEADER) -o $@ -I./MLX42/include -L./MLX42/build -lmlx42 -lglfw -ldl -pthread -lm
clean:
	$(DEL_MSG)
	$(DEL) $(BUILDS)

fclean: clean
	$(DEL_MSG)
	$(DEL) ./$(NAME)

re: fclean all

run: all
	clear
	@./$(NAME)

$(BUILDS):
	$(MKD_MSG)
	@$(MKDIR) $@

$(BUILDS)/%.o: %.c
	$(BLD_MSG)
	@printf "Building ... %s\n" $@
	@$(CC) $(CFLAGS) $(HEADER) -c $< -o $@ $(DEPFLAGS) $(@:.o=.d)

.PHONY: all clean fclean re

-include $(DEP)
