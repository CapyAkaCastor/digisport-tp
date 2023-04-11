cmake_minimum_required(VERSION 3.24)
project(observer)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
FetchContent_Declare(
        googletest
        # Specify the commit you depend on and update it regularly.
        URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Now simply link against gtest or gtest_main as needed. Eg
add_executable(observer observertest.cpp subject.cpp subject.h observer.cpp observer.h SubjectImpl.h SubjectImpl.cpp ObserverImpl.h ObserverImpl.cpp)
target_link_libraries(observer gtest_main)
add_test(NAME units_test COMMAND units)


# Documentation is here: https://github.com/google/googletest/blob/main/docs/primer.md