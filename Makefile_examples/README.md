
## What is `make`?

It's a small scripting language.

`make` was designed to organise long shell commands like `cc -o runnable_program_name main.o kbd.o io.o display.o`, which only need to be run if one of `main.o`, `kbd.o`, `io.o`, `display.o` have changed since the last time `cc -o runnable_program_name` was run.

In other words, `make` checks *dependencies* to see if they were updated, then runs some programs only if they were.


## Can I see an example program?

Yes. Here's one from section 2.2 of `info make`.

Here is a straightforward makefile that describes the way an executable
file called 'edit' depends on eight object files which, in turn, depend
on eight C source and three header files.

   In this example, all the C files include 'defs.h', but only those
defining editing commands include 'command.h', and only low level files
that change the editor buffer include 'buffer.h'.

     edit : main.o kbd.o command.o display.o \
            insert.o search.o files.o utils.o
             cc -o edit main.o kbd.o command.o display.o \
                        insert.o search.o files.o utils.o

     main.o : main.c defs.h
             cc -c main.c
     kbd.o : kbd.c defs.h command.h
             cc -c kbd.c
     command.o : command.c defs.h command.h
             cc -c command.c
     display.o : display.c defs.h buffer.h
             cc -c display.c
     insert.o : insert.c defs.h buffer.h
             cc -c insert.c
     search.o : search.c defs.h buffer.h
             cc -c search.c
     files.o : files.c defs.h buffer.h command.h
             cc -c files.c
     utils.o : utils.c defs.h
             cc -c utils.c
     clean :
             rm edit main.o kbd.o command.o display.o \
                insert.o search.o files.o utils.o

-----


## Why is the GNU make manual so long?

Because programmers are bad people.


### Where could I find some shorter explanations?

Karl Broman wrote one.




# Can I use `make` for something besides running compiler, linker, assembler, loader, of C programs?

*YES*. It can be used to encode other shell scripts and sysadmin tasks, and may be better than a bash function for this.

For example https://www.youtube.com/watch?v=k7zseUhaXeU this sysadmin uses `make` along with short `alias`es to remember and quickly execute special `ssh` commands for particular AWS nodes, and for certain kubernetes commands.
