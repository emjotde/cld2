
#include <iostream>
#include <string>
#include "cld2/detect_langs.h"

int main(int args, char** argv) {
  std::string line;
  while(std::getline(std::cin, line)) {
    Langs l;
    LangRanges lr;
    bool rel = DetectLangs(line, l, lr);
    std::cout << rel << "\t"; 

    for(size_t i = 0; i < l.size(); ++i) {
      if(i > 0)
        std::cout << " ";
      std::cout << l[i].language << ":" << l[i].percent;
    }
    std::cout << "\t";
    for(size_t i = 0; i < lr.size(); ++i) {
      if(i > 0)
      std::cout << " ";
      std::cout << lr[i].language << ":[" << lr[i].offset 
        << "," << lr[i].length << "]";
    }
    std::cout << std::endl;
  }
  return 0;
}
