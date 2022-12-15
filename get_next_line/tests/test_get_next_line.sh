rm -r /nfs/homes/fheld/Documents/get_next_line/tests/source
cp -r ../source .
cd source
#norminette
cd ..
cc test_main.c test_add_to_line.c source/get_next_line.c source/get_next_line.h source/get_next_line_utils.c -Wall -Wextra -Werror
./a.out