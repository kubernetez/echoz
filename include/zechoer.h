/*  =========================================================================
    zechoer - Echo server API

    Copyright (c) the Contributors as noted in the AUTHORS file.       
    This file is part of echoz.                                        
                                                                       
    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.           
    =========================================================================
*/

#ifndef ZECHOER_H_INCLUDED
#define ZECHOER_H_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

//  @interface
//  Create a new zechoer
ECHOZ_EXPORT zechoer_t *
    zechoer_new (void);

//  Destroy the zechoer
ECHOZ_EXPORT void
    zechoer_destroy (zechoer_t **self_p);

//  Self test of this class
ECHOZ_EXPORT void
    zechoer_test (bool verbose);

//  @end

#ifdef __cplusplus
}
#endif

#endif
