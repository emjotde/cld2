#pragma once

#include <string>
#include <vector>

namespace CLD2 {

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

bool DetectLangs(const std::string& text, Langs& langs, LangRanges& langRanges);

}