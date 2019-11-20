per MIT xv6.

An operating system's job is to share a computer. Multiple "processes" (=instructions + data + stack) want to access hardware resources, like the CPU, the NIC, or buses.

Operating systems also provide nicer API's than what the manufacturer's hardware-instructions manual describes. Or, at least, you're hoped to think they're nicer.

Unix's famous design choice was to tell those who want to "write" the same thing, whether they are "writing" to a file (on disk), to a network connection (via the NIC, but also via TCP or UDP or ...), to a database (local, remote, distributed), or to a fortune cookie carried by a pigeon.    The work of implementing standardised "write" instructions on TCP, database, or pigeon-paper, is left to the worker on the other side of that API.

The meaning of "operating system" and process-sharing shows up in advanced topics like:
- Xen
- RedHat's CNCF | open-container alternatives to Docker
- Puppet VM
- freeRTOS


- chroot


Xen is used by web hosts like Liquidweb or Bluehost to split an often-idle machine into different full-hosts for different paying clients.   Amazon cloud does similar stuff.

freeRTOS is a bare-bones operating system designed to fit on a small chip. It's "real-time" in the sense that you would feel comfortable running it inside a car. Sensors for the car may compete for resources, but the "real-time" OS can *never* lock up. So it chooses to bail old processes aggressively.
