cmake_minimum_required(VERSION 3.25)
project(cpp_learn)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 1. Define library/helper files that do NOT contain main() (include file extensions)
set(HELPER_SOURCES
        "Country.cpp"
)

# Find every single .cpp file anywhere inside the Projects folder
file(GLOB_RECURSE ALL_CPP_FILES "Projects/*.cpp")

foreach(SOURCE_FILE ${ALL_CPP_FILES})
    # Use NAME to keep the extension (e.g., "Country.cpp") for the matching check
    get_filename_component(FILE_WITH_EXT ${SOURCE_FILE} NAME)
    get_filename_component(FILE_NAME ${SOURCE_FILE} NAME_WE)
    get_filename_component(PARENT_DIR ${SOURCE_FILE} DIRECTORY)
    get_filename_component(FOLDER_NAME ${PARENT_DIR} NAME)

    # 2. Skip library files so CMake does not create executable targets for them
    if(FILE_WITH_EXT IN_LIST HELPER_SOURCES)
        continue()
    endif()

    if(SOURCE_FILE MATCHES "Part_1")
        set(PREFIX "P1")
    elseif(SOURCE_FILE MATCHES "Part_2")
        set(PREFIX "Part2")
    else()
        set(PREFIX "Misc")
    endif()

    if(FILE_NAME STREQUAL "main")
        set(TARGET_NAME "${PREFIX}_${FOLDER_NAME}_executable")
    else()
        set(TARGET_NAME "${PREFIX}_${FOLDER_NAME}_${FILE_NAME}")
    endif()

    string(REPLACE " " "_" TARGET_NAME ${TARGET_NAME})

    add_executable(${TARGET_NAME} ${SOURCE_FILE})

    # 3. Attach helper implementations to the targets that require them
    if(SOURCE_FILE MATCHES "Projects/Part_2/Headers/")
        if(FILE_NAME STREQUAL "main")
            target_sources(${TARGET_NAME} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/Projects/Part_2/Headers/Country.cpp")
        endif()
    endif()

    if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
        target_link_libraries(${TARGET_NAME} PRIVATE stdc++exp)
    endif()
endforeach()