#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

#include <sys/select.h>
#include <sys/time.h>

#include "errno.h"
#include <termios.h>

#include <sys/epoll.h>

int main(){

  int _ubloxHandle = open("/dev/ttyLF1", O_RDONLY );
  if(_ubloxHandle<0)
  {
    printf("open ttyLF1 error\n");
    exit(1);
  }

  termios options;
  tcgetattr(_ubloxHandle,&options);
  tcflush(_ubloxHandle,TCIOFLUSH);
  options.c_lflag &=~ ECHO;
  tcsetattr(_ubloxHandle,TCSANOW,&options);
  tcflush(_ubloxHandle,TCIOFLUSH);

  timeval tv;
  tv.tv_sec = 0;
  tv.tv_usec = 500000;
/*
  char _buf[1024];
  memset(_buf, 0, sizeof(_buf));
  fd_set readset;
  int z = 0;

  while(1){
    FD_ZERO( &readset );      
    FD_SET( _ubloxHandle, &readset );
    z = select( _ubloxHandle + 1, &readset, NULL, NULL, &tv);
    if(z > 0)
    {
      if( FD_ISSET(_ubloxHandle, &readset) )
      {
        memset(_buf, 0, sizeof(_buf));
        read( _ubloxHandle, _buf, sizeof(_buf) );
        printf("%s", _buf);
        memset(_buf, 0, sizeof(_buf));
      }
    }
  }
*/

  int epollfd = epoll_create1(0);
  struct epoll_event ev,events;

  while()

  return 0;
}