### What is a parser?

Text† needs to be loaded from disk into memory so you can do things with it. Things like, pull out one column of a `.csv` file or shrink an image into a thumbnail.

Data is gotten from the file with filehandles and seeking.

Data is interpreted into memory with the `scanf` command. For example K&R C example 1.1:


```
[copy program]
```



Once the bytes have been `scan`ned and given a `type` you can perform an operation on them, like capitalising a letter or adding two numbers. Read † below to understand why it’s necessary to know if the byte was numerical or `char`acter first. As well as why there is more than one meaning of "numerical" and "character".




###### You can’t do any work until the data is actually in memory.
So either somebody else already parsed this for you (as in the case of R `?data` command) or you must get it into memory yourself. Before you can even begin work.







† Text has some encoding, so for example hexadecimal `00 54 65 78 74` is the ASCII‡ standard designers’ agreed places to put the letters `T e x t`. If the computer thinks those bytes are numbers, then for example capital `T` = hex `54` = binary `01010100` = □⬛□⬛□⬛□□ would (1□2□4⬛8□16⬛32□64⬛128□) add up to 4+16+64 = 84, the decimal* number. If instead of ASCII-text or decimal-numbers (or signed integer … or floating-point …) the byte was part of an image (formatted how?!) or a song (formatted how?!?!) or a movie, …… that same `01010100` = □⬛□⬛□⬛□□ would mean different things.§ And as part of a longer sequence, hex `0x54` might be half of a CJK character in the Big 5 encoding.

Notice that `text` and `Text` don’t look even remotely similar to the computer, in binary. (hex `54 65 78 74` versus `74 65 78 74`) This is why names of files, functions, variables, and so on are totally distinct and `shakira` won’t sort next to `Shakira` or `ShAkirA` in your music folder, without the `sort` programmer explaining to the computer that `s` = hex `73` = binary  and `S` = hex `53` = binary are actually the same. (And doing so with the rest of the letters as well.)

Similarly for movie, audio, image, or database — but harder.

Various URL separators like `-`, `_`, and `%20` (` `) also have very different raw-bit representations. Even though people want to use them for the same thing.

The problem is even harder  for `"` vs `”`, where the `”` byte implies that some larger amount of text must be remembered (in memory), so that we can find back to the `“` it pairs with.



‡ `/usr/share/misc` or `man ascii` on a mac

* hex `0x54` has a different base; `84` = 8 &times; ten + 4 &times; one in our usual sense of ten fingers.             Hexadecimal `0x54` indicates 5 &times; sixteen + 4 &times; one.




§ In the case of video, a lone byte might not be interpretable because the natural units are larger. Sometimes the program needs to look at an entire file, packet, or stream to interpret a byte. For example consider sending a CSS background image over the internet. The information we eventually want is wrapped in several layers of transmission information (TCP, IP, DNS). Various other parts of the computer (like the kernel) will strip off & read the wrapping they need to e.g. tell the next program that “What follows, for the next ___ bytes, will be a PNG image — so read the bytes that way”.










#### What is a "raw" byte?

One that isn’t interpreted into a variable with any type. You can still do bitwise operations like flipping `01010100` into `10101011`, XOR'ing or AND'ing two equal-length bitstrings, and so on — without knowing whether those bits represent an internet IP packet, a gzipped image, the header of a `.wav` file, or an encrypted Morse code from the Nazis.
