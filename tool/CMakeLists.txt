ADD_EXECUTABLE(cld2_detect detect.cc detect_langs.cc)
target_link_libraries(cld2_detect LINK_PUBLIC cld2-static)


