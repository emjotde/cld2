#include "cld2/detect_langs.h"
#include "cld2/compact_lang_det.h"

namespace CLD2 {

bool DetectLangs(const std::string& text, Langs& langs, LangRanges& langRanges) {
  CLD2::Language l[3];
  int p[3];
  double n[3];
  int tb;
  bool reliable = false;
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

  return reliable;
}

}