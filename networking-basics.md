If you have never used DIG or traceroute, download BIND tools and traceroute and
then traceroute duckduckgo.com, traceroute . An alternative to BIND is djbdns,
use dnsip mx.mailgun.org or dnsip contact.plaid.com to see for example
CloudFront assigning several rotating IPv4 locations to 


https://serverfault.com/questions/49765/how-does-ipv4-subnetting-work

A very long, arrogant/shaming blogpost on Stackoverflow by Comic Book Guy. A
couple takeaways:

1. IPv4 addresses are really in binary. They are 4 bytes long. Each byte is
   separated by a dot.

##### why do I never see higher than 255 eg  `255.255.0.0`?

255 is the highest number expressible with 8 bits, i.e. 11111111 = 1 + 2 + 4 + 8
+ 16 + 32 + 64 + 128 = 255.

0 in “dotted-decimal” notation (IPv4’s notation) is also 00000000 in binary (one byte
long).



#### why some weird numbers are common like `192.168.0.0`?

They look simple in binary and make for good masks.

- 192 = 11000000
- 168 = 10101000



##### What is a subnet "mask"?


It’s something you `AND` with the IP address.



###### Why?

It’s to do with who got allocated lots of IPv4 addresses for internal use.




##### And what’s with the slash?

So-called CIDR notation is an even more decimal-ish alternative to binary.
255.255.255.0 in binary is

11111111 . 11111111 . 11111111 . 11111111 . 00000000

which, if you count the ones, is 8+8+8+8 = 24 ones. CIDR says call this /24 (and
you’re supposed to know they are contiguous on the left).










------

The quickest starting point for most computer words encountered by an early
systems programmer (you?), is drawings.jvns.ca.  (IP 104.28.7.94 or 104.28.6.94)

```
~: dig drawings.jvns.ca

; <<>> DiG 9.12.1 <<>> drawings.jvns.ca
;; global options: +cmd
;; Got answer:
;; ->>HEADER<<- opcode: QUERY, status: NOERROR, id: 56647
;; flags: qr rd ra; QUERY: 1, ANSWER: 2, AUTHORITY: 0, ADDITIONAL: 0

;; QUESTION SECTION:
;drawings.jvns.ca.		IN	A

;; ANSWER SECTION:
drawings.jvns.ca.	300	IN	A	104.28.7.94
drawings.jvns.ca.	300	IN	A	104.28.6.94

;; Query time: 67 msec
;; SERVER: 75.75.75.75#53(75.75.75.75)
;; WHEN: dork o'clock
;; MSG SIZE  rcvd: 66
```
