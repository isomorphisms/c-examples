After electrical engineers worked out how (DNS, TCP) to send `0/1` electrical signals across a distributed (center-less, therefore indestructible) communication net, kernel engineers wrote software to organise the incoming data (IP) so it can be understood easier.



The steps to running a server are:


(beej.us)




The simplest server would just write out (to file and/or `tee` to screen) what it hears.

A more complex server might talk back to the sender and ask them to verify himself.

A **static file server** (HTML, CSS) might look for a pre-existing file (like a spinning wheel) on disk and send that spinning wheel to the user, who (being a human) sees the spinning wheel and thinks “Oh, it’s busy doing productive work.”

Servers could also do computations that could be deferred until later, on disk. For example instead of handing off the job of fixing up user profile images to another computer process, the server could do this itself.

Servers can also talk to and listen to other processes on the computer they are on (IPC). Sockets are how they do that.
