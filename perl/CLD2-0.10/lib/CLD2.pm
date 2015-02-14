package CLD2;

use 5.018002;
use strict;
use warnings;


require Exporter;

our @ISA = qw(Exporter);

our %EXPORT_TAGS = ( 'all' => [ qw(
 GetLang
) ] );

our @EXPORT_OK = ( @{ $EXPORT_TAGS{'all'} } );

our @EXPORT = qw(
	
);

our $VERSION = '0.10';

use Inline 'CPP' => 'DATA', VERSION => '0.10', NAME => 'CLD2';
use Inline 'CPP' => config => libs => '-lcld2';


# Preloaded methods go here.

1;
__DATA__

__CPP__

#include <string>
#include <cld2/detect_langs.h>

SV* GetLang(char* in) {
  CLD2::Langs l;
  CLD2::LangRanges lr;
  bool rel = CLD2::DetectLangs(in, l, lr);

  AV* langs = newAV();
  for(size_t i = 0; i < l.size(); ++i) {
    HV* pl = newHV();
    hv_store(pl, "language", 8, newSVpvn(l[i].language.c_str(), l[i].language.length()), 0);
    hv_store(pl, "percent", 7, newSViv(l[i].percent), 0);
    av_push(langs, newRV_noinc((SV*) pl));
  }

  AV* ranges = newAV();
  for(size_t i = 0; i < lr.size(); ++i) {
    HV* plr = newHV();
    hv_store(plr, "language", 8, newSVpvn(lr[i].language.c_str(), lr[i].language.length()), 0);
    hv_store(plr, "offset", 6, newSViv(lr[i].offset), 0);
    hv_store(plr, "length", 6, newSViv(lr[i].length), 0);
    av_push(ranges, newRV_noinc((SV*) plr));
  }

  HV* all = newHV();
  hv_store(all, "guesses", 7, newRV_noinc((SV*) langs), 0);
  hv_store(all, "ranges", 6, newRV_noinc((SV*) ranges), 0);

  return newRV_noinc((SV*) all);
}
