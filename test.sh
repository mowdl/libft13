#!/bin/zsh

norminette libft/*.c libft/libft.h
echo "--- Compiling libft"
(cd libft && make) &&
	echo "--- Running tests" &&
	(cd tests && cmake --build build && cd build && ctest)
