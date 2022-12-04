CC		= gcc
CFLAGS 	= -Wall -Werror -Wextra -MMD

DIR_TMP = tmp/

S_NAME	= server
S_SRCS	= server.c \
		minitalk_utils.c \

S_OBJS	= $(S_SRCS:%.c=$(DIR_TMP)%.o)
S_DEPS 	= $(S_SRCS:%.c=$(DIR_TMP)%.d)


C_NAME	= client
C_SRCS	= client.c \
		minitalk_utils.c \

C_OBJS	= $(C_SRCS:%.c=$(DIR_TMP)%.o)
C_DEPS 	= $(C_SRCS:%.c=$(DIR_TMP)%.d)

all:		$(S_NAME) $(C_NAME)

$(DIR_TMP)%.o:	%.c Makefile
			@mkdir -p $(DIR_TMP)
			$(CC) $(CFLAGS) -c $< -o $@

$(S_NAME):	$(S_OBJS)
			$(CC) $(CFLAGS) $(S_OBJS) -o $(S_NAME)

$(C_NAME):	$(C_OBJS)
			$(CC) $(CFLAGS) $(C_OBJS) -o $(C_NAME)

clean:
			rm -f $(S_OBJS) $(C_OBJS)
			rm -f $(S_DEPS) $(C_DEPS)
			rm -rf $(DIR_TMP)

fclean:		clean
			rm -f $(S_NAME) $(C_NAME)

re:			fclean all

-include $(S_DEPS)
-include $(C_DEPS)

.PHONY: fclean clean all re
