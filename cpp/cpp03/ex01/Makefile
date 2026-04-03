# Nombre del proyecto
NAME = scav

# Compilador de C++
CXX = c++

# Flags para el compilador
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -Iheader

# Comando para eliminar archivos
RM = rm -f

# Archivos fuente
SRCS = src/ClapTrap.cpp
	   src/main.cpp
	   src/ScavTrap.cpp
# Archivos objeto
OBJS = $(patsubst src/%.cpp,%.o,$(SRCS))

# Target por defecto
all: $(NAME)

# Cómo compilar el binario
$(NAME): $(OBJS)
$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

# Cómo compilar archivos .o a partir de .cpp
%.o: src/%.cpp
$(CXX) $(CXXFLAGS) -o $@ -c $<

# Limpiar archivos objeto
clean:
$(RM) $(OBJS)

# Limpiar todo (binario + objetos)
fclean: clean
$(RM) $(NAME)

# Recompilar desde cero
re: fclean all

# Asegura que estos nombres no son archivos
.PHONY: all clean fclean re
