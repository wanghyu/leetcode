cmake_minimum_required(VERSION 3.14)
project(leetcode)

set(CMAKE_CXX_STANDARD 14)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -O0 -Wall -pthread -fno-elide-constructors")

add_executable(61-RotateList editor/cn/61-RotateList.cpp)
add_executable(1-TwoSum editor/cn/1-TwoSum.cpp)
add_executable(2-AddTwoNumbers editor/cn/2-AddTwoNumbers.cpp)
add_executable(344-ReverseString editor/cn/344-ReverseString.cpp)
add_executable(541-ReverseStringII editor/cn/541-ReverseStringII.cpp)
add_executable(24-SwapNodesInPairs editor/cn/24-SwapNodesInPairs.cpp)
add_executable(206-ReverseLinkedList editor/cn/206-ReverseLinkedList.cpp)
add_executable(232-ImplementQueueUsingStacks editor/cn/232-ImplementQueueUsingStacks.cpp)
add_executable(20-ValidParentheses editor/cn/20-ValidParentheses.cpp)
add_executable(1047-RemoveAllAdjacentDuplicatesInString editor/cn/1047-RemoveAllAdjacentDuplicatesInString.cpp)