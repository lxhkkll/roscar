file(REMOVE_RECURSE
  "interface_automoc.cpp"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/vision_pro_generate_messages_nodejs.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()