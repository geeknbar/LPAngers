char getch(void)
{
  struct termios Config_stdin,OldConfig_stdin;
  char c ;

  tcgetattr(0,&Config_stdin);
  tcgetattr(0,&OldConfig_stdin);
  Config_stdin.c_iflag&=~(IXON|IXOFF);
  Config_stdin.c_lflag&=~(ICANON|ECHO|ISIG);
  Config_stdin.c_cc[VMIN]=0;
  Config_stdin.c_cc[VTIME]=0;
  tcsetattr(0,TCSANOW,&Config_stdin);
  while(read(0,&c,1)!=1);
  tcsetattr(0,TCSANOW,&OldConfig_stdin);

  return c;
}
