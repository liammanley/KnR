#!/bin/bash
cc remove_comments.c

./a.out <in1.c >my_out1.c
diff out1.c my_out1.c
./a.out <in2.c >my_out2.c
diff out2.c my_out2.c
./a.out <in3.c >my_out3.c
diff out3.c my_out3.c
./a.out <in4.c >my_out4.c
diff out4.c my_out4.c

rm a.out my_out1.c my_out2.c my_out3.c my_out4.c