file(REMOVE_RECURSE
  "interface_automoc.cpp"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/sensor_msgs_generate_messages_lisp.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
