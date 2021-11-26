# Libasm 
(42 subject) A library containing some basic functions for assembly x86.

## Table of Content

* [Technologies](#technologies)
* [Description](#description)
* [Installation](#installation)
* [Usage](#usage)
* [Utility](#utility)
* [Contributing](#contributing)

## Technologies

Project is created with:
* nasm 2.14.02

## Description

The aim of this project is to create a library containing the following funtions:
* read()
* write()
* strcpy()
* strcmp()
* strdup()
* strlen()
Those functions must have the same behavior that the original ones. Of course, it must be coded in asm x86 for performance issues.

## Installation

Just pull the project !\
"Make" in the cloned repository and move the library "libasm.a" wherever you want.

## Usage

Classic 42 Makefile:
````sh
make		#compiles everything and create libasm.a library
make clean	#removes all the .o files
make fclean	#removes all the .o files and the library
make re		#cleans everything in the project and compiles everything again
````

Specific to the project:
````sh
make test   #compiles main.c in order to compare my functions with the original ones
./asm_test	#launch the comparison
````

## Utility

Though assembly x86 will not be of use every day, it is still useful in some areas of expertise to make some very optimised code (cybersecurity for example).\
It can save you some precious ms on your program if you have to do a lot of system calls.

## Contributing

Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.
