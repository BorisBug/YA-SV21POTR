clear
gcc test/list.c module/list.c -Wall -Werror -Wpedantic -Wextra -oout -Imodule/ -lunity
./out
rm out