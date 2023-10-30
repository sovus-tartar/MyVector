add_executable(test_myvector test.cpp)
target_include_directories(test_myvector PUBLIC ../include)
target_link_libraries(test_myvector GTest::gtest_main)
gtest_discover_tests(test_myvector)