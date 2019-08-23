`nc -l 1984`

in a second terminal, `nc localhost 1984`

Type anything in the second terminal, it should appear in the first.



This is IPC. It uses sockets (a socket netcat opened). Your language (like R) might be able to do this between two different REPL's (?connection in R).
