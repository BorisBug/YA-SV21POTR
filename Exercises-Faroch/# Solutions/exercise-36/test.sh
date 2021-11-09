clear # Clear the terminal

mkdir -p build # Create the build directory

rm -f ./build/* # Delete files in build

gcc test.c ./lib/module.c -I./lib -lunity -o ./build/test # Compile the test program

./build/test # Run the test program
