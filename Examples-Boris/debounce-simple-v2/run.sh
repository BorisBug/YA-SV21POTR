#compile STEP=0
#gcc debounce.c -DRUN_ON_PC -o debounce 

#compile STEP=1,2
gcc debounce.c -DRUN_ON_PC -lunity -o debounce 

#run
./debounce