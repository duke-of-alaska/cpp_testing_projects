cmake_minimum_required(VERSION 3.25)
project(cpp_learn)

# Force modern C++23 standards so std::print and contains works
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find every single .cpp file anywhere inside the Projects folder
file(GLOB_RECURSE ALL_CPP_FILES "Projects/*.cpp")

foreach(SOURCE_FILE ${ALL_CPP_FILES})
    # Extract the file name without extension
    get_filename_component(FILE_NAME ${SOURCE_FILE} NAME_WE)

    # Extract the folder name it lives in
    get_filename_component(PARENT_DIR ${SOURCE_FILE} DIRECTORY)
    get_filename_component(FOLDER_NAME ${PARENT_DIR} NAME)

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

    # Replace all blank spaces in the target name with clean underscores
    string(REPLACE " " "_" TARGET_NAME ${TARGET_NAME})

    add_executable(${TARGET_NAME} ${SOURCE_FILE})

    # -------------------------------------------------------------
    # 🔥 THE WINDOWS MIN-GW FIX: Manually link the C++23 print library
    # -------------------------------------------------------------
    if(MINGW AND CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
        target_link_libraries(${TARGET_NAME} PRIVATE stdc++exp)
    endif()

    if(SOURCE_FILE MATCHES "Projects/Part_2/Headers/")
        if(TARGET_NAME STREQUAL "Part2_Headers_executable")
            target_sources(${TARGET_NAME} PRIVATE "Projects/Part_2/Headers/Country.cpp")
        endif()
    endif()
endforeach()
