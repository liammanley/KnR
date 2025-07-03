#!/bin/bash
cc remove_comments_cpp.c

./a.out <cpp_input.c >my_cpp_output.c
diff cpp_output.c my_cpp_output.c

rm a.out my_cpp_output.c