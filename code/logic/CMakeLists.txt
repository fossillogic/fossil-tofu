# code/logic/CMakeLists.txt

# Define the include directories
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# Collect all header files in logic/fossil/*
file(GLOB HEADER_FILES ${CMAKE_CURRENT_SOURCE_DIR}/fossil/*.h)

# List the source files
set(TEST_CODE
    doublylist.c
    circularlist.c
    dqueue.c
    forwardlist.c
    pqueue.c
    queue.c
    setof.c
    mapof.c
    stack.c
    tofu.c
    tuple.c
    vector.c
)

# Create the library target
add_library(fossil-tofu STATIC ${TEST_CODE} ${HEADER_FILES})

# Set the library to be installed
install(TARGETS fossil-tofu
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
)

# Install the header files
install(FILES ${HEADER_FILES} DESTINATION include/fossil)

# Declare the dependency
add_library(fossil_tofu_dep INTERFACE)
target_link_libraries(fossil_tofu_dep INTERFACE fossil-tofu)
target_include_directories(fossil_tofu_dep INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
