# SubterraneanRose Window Manager Module

aux_source_directory(./src wm_src_list)
add_library("srose-wm" STATIC ${wm_src_list})
target_include_directories("srose-wm" PUBLIC ./include)

target_link_libraries("srose-wm" PUBLIC "srose-core")
target_link_libraries("srose-wm" PUBLIC "srose-gpu")
target_link_libraries("srose-wm" PUBLIC "srose-ext-imgui")
target_link_libraries("srose-wm" PUBLIC "srose-imguisr")

add_subdirectory(./imguisr)
