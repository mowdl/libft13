#!/bin/zsh

norminette libft/*.c libft/libft.h
echo "--- Compiling libft"
(cd libft && make && make bonus) &&
	echo "--- Running tests" &&
	(cd tests && cmake --build build && cd build && ctest || ctest --rerun-failed --output-on-failure)
