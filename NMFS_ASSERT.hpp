/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NMFS_ASSERT.hpp
 * Author: mattadmin
 *
 * Created on July 20, 2020, 2:53 PM
 */

#ifndef NMFS_ASSERT_HPP
#define NMFS_ASSERT_HPP

#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "lib/Console.hpp"
using namespace std;

#define xstr(s) STRX(s)
#define STRX(s) #s

struct UnitTestResults {
    std::vector<std::string> success;
    std::vector<std::string> failures;

    ~UnitTestResults() {
        std::cout << "\n\nTest suite resulted in " << io::BOLD << success.size() << io::DEFAULT << " successes and " << io::BOLD << failures.size() << io::DEFAULT << " failures...\n" << std::endl;

        if (failures.size() > 0) {
            std::cout << "Dump failure list (y,n)? ";
            std::string s;
            std::cin>>s;
            if (s == "y") {
                this->ShowFailures();
            }
        }
    }

    void ShowFailures() {

        for (int i = 0; i < failures.size(); i++) {
            std::cout << failures[i];
        }
    }


};

UnitTestResults results__;

void DumpFailures() {
    results__.ShowFailures();
}


#define NMFS_ASSERT(a)            \
if(a){                            \
std::stringstream ss;             \
ss<<"Function \""<<__FUNCTION__<<"\" at line "<<__LINE__<<" in file \"" <<__FILE__<< "\"....."<<io::GREEN<<"Success"<<io::DEFAULT<<"\n";          \
std::cout<<ss.str();          \
results__.success.push_back(ss.str());   \
}else{                            \
std::stringstream ss;             \
ss<<"Function \""<<__FUNCTION__<<"\" at line "<<__LINE__<<" in file \"" <<__FILE__<< "\"....."<<io::RED<<"Fail"<<io::DEFAULT<<"\n";             \
std::cout<<ss.str();          \
results__.failures.push_back(ss.str());   \
}

#define NMFS_ASSERT_EQUAL(a, b)            \
if(a == b){                            \
std::stringstream ss;             \
ss<<"Function \""<<__FUNCTION__<<"\" at line "<<__LINE__<<" in file \"" <<__FILE__<< "\"....."<<io::GREEN<<"Success"<<io::DEFAULT <<" | "<<xstr(a)<<" == "<<xstr(b)<<" : "<<xstr(a)<<" = "<<a<<", "<<xstr(b)<<" = "<<b<<" \n";          \
std::cout<<ss.str();          \
results__.success.push_back(ss.str());   \
}else{                            \
std::stringstream ss;             \
ss<<"Function \""<<__FUNCTION__<<"\" at line "<<__LINE__<<" in file \"" <<__FILE__<< "\"....."<<io::RED<<"Fail"<<io::DEFAULT <<" | "<<xstr(a)<<" != "<<xstr(b)<<" : "<<xstr(a)<<" = "<<a<<", "<<xstr(b)<<" = "<<b<<" \n";              \
std::cout<<ss.str();          \
results__.failures.push_back(ss.str());   \
}

#define NMFS_ASSERT_NOT_EQUAL(a, b)            \
if(a != b){                            \
std::stringstream ss;             \
ss<<"Function \""<<__FUNCTION__<<"\" at line "<<__LINE__<<" in file \"" <<__FILE__<< "\"....."<<io::GREEN<<"Success"<<io::DEFAULT <<" | "<<xstr(a)<<" =! "<<xstr(b)<<" : "<<xstr(a)<<" = "<<a<<", "<<xstr(b)<<" = "<<b<<" \n";          \
std::cout<<ss.str();          \
results__.success.push_back(ss.str());   \
}else{                            \
std::stringstream ss;             \
ss<<"Function \""<<__FUNCTION__<<"\" at line "<<__LINE__<<" in file \"" <<__FILE__<< "\"....."<<io::RED<<"Fail"<<io::DEFAULT <<" | "<<xstr(a)<<" == "<<xstr(b)<<" : "<<xstr(a)<<" = "<<a<<", "<<xstr(b)<<" = "<<b<<" \n";              \
std::cout<<ss.str();          \
results__.failures.push_back(ss.str());   \
}

