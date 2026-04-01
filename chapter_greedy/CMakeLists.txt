get_filename_component(CHAPTER_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)

file(GLOB CHAPTER_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

set(CHAPTER_TARGET_COUNT 0)

foreach(src IN LISTS CHAPTER_SOURCES)
    file(READ "${src}" src_content)
    string(REGEX MATCH "int[ \t\r\n]+main[ \t\r\n]*\\(" has_main "${src_content}")

    if(NOT has_main)
        get_filename_component(src_name ${src} NAME)
        message(STATUS "[${CHAPTER_NAME}] skip ${src_name} (no main)")
        continue()
    endif()

    get_filename_component(src_name ${src} NAME_WE)
    set(target_name "${CHAPTER_NAME}_${src_name}")

    add_executable(${target_name} ${src})

    target_include_directories(${target_name}
        PRIVATE
            ${PROJECT_SOURCE_DIR}
            ${PROJECT_SOURCE_DIR}/common
    )

    if(COMMAND enable_project_warnings)
        enable_project_warnings(${target_name})
    endif()

    if(COMMAND enable_project_asan)
        enable_project_asan(${target_name})
    endif()

    set_target_properties(${target_name} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/${CHAPTER_NAME}"
    )

    math(EXPR CHAPTER_TARGET_COUNT "${CHAPTER_TARGET_COUNT} + 1")
endforeach()

if(CHAPTER_TARGET_COUNT EQUAL 0)
    message(STATUS "[${CHAPTER_NAME}] no runnable sources yet")
endif()
