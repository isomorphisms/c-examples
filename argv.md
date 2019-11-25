#### What is `argc`?

The number of arguments which will be passed into a function.


##### What if I want the function to be variadic?

I don't know.


#### What is `argv[0]`?

The name of the program.


##### Why?

[see picture of process / memory organisation struct from mit xv6]


##### Have I seen this somewhere else?

Yes, in perl `$0` is also the name of the program.

[ruby example?]


### What is `argv`?

An array (=equal-length boxes stacked `N` long) containing the `arguments` which will be passed to the function.



#### What is the standard format for `int main`?

```
#includes

//globals
//possibly functions


int main(int argc, char* argv[])
{
	//the program
	return(0);
	}

//maybe more functions
```


##### Why the `return(0)`?

[xv6 answer]


##### Is that really a function?

No, it's not a mathematical function. Computer people just like to mis-use maths words to intimidate you.



##### What's the larger context for these instructions?

The instructions sit in a plain text file. You need to "build" them into a program. Building them requires a lexer+tokenizer to scan the text, a compiler to turn the parsed text into something closer to computer instructions, and a linker (`man ld`, `man ar`, `man nm`) to bring stuff from various places (like `#include <graphics.h>` or `#include <tty.h>`) into the executable you're building.

This multi-step process might be driven by a `Makefile`. `make` is a scripting language with a horrendously long manual which nobody actually likes but which does the job of scanning for requirements and dependencies and then executing instructions only if a job actually needs to be done.



##### Why are there curly braces `{}` and semicolons `;`?

It makes the job of scanning and tokenising your text instructions easier. If you didn't terminate a line with `;` then the person writing the compiler would have to infer what you almost certainly meant (but remember, they wrote the compiler without talking to you or looking at your code).

