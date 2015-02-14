
#include <iostream>
#include <string>
#include "cld2/compact_lang_det.h"

int main(int args, char** argv) {
  std::string line;
  while(std::getline(std::cin, line)) {
    std::cout << line << std::endl;
    
    CLD2::Language l[3];
    int p[3];
    double n[3];
    int tb;
    bool reliable;
    int vb;

    CLD2::ExtDetectLanguageSummaryCheckUTF8(line.c_str(), line.length(), true, 
      NULL, 0, l, p, n, NULL, &tb, &reliable, &vb);

    std::cout << CLD2::LanguageCode(l[0]) << ":" << p[0] << std::endl;
  }
  return 0;
}

/*
Language ExtDetectLanguageSummaryCheckUTF8(
                          const char* buffer,
                          int buffer_length,
                          bool is_plain_text,
                          const CLDHints* cld_hints,
                          int flags,
                          Language* language3,
                          int* percent3,
                          double* normalized_score3,
                          ResultChunkVector* resultchunkvector,
                          int* text_bytes,
                          bool* is_reliable,
                          int* valid_prefix_bytes);

*/