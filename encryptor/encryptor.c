//
// Created by James Miles on 31/08/2021.
//

#include "encryptor.h"

void encrypt(char *message)
{
    while ( *message )
    {
        *message = *message ^ 31;
        message++;
    }
}
