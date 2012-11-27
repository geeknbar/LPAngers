#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>

int main(){
  struct dirent *lecture;
  DIR *rep;
  rep = opendir("." );
  while ((lecture = readdir(rep))) {
    printf("%s\n", lecture->d_name);
    
  }
  closedir(rep);
}

