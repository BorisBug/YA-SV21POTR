# LEDs Driver

## A Single Instance Module & Dual Targeting.

To Compile and run the test run the commands below:

    clear && mkdir -p build && rm -rf ./build/* && gcc ./lib/driver/driver.c ./test/test.c -I./lib/driver -lunity -o ./build/test && ./build/test
