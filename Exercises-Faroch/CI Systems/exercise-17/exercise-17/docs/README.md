# Exercise 9

Using TDD make a program in team to get an expression as an argument from command line and check if it is correctly parenthesized or not.

To check if an expression is correctly parenthesized use a stack implemented by an array.

Parse the expression from left and when you reach an open parenthesis push it to the stack and when you reach a close parenthesis pop from the stack. In the end if the stack is empty, it means that the expression has correctly been parenthesized.

## Requirements

    Follow GitFlow Strategy (main and develop as the permanent branches)

    To buil and run the program and the tests, use make and a Makefile.

    Make 2 workflows which are run on Ubuntu by yourself.

        A workflow for develop with events push and pull_request to build and run the program and the tests.

        A woorkflow for main with event push to build and run the program and the tests, and to make a release. In the release you need to zip and store docs and the build program.

    When you are done with implementation, make merge develop into master. Ensure that a release will be created automatically.
