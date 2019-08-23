I recommend playing with protocols with either netcat or telnet. For me telnet is more fun. Look up how to send an email by telnetting to port 25 of your SMTP server. If you just use gmail and don't have a dork server, `ssh new@sdf.org` and make an account there. From within `ssh your_cool_8_letter_username@sdf.org` you will be able to `telnet 205.166.94.20 25` and say `EHLO`.


```
~: dig mx.sdf.org

; <<>> DiG 9.12.1 <<>> mx.sdf.org
;; global options: +cmd
;; Got answer:
;; ->>HEADER<<- opcode: QUERY, status: NOERROR, id: 31476
;; flags: qr rd ra; QUERY: 1, ANSWER: 1, AUTHORITY: 0, ADDITIONAL: 0

;; QUESTION SECTION:
;mx.sdf.org.			IN	A

;; ANSWER SECTION:
mx.sdf.org.		43200	IN	A	205.166.94.20

;; Query time: 571 msec
;; SERVER: 75.75.75.75#53(75.75.75.75)
;; WHEN: Loser O'Clock
;; MSG SIZE  rcvd: 44
```


