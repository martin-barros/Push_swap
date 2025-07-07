CC = cc

CFLAGS = -Wall -Wextra -Werror

STD_FUNCTIONS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c \
	     ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
	     ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
	     ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c \
	     ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c \
	     ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c \
	     ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c \
	     ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c \
	     ft_tolower.c ft_toupper.c ft_isnum.c \
	     
BONUS_SRCS = ft_lstadd_back.c ft_lstadd_front.c ft_lstnew.c \
		ft_lstmap.c ft_lstlast.c ft_lstiter.c ft_lstsize.c \
		ft_lstclear.c ft_lstdelone.c \

PRINTF_FUNCTIONS = ft_printf/ft_itoa.c ft_printf/ft_printf.c ft_printf/ft_putchar_count.c \
				ft_printf/ft_putlstr.c ft_printf/ft_putptr.c \
				ft_printf/ft_xX.c ft_printf/ft_unsigned_itoa.c \
		
GNL_FUNCTIONS = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \

CFUNCTIONS = $(STD_FUNCTIONS) $(BONUS_SRCS) $(PRINTF_FUNCTIONS) $(GNL_FUNCTIONS)

OBJS = $(CFUNCTIONS:.c=.o)

NAME = libft.a

all: $(PRINTF_FUNCTIONS) $(GNL_FUNCTIONS) $(NAME) 

$(NAME): $(OBJS)
	@ar rcs $@ $^

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
