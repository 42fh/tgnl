run_tests()
{
	i=$1
    cc test_main_full.c source/get_next_line.c \
    source/get_next_line.h source/get_next_line_utils.c -Wall -Wextra -Werror -D BUFFER_SIZE=$i
	./a.out files/h0
	./a.out files/h1
	./a.out files/h2
	./a.out files/h3
	./a.out files/h4
	./a.out files/h5

	tr -dc 'a-zA-Z\012' </dev/urandom | head -c 1000 > n3s3hw2ar83ujebp6tnm
	./a.out n3s3hw2ar83ujebp6tnm
	rm n3s3hw2ar83ujebp6tnm

}


rm -r /nfs/homes/fheld/Documents/get_next_line/tests/source
cp -r ../source .
cd source
norminette
cd ..
cc test_arbit_fd.c source/get_next_line.c source/get_next_line.h \
source/get_next_line_utils.c -Wall -Wextra -Werror
./a.out

run_tests 5
run_tests 20

echo "\nDone \n"
