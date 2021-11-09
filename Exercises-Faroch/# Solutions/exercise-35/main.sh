clear # Clear the terminal

mkdir -p build # Create the build directory

rm -f ./build/* # Delete files in build

gcc main.c ./lib/module.c -I./lib -o ./build/main # Compile the main program

./build/main # Run the main program
