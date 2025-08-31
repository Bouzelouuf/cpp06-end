# Nom de l'exécutable
NAME = serialize_test

# Compilateur et flags
CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Fichiers sources
SRCS = main.cpp Data.cpp Serializer.cpp

# Fichiers objets (automatique)
OBJS = $(SRCS:.cpp=.o)

# Règle par défaut : build
all: $(NAME)

# Lien des objets pour créer l'exécutable
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

# Compilation des .cpp en .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Supprimer les fichiers objets et l'exécutable
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

# Rebuild complet
re: fclean all

.PHONY: all clean fclean re
