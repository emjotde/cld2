ADD_LIBRARY(cld2 OBJECT
  cldutil.cc cldutil_shared.cc compact_lang_det.cc compact_lang_det_hint_code.cc
  compact_lang_det_impl.cc  debug.cc fixunicodevalue.cc
  generated_entities.cc  generated_language.cc generated_ulscript.cc
  getonescriptspan.cc lang_script.cc offsetmap.cc  scoreonescriptspan.cc
  tote.cc utf8statetable.cc
  cld_generated_cjk_uni_prop_80.cc cld2_generated_cjk_compatible.cc
  cld_generated_cjk_delta_bi_32.cc generated_distinct_bi_0.cc
  cld2_generated_quad0122.cc cld2_generated_deltaocta0122.cc
  cld2_generated_distinctocta0122.cc cld_generated_score_quad_octa_0122.cc
)

SET_TARGET_PROPERTIES(cld2 PROPERTIES COMPILE_FLAGS "-fPIC")

ADD_LIBRARY(cld2-static STATIC $<TARGET_OBJECTS:cld2>)
SET_TARGET_PROPERTIES(cld2-static
  PROPERTIES OUTPUT_NAME cld2
  CLEAN_DIRECT_OUTPUT 1)

ADD_LIBRARY(cld2-dynamic SHARED $<TARGET_OBJECTS:cld2>)
SET_TARGET_PROPERTIES(cld2-dynamic
  PROPERTIES OUTPUT_NAME cld2
  CLEAN_DIRECT_OUTPUT 1)

install (TARGETS cld2-dynamic DESTINATION lib)
install (TARGETS cld2-static DESTINATION lib)

install(FILES compact_lang_det.h encodings.h DESTINATION include/cld2)