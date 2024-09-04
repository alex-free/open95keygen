/*
BSD 3-Clause License

Copyright (c) 2021-2024 Alex Free
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

* Redistributions of source code must retain the above copyright notice, this
  list of conditions and the following disclaimer.

* Redistributions in binary form must reproduce the above copyright notice,
  this list of conditions and the following disclaimer in the documentation
  and/or other materials provided with the distribution.

* Neither the name of the copyright holder nor the names of its
  contributors may be used to endorse or promote products derived from
  this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SINGLE_DIGIT_RANGE 10 // Single digit, 0-9.
#define OEM_DAY_RANGE 367 // 3 digits, 001-366 are valid.

int main()
{
    unsigned char oem_key_year[2];
    unsigned char oem_key_part_1[5];
    unsigned char oem_key_part_2[5];
    unsigned char retail_key_part_1[3];
    unsigned char retail_key_part_2[7];
    unsigned char digit;
    unsigned char sum7;

    unsigned int oem_key_day;

    srand(time(NULL));
    printf("Open95Keygen %s by Alex Free (c) 2021-2024, 3-BSD\n", VERSION);

    // Retail key 1/2: Generate 3 random digits for retail that are not blacklisted. Blacklisted is 333, 444, 555, 666, 777, 888, and 999.
    while(1) 
    {
        for(digit = 0; digit < 3; digit++)
        {
            retail_key_part_1[digit] = rand() % SINGLE_DIGIT_RANGE;
        }

        if(
            !(retail_key_part_1[0] == 3 && retail_key_part_1[1] == 3 && retail_key_part_1[2] == 3) && // Activation function blacklists 333.
            !(retail_key_part_1[0] == 4 && retail_key_part_1[1] == 4 && retail_key_part_1[2] == 4) && // Activation function blacklists 444.
            !(retail_key_part_1[0] == 5 && retail_key_part_1[1] == 5 && retail_key_part_1[2] == 5) && // Activation function blacklists 555.
            !(retail_key_part_1[0] == 6 && retail_key_part_1[1] == 6 && retail_key_part_1[2] == 6) && // Activation function blacklists 666.
            !(retail_key_part_1[0] == 7 && retail_key_part_1[1] == 7 && retail_key_part_1[2] == 7) && // Activation function blacklists 777.
            !(retail_key_part_1[0] == 8 && retail_key_part_1[1] == 8 && retail_key_part_1[2] == 8) && // Activation function blacklists 888.
            !(retail_key_part_1[0] == 9 && retail_key_part_1[1] == 9 && retail_key_part_1[2] == 9) // Activation function blacklists 999.
        )
        {
            break;
        }
    }

    // Retail key 2/2: Generate 7 random digits that are divisible by 7, with no remainder.
    while(1)
    {
        for(digit = 0; digit < 7; digit++)
        {
            retail_key_part_2[digit] = rand() % SINGLE_DIGIT_RANGE;
        }

        sum7 = retail_key_part_2[0] + retail_key_part_2[1] + retail_key_part_2[2] + retail_key_part_2[3] + retail_key_part_2[4] + retail_key_part_2[5] + retail_key_part_2[6];

        if(sum7 % 7 == 0)
        {
            break;
        }
    }

    printf("Retail Product Key: %d%d%d-%d%d%d%d%d%d%d\n", retail_key_part_1[0], retail_key_part_1[1], retail_key_part_1[2], retail_key_part_2[0], retail_key_part_2[1], retail_key_part_2[2], retail_key_part_2[3], retail_key_part_2[4], retail_key_part_2[5], retail_key_part_2[6]);

    // OEM key 1/4: Generate 2 random digits for year within specification. Valid years are 95, 96, 97, 98, 99, 00, 01, 02.
    while(1) 
    {
        for(digit = 0; digit < 2; digit++)
        {
            oem_key_year[digit] = rand() % SINGLE_DIGIT_RANGE;
        }

        if( (oem_key_year[0] == 9 && oem_key_year[1] >= 5) || (oem_key_year[0] == 0 && oem_key_year[1] < 3) )
        {
            break;
        }
    }

    // OEM key 2/4: Generate 3 random digits for day, 001-366.
    while(1) 
    {
        oem_key_day = rand() % OEM_DAY_RANGE;

        if(oem_key_day != 0) // If not zero. Must be 001-366.
        {
            break;
        }
    }

    // OEM key 3/4: Generate 5 random digits whose total is devisable by 7 with no remainder. Last digit can not be 0, 8, or 9 (thanks @steeviebops on winworldpc's Windows 95 OSR 2 page comments for leaving that tip for me to find).
    while(1)
    {
        for(digit = 0; digit < 5; digit++)
        {
            oem_key_part_1[digit] = rand() % SINGLE_DIGIT_RANGE;
        }

        sum7 = oem_key_part_1[0] + oem_key_part_1[1] + oem_key_part_1[2] + oem_key_part_1[3] + oem_key_part_1[4];

        if(sum7 % 7 == 0)
        {
            if(
                !(oem_key_part_1[4] == 0) &&
                !(oem_key_part_1[4] == 8) &&
                !(oem_key_part_1[4] == 9)
            )
            {
                break;
            }
        }
    }

    // OEM key 4/4: Generate 5 random digits with no specific criteria.
    for(digit = 0; digit < 5; digit++)
    {
        oem_key_part_2[digit] = rand() % SINGLE_DIGIT_RANGE; // purely random, no checking of what these even are
    }

    printf("OEM Product Key: %03d%d%d-OEM-00%d%d%d%d%d-%d%d%d%d%d\n", oem_key_day, oem_key_year[0], oem_key_year[1], oem_key_part_1[0], oem_key_part_1[1], oem_key_part_1[2], oem_key_part_1[3], oem_key_part_1[4], oem_key_part_2[0], oem_key_part_2[1], oem_key_part_2[2], oem_key_part_2[3], oem_key_part_2[4]);

    return(0);
}
