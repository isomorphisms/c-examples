// https://stackoverflow.com/a/4291100/563329

#include <stdio.h>
#include <unistd.h>


int main() {

extern char **environ;

int i = 0;
while(environ[i]){
  printf("%s\n", environ[i++]); // prints in form of "variable=value"
}


return 0;
}
