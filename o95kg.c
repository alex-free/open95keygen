/*
Open95Keygen version 1.0 - Febuary 7th 2021

BSD 3-Clause License

Copyright (c) 2021, Alex Free
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

#define DIGIT_RANGE 10
#define OEM_DAY_RANGE 366

unsigned char oem_key_year[2];
unsigned char oem_key_5[5];
unsigned char oem_key_5_random[5];
unsigned char retail_key_1[3];
unsigned char retail_key_2[7];
unsigned char digit;
unsigned char sum7;

unsigned int oem_key_day;

void gen_oem_day() 
{
    while(1) 
    {
        oem_key_day = rand() % OEM_DAY_RANGE;

        if(oem_key_day != 0)
            break;
    }
}

void gen_oem_year() 
{
    while(1) 
    {
        for(digit=0; digit<2; ++digit)
            oem_key_year[digit] = rand() % DIGIT_RANGE;

        if((oem_key_year[0] == 9 && oem_key_year[1] >= 5) || (oem_key_year[0] == 0 && oem_key_year[1] < 3))
            break;
    }
}

void gen_5digits_oem()
{
    while(1)
    {
        for(digit=0; digit<5; ++digit)
            oem_key_5[digit] = rand() % DIGIT_RANGE;

        sum7 = oem_key_5[0] + oem_key_5[1] + oem_key_5[2] + oem_key_5[3] + oem_key_5[4];

        if(sum7 % 7 == 0)
            break;
    }
}

void gen_5digits_random_oem()
{
    for(digit=0; digit<5; ++digit)
    oem_key_5_random[digit] = rand() % DIGIT_RANGE;   
}

void gen_3digits_retail() 
{
    while(1) 
    {
        for(digit=0; digit<3; ++digit)
            retail_key_1[digit] = rand() % DIGIT_RANGE;

        if(!(retail_key_1[0] == 3 && retail_key_1[1] == 3 && retail_key_1[2] == 3) || (retail_key_1[0] == 4 && retail_key_1[1] == 4 && retail_key_1[2] == 4) || (retail_key_1[0] == 5 && retail_key_1[1] == 5 && retail_key_1[2] == 5) || (retail_key_1[0] == 6 && retail_key_1[1] == 6 && retail_key_1[2] == 6) || (retail_key_1[0] == 7 && retail_key_1[1] == 7 && retail_key_1[2] == 7) || (retail_key_1[0] == 8 && retail_key_1[1] == 8 && retail_key_1[2] == 8) || (retail_key_1[0] == 9 && retail_key_1[1] == 9 && retail_key_1[2] == 9))
            break;
    }
}

void gen_7digits_retail()
{
    while(1)
    {
        for(digit=0; digit<7; ++digit)
        retail_key_2[digit] = rand() % DIGIT_RANGE;

        sum7 = retail_key_2[0] + retail_key_2[1] + retail_key_2[2] + retail_key_2[3] + retail_key_2[4] + retail_key_2[5] + retail_key_2[6];

        if(sum7 % 7 == 0)
            break;
    }
}

int main()
{
    srand(time(NULL));
    printf("Open95Keygen by Alex Free (C)2021, 2023 3-BSD\n");
    gen_3digits_retail();
    gen_7digits_retail();
    printf("Retail Product Key: %d%d%d-%d%d%d%d%d%d%d\n", retail_key_1[0], retail_key_1[1], retail_key_1[2], retail_key_2[0], retail_key_2[1], retail_key_2[2], retail_key_2[3], retail_key_2[4], retail_key_2[5], retail_key_2[6]);
    gen_oem_day();
    gen_oem_year();
    gen_5digits_oem();
    gen_5digits_random_oem();
    printf("OEM Product Key: %03d%d%d-OEM-00%d%d%d%d%d-%d%d%d%d%d\n", oem_key_day, oem_key_year[0], oem_key_year[1], oem_key_5[0], oem_key_5[1], oem_key_5[2], oem_key_5[3], oem_key_5[4], oem_key_5_random[0], oem_key_5_random[1], oem_key_5_random[2], oem_key_5_random[3], oem_key_5_random[4]);
    return(0);
}
