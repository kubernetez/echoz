/*  =========================================================================
    echo_client - Echo client

    Copyright (c) the Contributors as noted in the AUTHORS file.       
    This file is part of echoz.                                        
                                                                       
    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.           
    =========================================================================
*/

/*
@header
    echo_client - Echo client
@discuss
@end
*/

#include "echoz_classes.h"

int main (int argc, char *argv [])
{
    bool verbose = false;
    char *endpoints = NULL;
    char *message = NULL;

    int argn;
    for (argn = 1; argn < argc; argn++) {
        if (streq (argv [argn], "--help")
        ||  streq (argv [argn], "-h")) {
            puts ("echoz_server [options] ...");
            puts ("  --verbose / -v         verbose test output");
            puts ("  --endpoints / -e       endpoint(s) to listen on");
            puts ("  --message / -m         mesage to send");
            puts ("  --help / -h            this information");
            return 0;
        }
        else
        if (streq (argv [argn], "--verbose")
        ||  streq (argv [argn], "-v")) {
            verbose = true;
        }
        else
        if (streq (argv [argn], "--endpoints")
        || streq (argv [argn], "-e")) {
            argn++;
            endpoints = argv [argn];
        }
        else
        if (streq (argv [argn], "--message")
        || streq (argv [argn], "-m")) {
            argn++;
            message = argv [argn];
        }
        else {
            printf ("Unknown option: %s\n", argv [argn]);
            return 1;
        }
    }
    //  Insert main code here
    if (verbose) {
        zsys_debug ("echoz_client - Echo client");
        zsys_debug ("endpoints: %s", endpoints);
        zsys_debug ("message: %s", message);
    }

    zsock_t *client = zsock_new_dealer (endpoints);
    assert (client);

    zstr_send (client, message);
    char *reply = zstr_recv (client);
    zsys_info ("RECEIVED: '%s'\n", reply);
    free (reply);
    zsock_destroy (&client);
    return 0;
}
