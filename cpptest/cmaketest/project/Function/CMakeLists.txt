cmake_minimum_required(VERSION 3.8)
project(Function)

set(var1 "var1: init")

function(func2)
    set(var1 "var1: value in fun2")
    message(STATUS "${var1}")
endfunction()

message(STATUS "调用func2之前var1的值: ${var1}")

message(STATUS "===调用fun2===")
FUNC2()

message(STATUS "调用func2之后var1的值: ${var1}")

message(STATUS "===PARENT_SCOPE===")
