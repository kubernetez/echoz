/*  =========================================================================
    zecho_actor - Actor for zechoer

    Copyright (c) the Contributors as noted in the AUTHORS file.       
    This file is part of echoz.                                        
                                                                       
    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.           
    =========================================================================
*/

#ifndef ZECHO_ACTOR_H_INCLUDED
#define ZECHO_ACTOR_H_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif


//  @interface
//  Create new zecho_actor actor instance.
//  @TODO: Describe the purpose of this actor!
//
//      zactor_t *zecho_actor = zactor_new (zecho_actor, NULL);
//
//  Destroy zecho_actor instance.
//
//      zactor_destroy (&zecho_actor);
//
//  Enable verbose logging of commands and activity:
//
//      zstr_send (zecho_actor, "VERBOSE");
//
//  Start zecho_actor actor.
//
//      zstr_sendx (zecho_actor, "START", NULL);
//
//  Stop zecho_actor actor.
//
//      zstr_sendx (zecho_actor, "STOP", NULL);
//
//  This is the zecho_actor constructor as a zactor_fn;
ECHOZ_EXPORT void
    zecho_actor_actor (zsock_t *pipe, void *args);

//  Self test of this actor
ECHOZ_EXPORT void
    zecho_actor_test (bool verbose);
//  @end

#ifdef __cplusplus
}
#endif

#endif
