clear
gcc exercise-37.c -Wall -o out
./out 25 + 35
./out 100 - 88
./out 20 / 4
./out 3 '*' 5
./out 33 % 10
./out 1 ? 1
./out 300 % 0
./out 222 / 0

a=10; b=3; op="%"; # op can be "+", "-", "//", "* ", "%"
./out $a "$op" $b

a=23; b=5; op="*"; # op can be "+", "-", "//", "* ", "%"
./out $a "$op" $b

rm out
