#include <iostream>
#include <fstream>

int main(int argc,char **argv){
  std::ofstream file;
  int size=0,sortsize=0;
  float sort=0;

  for (int i=1; i<argc; i++){
    if (argv[i][0] != '-') return 1;
    switch (argv[i][1]) {
    case 'n':{
      i++;
      sscanf(argv[i],"%d",&size);
    } break;
    case 's':{
      i++;
      sscanf(argv[i],"%f",&sort);
    }break;
  }}
  std::cout<<size<<std::endl;
  std::cout<<sort<<std::endl;
  sortsize=size*sort/100;
  std::cout<<sortsize<<std::endl;
  for(int i=0;i<100;i++){
    file.open(std::to_string(i));
    for(int i=0;i<size;i++){
      if(i<sortsize) file<<i<<std::endl;
      else file<<rand() % 99999999 + sortsize<<std::endl;
    }
    file.close();
  }
  return 0;
}
