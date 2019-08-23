## What are types? Why are they necessary?

The bits `11001010 01101101` don’t mean anything without a dictionary. That same
pattern could be used to represent text, numbers, part of an image, part of a
mp3 file, or an IP address.

Engineers (often long-ago engineers) defined standards for what bytes should
mean what. For example the ASCII standard (`man ascii`) says which 7-bit pattern
indicates which (majuscule or minuscule) English letter.

MPEG-4 is another standard.


SQLite (a common database) defines its standard [here].



If you don’t know what the bits will be used for---MPEG, PNG, MP3, sqlite3,
plain ascii, Big 5, unsigned integer, integer, float----then those bits have
come from any of those formats . (Unless you are a code
cracker; then you might do the work yourself of figuring out that `ajelks` isn’t
a likely word so the underlying bits must be of a different type.)



###### sidebar
There’s nothing mathematical about these encodings---nothing spiritual, eternal,
or necessary. You couldn’t infer the ASCII encoding from logic.





#### How do types come up in programming?


You declare `int x` to tell C how to interpret those bits.

How a language should treat types is debated in PLT.
