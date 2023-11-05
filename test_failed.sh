#!/bin/zsh

echo "--- Compiling libft"
(cd libft && make) &&
	echo "--- Running tests" &&
	(cd tests && cmake --build build && cd build && ctest --rerun-failed --output-on-failure)