#define NMFS_ASSERT_LESS_THAN(a, b)            \
if(a < b){                            \
std::stringstream ss;             \
ss<<"Function \""<<__FUNCTION__<<"\" at line "<<__LINE__<<" in file \"" <<__FILE__<< "\"....."<<io::GREEN<<"Success"<<io::DEFAULT <<" | "<<xstr(a)<<" < "<<xstr(b)<<" : "<<xstr(a)<<" = "<<a<<", "<<xstr(b)<<" = "<<b<<" \n";          \
std::cout<<ss.str();          \
results__.success.push_back(ss.str());   \
}else{                            \
std::stringstream ss;             \
ss<<"Function \""<<__FUNCTION__<<"\" at line "<<__LINE__<<" in file \"" <<__FILE__<< "\"....."<<io::RED<<"Fail"<<io::DEFAULT <<" | "<<xstr(a)<<" >= "<<xstr(b)<<" : "<<xstr(a)<<" = "<<a<<", "<<xstr(b)<<" = "<<b<<" \n";              \
std::cout<<ss.str();          \
results__.failures.push_back(ss.str());   \
}

#define NMFS_ASSERT_LESS_THAN_EQUAL(a, b)            \
if(a <= b){                            \
std::stringstream ss;             \
ss<<"Function \""<<__FUNCTION__<<"\" at line "<<__LINE__<<" in file \"" <<__FILE__<< "\"....."<<io::GREEN<<"Success"<<io::DEFAULT <<" | "<<xstr(a)<<" <= "<<xstr(b)<<" : "<<xstr(a)<<" = "<<a<<", "<<xstr(b)<<" = "<<b<<" \n";          \
std::cout<<ss.str();          \
results__.success.push_back(ss.str());   \
}else{                            \
std::stringstream ss;             \
ss<<"Function \""<<__FUNCTION__<<"\" at line "<<__LINE__<<" in file \"" <<__FILE__<< "\"....."<<io::RED<<"Fail"<<io::DEFAULT <<" | "<<xstr(a)<<" > "<<xstr(b)<<" : "<<xstr(a)<<" = "<<a<<", "<<xstr(b)<<" = "<<b<<" \n";              \
std::cout<<ss.str();          \
results__.failures.push_back(ss.str());   \
}

#define NMFS_ASSERT_GREATER_THAN(a, b)            \
if(a > b){                            \
std::stringstream ss;             \
ss<<"Function \""<<__FUNCTION__<<"\" at line "<<__LINE__<<" in file \"" <<__FILE__<< "\"....."<<io::GREEN<<"Success"<<io::DEFAULT <<" | "<<xstr(a)<<" > "<<xstr(b)<<" : "<<xstr(a)<<" = "<<a<<", "<<xstr(b)<<" = "<<b<<" \n";          \
std::cout<<ss.str();          \
results__.success.push_back(ss.str());   \
}else{                            \
std::stringstream ss;             \
ss<<"Function \""<<__FUNCTION__<<"\" at line "<<__LINE__<<" in file \"" <<__FILE__<< "\"....."<<io::RED<<"Fail"<<io::DEFAULT <<" | "<<xstr(a)<<" <= "<<xstr(b)<<" : "<<xstr(a)<<" = "<<a<<", "<<xstr(b)<<" = "<<b<<" \n";              \
std::cout<<ss.str();          \
results__.failures.push_back(ss.str());   \
}

#define NMFS_ASSERT_GREATER_THAN_EQUAL(a, b)            \
if(a >= b){                            \
std::stringstream ss;             \
ss<<"Function \""<<__FUNCTION__<<"\" at line "<<__LINE__<<" in file \"" <<__FILE__<< "\"....."<<io::GREEN<<"Success"<<io::DEFAULT <<" | "<<xstr(a)<<" >= "<<xstr(b)<<" : "<<xstr(a)<<" = "<<a<<", "<<xstr(b)<<" = "<<b<<" \n";          \
std::cout<<ss.str();          \
results__.success.push_back(ss.str());   \
}else{                            \
std::stringstream ss;             \
ss<<"Function \""<<__FUNCTION__<<"\" at line "<<__LINE__<<" in file \"" <<__FILE__<< "\"....."<<io::RED<<"Fail"<<io::DEFAULT <<" | "<<xstr(a)<<" < "<<xstr(b)<<" : "<<xstr(a)<<" = "<<a<<", "<<xstr(b)<<" = "<<b<<" \n";              \
std::cout<<ss.str();          \
results__.failures.push_back(ss.str());   \
}


#endif /* NMFS_ASSERT_HPP */

