# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/07 17:18:05 by hed-dyb           #+#    #+#              #
#    Updated: 2023/03/24 14:37:24 by hed-dyb          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = so_long
BONUS_NAME = so_long_bonus
CC = cc 
FLAGS = -Wall -Werror -Wextra
MLXFLAGS = $(FLAGS) -lmlx -framework OpenGL -framework AppKit


FILES = mandatory/so_long.c mandatory/utils.c mandatory/ft_split.c \
		mandatory/check_map.c mandatory/validpath.c \
		mandatory/mlx.c mandatory/utils_mlx.c \
		mandatory/utils_mlx_2.c

BONUS_FILES = bonus/so_long_bonus.c bonus/utils_bonus.c bonus/ft_split_bonus.c \
		bonus/check_map_bonus.c bonus/validpath_bonus.c \
		bonus/mlx_bonus.c bonus/utils_mlx_bonus.c \
		bonus/animation_bonus.c bonus/extra_utils.c bonus/move_enemy.c

OBJ = $(FILES:%.c=%.o)#to create a list of .o from the coresponding .c(its like coping all .c and change .c with .o)

BONUS_OBJ = $(BONUS_FILES:%.c=%.o)#to create a list of .o from the coresponding .c(its like coping all .c and change .c with .o)


all : $(NAME)

bonus : $(BONUS_NAME)

$(NAME) : $(OBJ) # tells Make that the library $(NAME) should be built by archiving all the object files specified in $(OBJ)
	$(CC) $(MLXFLAGS) $(OBJ) -o $(NAME)

$(BONUS_NAME) : $(BONUS_OBJ) 
	$(CC) $(MLXFLAGS) $(BONUS_OBJ) -o $(BONUS_NAME)
	
%.o : %.c mandatory/so_long.h bonus/so_long_bonus.h
	$(CC) $(FLAGS) -c $< -o $@

clean :
	$(RM) $(OBJ)
	$(RM) $(BONUS_OBJ)

fclean : clean
	$(RM) $(NAME)
	$(RM) $(BONUS_NAME)


re : fclean all
.PHONY : clean fclean bonus
#***********************************************************#

# ==> a Rule example :
# target : prerequisites / dependencies
# 		commands

# in this exmapke :

# obj/%.o: src/%.c
#     gcc -c $< -o $@

#   $@     variable refers to the target name,(obj/%.o)
#   $<     variable refers to the prerequisite file name. (src/%.c).


# $(AR) $(NAME) $(OBJ) creates a static library file (or an >> archive file <<, is a file that contains a collection of object files (compiled code))



# =>  using       -c    : create an .o only - dont link it to create an executable.
# =>  not using   -c : the compiler will try to link the object file to create an executable.


#There are two types of wildcards commonly used in Makefiles: % and *#

#* (asterisk) matches any sequence of zero or more characters, including no characters at all.#
#For example, *.c matches any file that ends with .c, and src/*.c matches any .c file in the src/ directory.#
#% (percent sign) matches any sequence of characters, but only once.#
#For example, %.o matches any file that ends with .o, and obj/%.o matches any .o file in the obj/ directory.#

#the deference between * and %         #

# ====> The % wildcard can only be used in >>pattern<< (like %.o:%.c  you can use this rm %.c) rules, not in command lines.
# ====> the wildcard * is a character that represents any sequence of characters, including zero characters. 
#		It is often used in file name patterns to match multiple files with similar names. For example, the pattern *.txt matches any file with the .txt extension in the current directory. 
#		The * wildcard can also be used in other contexts, such as shell commands or regular expressions, to represent any sequence of characters.



#the rule %.o: %.c specifies that any target ending in .o depends on a prerequisite file ending in .c.#
#When you run make and it encounters a target like foo.o, it will look for a file named foo.c and apply the recipe to create the object file.#
#In summary, * is used to match multiple file names in a file name pattern, while % is used to match multiple target names in a pattern rule.#

