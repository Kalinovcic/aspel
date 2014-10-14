/* 
 * Copyright (C) 2014 Lovro Kalinovcic
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 * 
 * File: aspel.c
 * Description: 
 * Author: Lovro Kalinovcic
 * 
 */

#include <stdlib.h>
#include <stdio.h>

#include <identifier.h>
#include <output.h>
#include <scanner.h>
#include <program.h>

int main(int argc, char** argv)
{
    /*
    system("../aspelc/Debug/aspelc -o test.aml test.aspel");
    system("../aasm/Debug/aasm -o test.aby test.aml");
    */

    FILE* pF = fopen("../aspel/test.aspel", "rb");
    fseek(pF, 0, SEEK_END);
    AC_uint size = ftell(pF);
    fseek(pF, 0, SEEK_SET);
    AC_byte* src = malloc(size);
    fread(src, 1, size, pF);
    fclose(pF);

    struct AC_output* output = AC_output_make("../aspel/test.aml");
    struct AC_scanner* scanner = AC_scanner_make(src, size);
    struct AC_program* program = AC_program_make(scanner);

    AC_program_translate(program, output);

    AC_program_destroy(program);
    AC_scanner_destroy(scanner);
    AC_output_destroy(output);
    free(src);

    printf("successful pass\n");

    return 0;
}
