#include <iostream>
#include <fstream>

int main(int argc,char **argv){
  std::ofstream file;
  int size=0,revert=0;

  for (int i=1; i<argc; i++){
    if (argv[i][0] != '-') return 1;
    switch (argv[i][1]) {
    case 'n':{
      i++;
      sscanf(argv[i],"%d",&size);
    } break;
  }}
  std::cout<<size<<std::endl;
  revert=10*size;
  for(int i=0;i<100;i++){
    file.open(std::to_string(i));
    for(int i=0;i<size;i++){
        file<<revert<<std::endl;
        revert--;
    }
    file.close();
  }
  return 0;
}
