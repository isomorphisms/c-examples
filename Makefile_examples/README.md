
## What is `make`?

It's a small scripting language.

The commands look like `make`, `make clean`, `make install`, `make dep`, `make distclean`, `make uninstall-data`, `make pack`, `make love`*, `make spec`, `make publish`, `make tag`. As with `git`, these are two-word commands. †




`make` was designed to organise long shell commands like ` arm-none-eabi-gcc -o runnable_program_name -mcpu=cortex-m0plus -mthumb --specs=nosys.specs -Wall -c main.o kbd.o io.o display.o`, which only need to be run if one of `main.o`, `kbd.o`, `io.o`, `display.o` have changed since the last time `cc -o runnable_program_name` was run.

You can imagine that typing ____ correctly over and over might be difficult, and yet there you may need to change the call in important ways, so Ctrl+R'ing for `cc` wouldn’t be easy either. Hence building a lever-box: `make`.

In other words, `make` checks *dependencies* to see if they were updated, then runs some programs only if they were.


## Can I see an example program?

Yes. Here's one from section 2.2 of `info make`.

Here is a straightforward makefile that describes the way an executable
file called 'edit' depends on eight object files which, in turn, depend
on eight C source and three header files.

   In this example, all the C files include 'defs.h', but only those
defining editing commands include 'command.h', and only low level files
that change the editor buffer include 'buffer.h'.

     edit : main.o kbd.o command.o display.o insert.o search.o files.o utils.o
            cc -o edit main.o kbd.o command.o \
		 display.o insert.o search.o files.o



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





## What is `.PHONY`?

https://stackoverflow.com/questions/2145590/what-is-the-purpose-of-phony-in-a-makefile

stackoverflow.com/a/2145605

> sometimes you want your Makefile to run commands that do not represent physical files in the file system.
Good examples for this are the common targets "clean" and "all". Chances are this isn't the case, but you may
potentially have a file named clean in your main directory. In such a case Make will be confused because by default
the clean target would be associated with this file and Make will only run it when the file doesn't appear to be
up-to-date with regards to its dependencies.
> 
> These special targets are called phony and you can explicitly tell Make they're not associated with files, e.g.:
> 
> ```
> .PHONY: clean
> clean:
>   rm -rf *.o
> ```
> 
> Now make clean will run as expected even if you do have a file named clean.
> 
> In terms of Make, a phony target is simply a target that is always out-of-date



^ The answerer, Eli Bendersky, writes excellent tech documentation. http://eli.thegreenplace.net has information about ELF files and other stuff. His writing is readable, unlike almost all programmers’ writing.





### Where would I find some sample `Makefile`s?

On github, and nowadays they may be packaged with `Dockerfile`s.

I store software I install in `/opt`, so `find /opt -name "Makefile"`  (no `=` in `-name "Makefile"`) lists some for me.

You can also look in `/usr/lib`, `/usr/include`, or `/usr/share`. `find /usr/lib -name "Makefile"` for me found global node modules like vue-cli and sails, which used Makefiles.


Lastly, for mac and windows users, homebrew and chocolatey install to places you can find via their documentation. Something like `/usr/local/Cellar/....`.









































* https://github.com/moll/json-stringify-safe/blob/master/Makefile#start-of-content


 `make` alone, just the one word, runs the first verb defined in the Makefile.

† Unfortunately, two-word (with space ` ` not `_`) things cannot be `alias`ed or made function of, easily in bash. https://stackoverflow.com/questions/10169582/create-multi-word-alias-in-bash https://stackoverflow.com/questions/40654352/how-to-write-an-alias-for-two-words 
