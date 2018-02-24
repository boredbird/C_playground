cmake_minimum_required(VERSION 3.9)
project(C_playground)

set(CMAKE_CXX_STANDARD 11)

add_executable(C_playground
#        exicise/C/07/7.8/table7_8left.c
#        exicise/C/07/7.8/table7_8right.c
#        exicise/C/07/7.9/li7_9right.c
#        exicise/C/07/7.9/table7_9left.c
#        exicise/C/07/7.10/table7_10left.c
#        exicise/C/07/7.10/table7_10right.c
#        exicise/C/07/7.11/table7_11left.c
#        exicise/C/07/7.11/table7_11right.c
#        exicise/C/08/table8_1/table8_1left.c
#        exicise/C/08/table8_1/table8_1right.c
#        exicise/C/08/li8_1.c
#        exicise/C/08/li8_2.c
#        exicise/C/08/li8_3.c
#        exicise/C/08/li8_4.c
#        exicise/C/08/li8_5.c
#        exicise/C/08/li8_6.c
#        exicise/C/09/li9_1.c
#        exicise/C/09/li9_2.c
#        exicise/C/09/li9_3.c
#        exicise/C/09/li9_4.c
        exicise/C/10/li10_1.c
        exicise/C/10/li10_2.c
        exicise/C/10/li10_3.c
        exicise/C/10/li10_4.c
        exicise/C/10/li10_5.c
        exicise/C/10/li10_6.c
        exicise/C/10/li10_7.c
        exicise/C/10/li10_8.c
        exicise/C/10/li10_9.c
        exicise/C/10/li10_10.c
        exicise/C/11/copy.c
        exicise/C/11/li11_1.c
        exicise/C/11/li11_2.c
        exicise/C/11/li11_3.c
        exicise/C/11/li11_4.c
        exicise/C/11/li11_5.c
        exicise/C/11/li11_6.c
        exicise/C/11/li11_7.c
        exicise/C/11/li11_8.c
        exicise/C/12/12_1/li12_1.c
        exicise/C/12/12_1/list.h
        exicise/C/12/12_1/node.h
        exicise/C/12/12_1/prepare.h
        exicise/C/12/12_2/file.h
        exicise/C/12/12_2/li12_2.c
        exicise/C/12/12_2/list.h
        exicise/C/12/12_2/node.h
        exicise/C/12/12_2/prepare.h
        exicise/C/13/ceshi.cpp
        exicise/C/13/li3_4.c
        exicise/C/13/li3_6.c
        exicise/C/13/li13_1.c
        exicise/C/13/li13_1.cpp
        exicise/C/13/li13_2.c
        exicise/C/13/li13_2.cpp
        exicise/C/13/li13_3.c
        exicise/C/13/li13_3.cpp
        exicise/C/13/li13_4.cpp
        exicise/C/13/li13_5.c
        exicise/C/13/li13_5.cpp
        exicise/C/13/li13_6.c
        exicise/C/13/li13_6.cpp
        exicise/C/13/li13_7.c
        exicise/C/13/li13_7.cpp
        exicise/C/13/li13_8.cpp
        exicise/C/13/li13_9.cpp
        exicise/C/13/li13_10.cpp
        exicise/C/13/li13_11.cpp
        exicise/C++/Xiti/xiti1-5.cpp
        exicise/C++/Xiti/xiti2-4-1.cpp
        exicise/C++/Xiti/xiti2-4-2.cpp
        exicise/C++/Xiti/xiti2-4-3.cpp
        exicise/C++/Xiti/xiti2-4-4.cpp
        exicise/C++/Xiti/xiti3-4-1.cpp
        exicise/C++/Xiti/xiti3-4-2.cpp
        exicise/C++/Xiti/xiti3-4-3.cpp
        exicise/C++/Xiti/xiti3-4-4.cpp
        exicise/C++/Xiti/xiti3-4-5.cpp
        exicise/C++/Xiti/xiti3-4-6.cpp
        exicise/C++/Xiti/xiti3-4-7.cpp
        exicise/C++/Xiti/xiti3-4-8.cpp
        exicise/C++/Xiti/xiti3-4-9.cpp
        exicise/C++/Xiti/xiti3-4-10.cpp
        exicise/C++/Xiti/xiti3-4-11.cpp
        exicise/C++/Xiti/xiti3-4-12.cpp
        exicise/C++/Xiti/xiti4-5-1.cpp
        exicise/C++/Xiti/xiti4-5-2.cpp
        exicise/C++/Xiti/xiti4-5-3.cpp
        exicise/C++/Xiti/xiti4-5-4.cpp
        exicise/C++/Xiti/xiti4-5-5.cpp
        exicise/C++/Xiti/xiti4-5-6.cpp
        exicise/C++/Xiti/xiti4-5-7.cpp
        exicise/C++/Xiti/xiti5-4-1.cpp
        exicise/C++/Xiti/xiti5-4-2.cpp
        exicise/C++/Xiti/xiti5-4-3.cpp
        exicise/C++/Xiti/xiti5-4-4.cpp
        exicise/C++/Xiti/xiti5-4-5.cpp
        exicise/C++/Xiti/xiti5-4-6.cpp
        exicise/C++/Xiti/Xiti6_6_1.cpp
        exicise/C++/Xiti/Xiti6_6_2.cpp
        exicise/C++/Xiti/Xiti6_6_3.cpp
        exicise/C++/Xiti/Xiti7_6_1.cpp
        exicise/C++/Xiti/Xiti7_6_2.cpp
        exicise/C++/Xiti/Xiti7_6_3.cpp
        exicise/C++/Xiti/Xiti8_4_1.cpp
        exicise/C++/Xiti/Xiti8_4_2.cpp
        exicise/C++/Xiti/Xiti9_4_1.cpp
        exicise/C++/Xiti/Xiti9_4_2.cpp
        exicise/C++/Xiti/Xiti10_4_1.cpp
        exicise/C++/Xiti/Xiti10_4_2.cpp
        exicise/C++/Xiti/Xiti10_4_3.cpp
        exicise/C++/Xiti/Xiti11_3_1.cpp
        exicise/C++/Xiti/Xiti11_3_2.cpp
        exicise/C++/Xiti/Xiti11_3_3.cpp
        exicise/C++/Xiti/Xiti11_3_4.cpp
        exicise/C++/Xiti/xiti12-4-1.cpp
        exicise/C++/Xiti/xiti12-4-2.cpp
       )
