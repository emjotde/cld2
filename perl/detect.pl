use strict;
use Inline 'CPP';
use Inline 'CPP' => config => libs => '-lcld2';

while(<STDIN>) {
  print GetLang($_), "\n";
}

__END__
__CPP__

#include <string>
#include <cld2/detect_langs.h>

char* GetLang(char* in) {
  CLD2::Langs l;
  CLD2::LangRanges lr;
  bool rel = CLD2::DetectLangs(in, l, lr);
  return const_cast<char*>(l[0].language.c_str());
}
