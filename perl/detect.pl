use strict;
use Data::Dumper;
use CLD2;

while(<STDIN>) {
  print Dumper(CLD2::GetLang($_));
}