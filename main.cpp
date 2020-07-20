/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: mattadmin
 *
 * Created on July 20, 2020, 11:08 AM
 */

#include "NMFS_ASSERT.hpp"

void RunTest() {

    double R0 = 1.0;
    double S0 = .5;
    NMFS_ASSERT(1 == 1);
    NMFS_ASSERT(0 == 1);
    NMFS_ASSERT_EQUAL(R0, S0);
    NMFS_ASSERT_NOT_EQUAL(R0, S0);
    NMFS_ASSERT_LESS_THAN(R0, S0);
    NMFS_ASSERT_LESS_THAN_EQUAL(R0, S0);
    NMFS_ASSERT_GREATER_THAN(R0, S0);
    NMFS_ASSERT_GREATER_THAN_EQUAL(R0, S0);
}

/*
 * 
 */
int main(int argc, char** argv) {

    RunTest();

    return 0;
}

