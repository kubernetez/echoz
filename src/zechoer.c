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
    zsock_t *router;
    zpoller_t *poller;
    bool verbose;
};


//  --------------------------------------------------------------------------
//  Create a new zechoer

zechoer_t *
zechoer_new (char *endpoints)
{
    zechoer_t *self = (zechoer_t *) zmalloc (sizeof (zechoer_t));
    assert (self);
    
    self->router = zsock_new_router (endpoints);
    if (!self->router)
        zechoer_destroy (&self);
     

    self->poller = zpoller_new (self->router, NULL);
    if (!self->poller)
        zechoer_destroy (&self);

    return self;
}


//  --------------------------------------------------------------------------
//  Start the zechoer

int
zechoer_start (zechoer_t *self)
{
    zsock_t *which = (zsock_t *) zpoller_wait (self->poller, -1);
    while (which == self->router) {
        zframe_t *identity = zframe_recv (which);
        if (!identity)
            return -1;
        
        zframe_t *message = zframe_recv (which);
        if (!message)
            return 1;
        
        if (self->verbose)
            zsys_debug ("received %s from %s", message, identity);

        zframe_send (&identity, self->router, 1);
        zframe_send (&message, self->router, 0);

        which = (zsock_t *) zpoller_wait (self->poller, -1);
    }

    bool abnormal_exit = zpoller_terminated (self->poller);

    if (abnormal_exit)
        return -1;

    return 0;
}

//  --------------------------------------------------------------------------
//  Destroy the zechoer

void
zechoer_destroy (zechoer_t **self_p)
{
    assert (self_p);
    if (*self_p) {
        zechoer_t *self = *self_p;
        zpoller_destroy (&self->poller);
        zsock_destroy (&self->router);
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

    zechoer_t *self = zechoer_new ("inproc://zechotest");
    assert (self);
    zechoer_destroy (&self);
    //  @end
    printf ("OK\n");
}
