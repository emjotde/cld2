
#include <iostream>
#include <string>
#include "cld2/compact_lang_det.h"

struct LangPercent {
  std::string language;
  int percent;
};

typedef std::vector<LangPercent> Langs;

struct LangRange {
  std::string language;
  int offset;
  int length;
};

typedef std::vector<LangRange> LangRanges;

void DetectLangs(const std::string& text, Langs& langs, LangRanges& langRanges) {
  CLD2::Language l[3];
  int p[3];
  double n[3];
  int tb;
  bool reliable;
  int vb;
  CLD2::ResultChunkVector rcv;

  CLD2::ExtDetectLanguageSummaryCheckUTF8(text.c_str(), text.length(), true,
    NULL, 0, l, p, n, &rcv, &tb, &reliable, &vb);

  for(size_t i = 0; i < 3; i++) {
    if(p[i] || i == 0) {
       LangPercent lp = {CLD2::LanguageCode(l[i]), p[i]};
       langs.push_back(lp);
    }
  } 
  for(size_t i = 0; i < rcv.size(); ++i) {
    LangRange lr = {CLD2::LanguageCode(static_cast<CLD2::Language>(rcv[i].lang1)),
      rcv[i].offset, rcv[i].bytes};
    langRanges.push_back(lr);
  }
}

int main(int args, char** argv) {
  std::string line;
  while(std::getline(std::cin, line)) {
    Langs l;
    LangRanges lr;
    DetectLangs(line, l, lr);

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
