cmake_minimum_required(VERSION 3.25)
project(cpp_learn)

# Upgrade from C++14 to modern C++23 so we can use std::print, ranges, etc.
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find every single .cpp file anywhere inside the Projects folder
file(GLOB_RECURSE ALL_CPP_FILES "Projects/*.cpp")

foreach(SOURCE_FILE ${ALL_CPP_FILES})
    # Extract the file name without extension (e.g., "std_move")
    get_filename_component(FILE_NAME ${SOURCE_FILE} NAME_WE)

    # Extract the folder name it lives in (e.g., "Move")
    get_filename_component(PARENT_DIR ${SOURCE_FILE} DIRECTORY)
    get_filename_component(FOLDER_NAME ${PARENT_DIR} NAME)

    # Check if it belongs to Part 1 or Part 2 to keep things organized
    if(SOURCE_FILE MATCHES "Part_1")
        set(PREFIX "P1")
    elseif(SOURCE_FILE MATCHES "Part_2")
        set(PREFIX "P2")
    else()
        set(PREFIX "Misc")
    endif()

    # Skip main.cpp files inside Header folders if they need to link with local classes
    # (This prevents duplicate target names if you have multiple 'main.cpp' files)
    if(FILE_NAME STREQUAL "main")
        set(TARGET_NAME "${PREFIX}_${FOLDER_NAME}_executable")
    else()
        set(TARGET_NAME "${PREFIX}_${FOLDER_NAME}_${FILE_NAME}")
    endif()

    # Create an independent, runnable program for this specific file!
    add_executable(${TARGET_NAME} ${SOURCE_FILE})

    # Special fix for your Headers concept: link Country.cpp with its main executable
    if(SOURCE_FILE MATCHES "Projects/Part_2/Headers/")
        # This ensures the Headers target includes both the main and the class implementation
        if(TARGET_NAME STREQUAL "P2_Headers_executable")
            target_sources(${TARGET_NAME} PRIVATE "Projects/Part_2/Headers/Country.cpp")
        endif()
    endif()
endforeach()
