use 5.018002;
use Inline::MakeMaker;
# See lib/ExtUtils/MakeMaker.pm for details of how to influence
# the contents of the Makefile that is written.
WriteMakefile(
    NAME              => 'CLD2',
    VERSION_FROM      => 'lib/CLD2.pm', # finds $VERSION
    PREREQ_PM         => {}, # e.g., Module::Name => 1.1
    ($] >= 5.005 ?     ## Add these new keywords supported since 5.005
      (ABSTRACT_FROM  => 'lib/CLD2.pm', # retrieve abstract from module
       AUTHOR         => 'Marcin Junczys-Dowmunt <marcinj@>') : ()),
);
