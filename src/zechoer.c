/*  =========================================================================
    zechoer - Echo server API

    Copyright (c) the Contributors as noted in the AUTHORS file.       
    This file is part of echoz.                                        
                                                                       
    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.           
    =========================================================================
*/

/*
@header
    zechoer - Echo server API
@discuss
@end
*/

#include "echoz_classes.h"

//  Structure of our class

struct _zechoer_t {
    int filler;     //  Declare class properties here
};


//  --------------------------------------------------------------------------
//  Create a new zechoer

zechoer_t *
zechoer_new (void)
{
    zechoer_t *self = (zechoer_t *) zmalloc (sizeof (zechoer_t));
    assert (self);
    //  Initialize class properties here
    return self;
}


//  --------------------------------------------------------------------------
//  Destroy the zechoer

void
zechoer_destroy (zechoer_t **self_p)
{
    assert (self_p);
    if (*self_p) {
        zechoer_t *self = *self_p;
        //  Free class properties here
        //  Free object itself
        free (self);
        *self_p = NULL;
    }
}

//  --------------------------------------------------------------------------
//  Self test of this class

void
zechoer_test (bool verbose)
{
    printf (" * zechoer: ");

    //  @selftest
    //  Simple create/destroy test

    // Note: If your selftest reads SCMed fixture data, please keep it in
    // src/selftest-ro; if your test creates filesystem objects, please
    // do so under src/selftest-rw. They are defined below along with a
    // usecase (asert) to make compilers happy.
    const char *SELFTEST_DIR_RO = "src/selftest-ro";
    const char *SELFTEST_DIR_RW = "src/selftest-rw";
    assert (SELFTEST_DIR_RO);
    assert (SELFTEST_DIR_RW);
    // Uncomment these to use C++ strings in C++ selftest code:
    //std::string str_SELFTEST_DIR_RO = std::string(SELFTEST_DIR_RO);
    //std::string str_SELFTEST_DIR_RW = std::string(SELFTEST_DIR_RW);
    //assert ( (str_SELFTEST_DIR_RO != "") );
    //assert ( (str_SELFTEST_DIR_RW != "") );
    // NOTE that for "char*" context you need (str_SELFTEST_DIR_RO + "/myfilename").c_str()

    zechoer_t *self = zechoer_new ();
    assert (self);
    zechoer_destroy (&self);
    //  @end
    printf ("OK\n");
}
