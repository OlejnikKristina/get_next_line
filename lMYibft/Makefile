NAME		= libft.a
CFLAGS		= -Wall -Werror -Wextra

FILES :=	strcmp \
	toupper \
	strcpy \
	strdup \
	atoi \
	strlen \
	isalnum \
	isalpha \
	isascii \
	strncat \
	strncmp \
	strncpy \
	isdigit \
	strnstr \
	isprint \
	strrchr \
	strcat \
	strstr \
	strchr \
	tolower \
	memmove \
	memcpy \
	memccpy \
	memcmp \
	memset \
	bzero \
	memchr \
	strlcat \
	putstr_fd \
	putchar_fd \
	putendl_fd \
	putendl \
	putnbr_fd \
	putnbr \
	putstr \
	putchar \
	memalloc \
	memdel \
	strnew \
	strdel \
	strclr \
	striter \
	striteri \
	strmap \
	strmapi \
	strequ \
	strnequ \
	strsub \
	strsplit \
	strjoin \
	lstnew \
	lstdelone \
	lstadd \
	lstiter \
	strtrim \
	lstdel \
	itoa \
	lstmap \
	sqrt \
	recursive_factorial \
	foreach \
	range \

SRC = $(addprefix ft_, $(FILES))
PRIVATE = kr_count_words findchr ft_count_digit space

OBJ	= $(addsuffix .o, $(SRC)) $(addsuffix .o, $(PRIVATE))

all: $(NAME)

# This won't run if the .o files don't exist or are not modified
$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

# This won't run if the source files don't exist or are not modified
$(OBJ):
	gcc $(CFLAGS) -c $(addsuffix .c, $(SRC)) $(addsuffix .c, $(PRIVATE))
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

so:
	gcc -shared -o $(NAME) $(OBJ)
# I use .PHONY to make sure that gnu make will still run even if files called
# clean / fclean / all and re already exist in the directory
.PHONY: clean fclean all re
