//
// Created by James Miles on 31/08/2021.
//

#include <stdio.h>
#include "../encryptor/encryptor.h"

int main()
{
    char msg[80];
    while ( fgets(msg, 80, stdin) )
    {
        encrypt(msg);
        printf("%s", msg);
    }
}
