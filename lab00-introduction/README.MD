[![Open in Codespaces](https://classroom.github.com/assets/launch-codespace-2972f46106e565e64193e422d61a12cf1da4916b45550586e14ef0a7c637dd04.svg)](https://classroom.github.com/open-in-codespaces?assignment_repo_id=20600525)
# Lab 0: Basic C Programming

This lab introduces you to the C programming language and how lab lectures will be conducted. You will learn how to use the command line to compile, run your programs and submit your work. This would provide basic installation and setup instructions for the course. You will also learn how to use the `git` version control system to manage your code. 

## Setup

Every lab will be written in C and will be tested using github actions. The development environment will be a Linux based, it could be a virtual machine or a container. You will need a machine that could provide a Linux environment, such as a Linux machine, a Mac or a Windows machine with a Linux subsystem. I personally recommend using Ubuntu 20.04 LTS \[[1](https://ubuntu.com/download/desktop)\] as it is the most popular Linux distribution and it is well supported.
### Setup a Linux subsystem on Windows

Windows recently added a Linux subsystem that allows you to run a Linux environment on Windows. You can follow the instructions in \[[2](https://learn.microsoft.com/en-us/windows/wsl/install)\] to install the Linux subsystem on Windows or simply download Ubuntu 20.04 LTS from the Microsoft store \[[3](https://www.microsoft.com/en-us/p/ubuntu-2004-lts/9n6svws3rx71?activetab=pivot:overviewtab)\].

### Setup on Mac

MacOS is a Unix based operating system, so it is very similar to Linux. Most of Linux commands and programs are available on MacOS. To install the required software, you can use [Homebrew](https://brew.sh/), a package manager for MacOS. You can install Homebrew using the following command:

```bash
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
```

Then you can install the required software using the following command:

```bash
brew install git gcc make python3
```
### Install the required software

You will need to install the following software on your machine:

- [git](https://git-scm.com/downloads)
- [gcc](https://gcc.gnu.org/install/)
- [make](https://www.gnu.org/software/make/)
- [python3](https://www.python.org/downloads/)

You can install all of them using the following command on Ubuntu:

```bash
sudo apt-get update && sudo apt-get install -y git gcc make python3 build-essential
```

## Assignment


Before running the autograders, compile your code to create the testing program qtest:
```bash
make
```

Check the correctness of your code:
```bash
make test
```

### Using qtest:

qtest provides a command interpreter that can create and manipulate queues.

Run `./qtest -h` to see the list of command-line options

When you execute `./qtest`, it will give a command prompt "cmd>".  Type
"help" to see a list of available commands


### Files:

You will handing in these two files

`queue.h`                 Modified version of declarations including new fields you want to introduce
`queue.c`                 Modified version of queue code to fix deficiencies of original code

### Tools for evaluating your queue code
Makefile                Builds the evaluation program qtest
README                  This file
driver.py*              The C lab driver program, runs qtest on a standard set of traces

### Helper files

`console.{c,h}`:          Implements command-line interpreter for qtest

`report.{c,h}`:           Implements printing of information at different levels of verbosity

`harness.{c,h}`:          Customized version of malloc and free to provide rigorous testing framework

`qtest.c`                 Code for qtest

### Trace files

traces/trace-XX-CAT.cmd Trace files used by the driver.  These are input files for qtest.
                        
They are short and simple.  We encourage to study them to see what tests are being performed.

XX is the trace number (1-15).  CAT describes the general nature of the test.

traces/trace-eg.cmd:    A simple, documented trace file to demonstrate the operation of qtest