# ======>    ar   command creates a static library file with the name specified by the $(NAME) variable, 
# and includes the object files specified in $(OBJ).

# ===> Static library, also known as an archive, is a collection of object files that are bundled together into a single file. The library is called "static" because the code is linked with the program at compile-time, and the resulting binary contains a copy of the library code.


# Deference between static and dynamic library 
# The main difference between a static library and a dynamic library is in how the code is linked with the program.
# In a static library, the code is linked at compile time, and the resulting binary file contains a copy of the library code. When you run the program, all the code it needs is already included in the executable, so it doesn't need to load any external libraries at runtime. This makes static libraries easy to use and deploy, but can result in larger executable files and can make it harder to update the library code.
# In a dynamic library, the code is linked at runtime, when the program is loaded into memory. The program uses a dynamic linker to find and load the necessary library code from a shared library file (.so on Linux, .dll on Windows). Because the library code is loaded at runtime, it can be shared between multiple programs, which can reduce memory usage and improve performance. Dynamic libraries are commonly used for system libraries that are frequently updated, such as libc.

# Here are some examples of static and dynamic libraries:

# Standard C library: 
# libc is a dynamic library that provides basic C functions, such as memory allocation, input/output, and string handling.
# Graphics library: OpenGL is a dynamic library that provides functions for rendering 2D and 3D graphics.
# Math library: libm is a static library that provides mathematical functions, such as trigonometry, logarithms, and exponential functions.
# Compression library: zlib is a static library that provides compression and decompression functions for the gzip and deflate formats.
# Networking library: libcurl is a dynamic library that provides functions for making HTTP requests and other network operations.


# ====> The steps that occur when compiling a C program:

# Preprocessing:(cpp example.c)
# The preprocessor scans the source code and performs textual replacements and 
# expansions of preprocessor directives. Preprocessor directives are instructions
#  to the preprocessor to perform certain actions before the code is compiled. 
#  These include #include statements, which insert code from other files, and 
#  #define statements, which define constants or macros. The output of this step 
#  is a preprocessed source code file.

# Compilation:(cc -S example.c)
# The compiler takes the preprocessed source code file and translates it into 
# assembly language. This involves parsing the source code to generate an 
# intermediate representation of the program, optimizing that representation, 
# and then generating assembly code from the optimized intermediate representation.

# Assembly:(cc -o example.c)
# The assembler takes the assembly code generated by the compiler and converts 
# it into object code, which is machine-readable code that can be executed directly
#  by the computer.

# Linking:
# If the program uses external libraries or other object files, the linker combines
#  the object code generated by the compiler with the object code from any necessary
#   libraries or other object files to create an executable file. The linker 
#   resolves symbols, which are references to functions or variables that are 
#   defined in other parts of the program or in external libraries, and creates
#    the final binary executable file.

# ===> most popular C compilers 

# gcc - GNU Compiler Collection:
# gcc is a popular and widely used C compiler. It is the default compiler on most 
# Unix-based systems, including Linux, and is also available for other platforms. 
# gcc is an open-source compiler that supports a wide range of programming languages, 
# including C, C++, and Objective-C. It includes a suite of tools for building and 
# debugging programs, such as gdb for debugging and make for building.

# clang - C Language Family Frontend for LLVM:
# clang is another popular C compiler. It is also open-source and supports a wide 
# range of programming languages, including C, C++, and Objective-C. clang is 
# designed to be compatible with gcc, and can often be used as a drop-in replacement
#  for gcc. One of the main differences between clang and gcc is that clang is 
#  designed to be modular and has a well-defined API, which makes it easier to 
#  integrate with other tools and libraries.

# CC ?
# cc and gcc are both C compilers, but gcc is a more feature-rich and powerful compiler
#  that is widely used and available on many platforms. cc is often used as a shorthand 
#  for the default C compiler on Unix-based systems, which is often gcc.

