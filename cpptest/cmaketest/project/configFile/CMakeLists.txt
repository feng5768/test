cmake_minimum_required(VERSION 3.8)
project(ConfigFile)

set(VAR1 520)

set(NAME "小红")
set(NEW_NAME "小黄")

set(QUOTE "\"bb\"")

set(my_print "print_something")

configure_file(input.h input_default.h)
configure_file(input.h input_copyonly.h COPYONLY)
configure_file(input.h input_escape_quotes.h ESCAPE_QUOTES)
configure_file(input.h input_at_only.h @ONLY)
configure_file(input.h input_newline_style_dos.h NEWLINE_STYLE DOS)
configure_file(input.h input_newline_style_unix.h NEWLINE_STYLE LF)
