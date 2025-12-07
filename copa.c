#include <stdio.h>
#include <string.h>
#include <ctype.h>
char tabela[495][8] = {
        /* 1  */ { 'E','J','I','F','H','G','L','K' },
        /* 2  */ { 'H','G','I','D','J','F','L','K' },
        /* 3  */ { 'E','J','I','D','H','G','L','K' },
        /* 4  */ { 'E','J','I','D','H','F','L','K' },
        /* 5  */ { 'E','G','I','D','J','F','L','K' },
        /* 6  */ { 'E','G','J','D','H','F','L','K' },
        /* 7  */ { 'E','G','I','D','H','F','L','K' },
        /* 8  */ { 'E','G','J','D','H','F','L','I' },
        /* 9  */ { 'E','G','J','D','H','F','I','K' },
        /*10  */ { 'H','G','I','C','J','F','L','K' },
        /*11  */ { 'E','J','I','C','H','G','L','K' },
        /*12  */ { 'E','J','I','C','H','F','L','K' },
        /*13  */ { 'E','G','I','C','J','F','L','K' },
        /*14  */ { 'E','G','J','C','H','F','L','K' },
        /*15  */ { 'E','G','I','C','H','F','L','K' },
        /*16  */ { 'E','G','J','C','H','F','L','I' },
        /*17  */ { 'E','G','J','C','H','F','I','K' },
        /*18  */ { 'H','G','I','C','J','D','L','K' },
        /*19  */ { 'C','J','I','D','H','F','L','K' },
        /*20  */ { 'C','G','I','D','J','F','L','K' },
        /*21  */ { 'C','G','J','D','H','F','L','K' },
        /*22  */ { 'C','G','I','D','H','F','L','K' },
        /*23  */ { 'C','G','J','D','H','F','L','I' },
        /*24  */ { 'C','G','J','D','H','F','I','K' },
        /*25  */ { 'E','J','I','C','H','D','L','K' },
        /*26  */ { 'E','G','I','C','J','D','L','K' },
        /*27  */ { 'E','G','J','C','H','D','L','K' },
        /*28  */ { 'E','G','I','C','H','D','L','K' },
        /*29  */ { 'E','G','J','C','H','D','L','I' },
        /*30  */ { 'E','G','J','C','H','D','I','K' },
        /*31  */ { 'C','J','E','D','I','F','L','K' },
        /*32  */ { 'C','J','E','D','H','F','L','K' },
        /*33  */ { 'C','E','I','D','H','F','L','K' },
        /*34  */ { 'C','J','E','D','H','F','L','I' },
        /*35  */ { 'C','J','E','D','H','F','I','K' },
        /*36  */ { 'C','G','E','D','J','F','L','K' },
        /*37  */ { 'C','G','E','D','I','F','L','K' },
        /*38  */ { 'C','G','E','D','J','F','L','I' },
        /*39  */ { 'C','G','E','D','J','F','I','K' },
        /*40  */ { 'C','G','E','D','H','F','L','K' },
        /*41  */ { 'C','G','J','D','H','F','L','E' },
        /*42  */ { 'C','G','J','D','H','F','E','K' },
        /*43  */ { 'C','G','E','D','H','F','L','I' },
        /*44  */ { 'C','G','E','D','H','F','I','K' },
        /*45  */ { 'C','G','J','D','H','F','E','I' },
        /*46  */ { 'H','J','B','F','I','G','L','K' },
        /*47  */ { 'E','J','I','B','H','G','L','K' },
        /*48  */ { 'E','J','B','F','I','H','L','K' },
        /*49  */ { 'E','J','B','F','I','G','L','K' },
        /*50  */ { 'E','J','B','F','H','G','L','K' },
        /*51  */ { 'E','G','B','F','I','H','L','K' },
        /*52  */ { 'E','J','B','F','H','G','L','I' },
        /*53  */ { 'E','J','B','F','H','G','I','K' },
        /*54  */ { 'H','J','B','D','I','G','L','K' },
        /*55  */ { 'H','J','B','D','I','F','L','K' },
        /*56  */ { 'I','G','B','D','J','F','L','K' },
        /*57  */ { 'H','G','B','D','J','F','L','K' },
        /*58  */ { 'H','G','B','D','I','F','L','K' },
        /*59  */ { 'H','G','B','D','J','F','L','I' },
        /*60  */ { 'H','G','B','D','J','F','I','K' },
        /*61  */ { 'E','J','B','D','I','H','L','K' },
        /*62  */ { 'E','J','B','D','I','G','L','K' },
        /*63  */ { 'E','J','B','D','H','G','L','K' },
        /*64  */ { 'E','G','B','D','I','H','L','K' },
        /*65  */ { 'E','J','B','D','H','G','L','I' },
        /*66  */ { 'E','J','B','D','H','G','I','K' },
        /*67  */ { 'E','J','B','D','I','F','L','K' },
        /*68  */ { 'E','J','B','D','H','F','L','K' },
        /*69  */ { 'E','I','B','D','H','F','L','K' },
        /*70  */ { 'E','J','B','D','H','F','L','I' },
        /*71  */ { 'E','J','B','D','H','F','I','K' },
        /*72  */ { 'E','G','B','D','J','F','L','K' },
        /*73  */ { 'E','G','B','D','I','F','L','K' },
        /*74  */ { 'E','G','B','D','J','F','L','I' },
        /*75  */ { 'E','G','B','D','J','F','I','K' },
        /*76  */ { 'E','G','B','D','H','F','L','K' },
        /*77  */ { 'H','G','B','D','J','F','L','E' },
        /*78  */ { 'H','G','B','D','J','F','E','K' },
        /*79  */ { 'E','G','B','D','H','F','L','I' },
        /*80  */ { 'E','G','B','D','H','F','I','K' },
        /*81  */ { 'H','G','B','D','J','F','E','I' },
        /*82  */ { 'H','J','B','C','I','G','L','K' },
        /*83  */ { 'H','J','B','C','I','F','L','K' },
        /*84  */ { 'I','G','B','C','J','F','L','K' },
        /*85  */ { 'H','G','B','C','J','F','L','K' },
        /*86  */ { 'H','G','B','C','I','F','L','K' },
        /*87  */ { 'H','G','B','C','J','F','L','I' },
        /*88  */ { 'H','G','B','C','J','F','I','K' },
        /*89  */ { 'E','J','B','C','I','H','L','K' },
        /*90  */ { 'E','J','B','C','I','G','L','K' },
        /*91  */ { 'E','J','B','C','H','G','L','K' },
        /*92  */ { 'E','G','B','C','I','H','L','K' },
        /*93  */ { 'E','J','B','C','H','G','L','I' },
        /*94  */ { 'E','J','B','C','H','G','I','K' },
        /*95  */ { 'E','J','B','C','I','F','L','K' },
        /*96  */ { 'E','J','B','C','H','F','L','K' },
        /*97  */ { 'E','I','B','C','H','F','L','K' },
        /*98  */ { 'E','J','B','C','H','F','L','I' },
        /*99  */ { 'E','J','B','C','H','F','I','K' },
        /*100 */ { 'E','G','B','C','J','F','L','K' },
                {'E','G','B','C','I','F','L','K'},
                {'E','G','B','C','J','F','L','I'},
                {'E','G','B','C','J','F','I','K'},
                {'E','G','B','C','H','F','L','K'},
                {'H','G','B','C','J','F','L','E'},
                {'H','G','B','C','J','F','E','K'},
                {'E','G','B','C','H','F','L','I'},
                {'E','G','B','C','H','F','I','K'},
                {'H','G','B','C','J','F','E','I'},
                {'H','J','B','C','I','D','L','K'},
                {'I','G','B','C','J','D','L','K'},
                {'H','G','B','C','J','D','L','K'},
                {'H','G','B','C','I','D','L','K'},
                {'H','G','B','C','J','D','L','I'},
                {'H','G','B','C','J','D','I','K'},
                {'C','J','B','D','I','F','L','K'},
                {'C','J','B','D','H','F','L','K'},
                {'C','I','B','D','H','F','L','K'},
                {'C','J','B','D','H','F','L','I'},
                {'C','J','B','D','H','F','I','K'},
                {'C','G','B','D','J','F','L','K'},
                {'C','G','B','D','I','F','L','K'},
                {'C','G','B','D','J','F','L','I'},
                {'C','G','B','D','J','F','I','K'},
                {'C','G','B','D','H','F','L','K'},
                {'C','G','B','D','H','F','L','J'},
                {'H','G','B','C','J','F','D','K'},
                {'C','G','B','D','H','F','L','I'},
                {'C','G','B','D','H','F','I','K'},
                {'H','G','B','C','J','F','D','I'},
                {'E','J','B','C','I','D','L','K'},
                {'E','J','B','C','H','D','L','K'},
                {'E','I','B','C','H','D','L','K'},
                {'E','J','B','C','H','D','L','I'},
                {'E','J','B','C','H','D','I','K'},
                {'E','G','B','C','J','D','L','K'},
                {'E','G','B','C','I','D','L','K'},
                {'E','G','B','C','J','D','L','I'},
                {'E','G','B','C','J','D','I','K'},
                {'E','G','B','C','H','D','L','K'},
                {'H','G','B','C','J','D','L','E'},
                {'H','G','B','C','J','D','E','K'},
                {'E','G','B','C','H','D','L','I'},
                {'E','G','B','C','H','D','I','K'},
                {'H','G','B','C','J','D','E','I'},
                {'C','J','B','D','E','F','L','K'},
                {'C','E','B','D','I','F','L','K'},
                {'C','J','B','D','E','F','L','I'},
                {'C','J','B','D','E','F','I','K'},
                {'C','E','B','D','H','F','L','K'},
                {'C','J','B','D','H','F','L','E'},
                {'C','J','B','D','H','F','E','K'},
                {'C','E','B','D','H','F','L','I'},
                {'C','E','B','D','H','F','I','K'},
                {'C','J','B','D','H','F','E','I'},
                {'C','G','B','D','E','F','L','K'},
                {'C','G','B','D','J','F','L','E'},
                {'C','G','B','D','J','F','E','K'},
                {'C','G','B','D','E','F','L','I'},
                {'C','G','B','D','E','F','I','K'},
                {'C','G','B','D','J','F','E','I'},
                {'C','G','B','D','H','F','L','E'},
                {'C','G','B','D','H','F','E','K'},
                {'H','G','B','C','J','F','D','E'},
                {'C','G','B','D','H','F','E','I'},
                {'H','J','I','F','A','G','L','K'},
                {'E','J','I','A','H','G','L','K'},
                {'E','J','I','F','A','H','L','K'},
                {'E','J','I','F','A','G','L','K'},
                {'E','G','J','F','A','H','L','K'},
                {'E','G','I','F','A','H','L','K'},
                {'E','G','J','F','A','H','L','I'},
                {'E','G','J','F','A','H','I','K'},
                {'H','J','I','D','A','G','L','K'},
                {'H','J','I','D','A','F','L','K'},
                {'I','G','J','D','A','F','L','K'},
                {'H','G','J','D','A','F','L','K'},
                {'H','G','I','D','A','F','L','K'},
                {'H','G','J','D','A','F','L','I'},
                {'H','G','J','D','A','F','I','K'},
                {'E','J','I','D','A','H','L','K'},
                {'E','J','I','D','A','G','L','K'},
                {'E','G','J','D','A','H','L','K'},
                {'E','G','I','D','A','H','L','K'},
                {'E','G','J','D','A','H','L','I'},
                {'E','G','J','D','A','H','I','K'},
                {'E','J','I','D','A','F','L','K'},
                {'H','J','E','D','A','F','L','K'},
                {'H','E','I','D','A','F','L','K'},
                {'H','J','E','D','A','F','L','I'},
                {'H','J','E','D','A','F','I','K'},
                {'E','G','J','D','A','F','L','K'},
                {'E','G','I','D','A','F','L','K'},
                {'E','G','J','D','A','F','L','I'},
                {'E','G','J','D','A','F','I','K'},
                {'H','G','E','D','A','F','L','K'},
                {'H','G','J','D','A','F','L','E'},
                {'H','G','J','D','A','F','E','K'},
                {'H','G','E','D','A','F','L','I'},
                {'H','G','E','D','A','F','I','K'},
                {'H', 'G', 'J', 'D', 'A', 'F', 'E', 'I'},
                {'H', 'J', 'I', 'C', 'A', 'G', 'L', 'K'},
                {'H', 'J', 'I', 'C', 'A', 'F', 'L', 'K'},
                {'I', 'G', 'J', 'C', 'A', 'F', 'L', 'K'},
                {'H', 'G', 'J', 'C', 'A', 'F', 'L', 'K'},
                {'H', 'G', 'I', 'C', 'A', 'F', 'L', 'K'},
                {'H', 'G', 'J', 'C', 'A', 'F', 'L', 'I'},
                {'H', 'G', 'J', 'C', 'A', 'F', 'I', 'K'},
                {'E', 'J', 'I', 'C', 'A', 'H', 'L', 'K'},
                {'E', 'J', 'I', 'C', 'A', 'G', 'L', 'K'},
                {'E', 'G', 'J', 'C', 'A', 'H', 'L', 'K'},
                {'E', 'G', 'I', 'C', 'A', 'H', 'L', 'K'},
                {'E', 'G', 'J', 'C', 'A', 'H', 'L', 'I'},
                {'E', 'G', 'J', 'C', 'A', 'H', 'I', 'K'},
                {'E', 'J', 'I', 'C', 'A', 'F', 'L', 'K'},
                {'H', 'J', 'E', 'C', 'A', 'F', 'L', 'K'},
                {'H', 'E', 'I', 'C', 'A', 'F', 'L', 'K'},
                {'H', 'J', 'E', 'C', 'A', 'F', 'L', 'I'},
                {'H', 'J', 'E', 'C', 'A', 'F', 'I', 'K'},
                {'E', 'G', 'J', 'C', 'A', 'F', 'L', 'K'},
                {'E', 'G', 'I', 'C', 'A', 'F', 'L', 'K'},
                {'E', 'G', 'J', 'C', 'A', 'F', 'L', 'I'},
                {'E', 'G', 'J', 'C', 'A', 'F', 'I', 'K'},
                {'H', 'G', 'E', 'C', 'A', 'F', 'L', 'K'},
                {'H', 'G', 'J', 'C', 'A', 'F', 'L', 'E'},
                {'H', 'G', 'J', 'C', 'A', 'F', 'E', 'K'},
                {'H', 'G', 'E', 'C', 'A', 'F', 'L', 'I'},
                {'H', 'G', 'E', 'C', 'A', 'F', 'I', 'K'},
                {'H', 'G', 'J', 'C', 'A', 'F', 'E', 'I'},
                {'H', 'J', 'I', 'C', 'A', 'D', 'L', 'K'},
                {'I', 'G', 'J', 'C', 'A', 'D', 'L', 'K'},
                {'H', 'G', 'J', 'C', 'A', 'D', 'L', 'K'},
                {'H', 'G', 'I', 'C', 'A', 'D', 'L', 'K'},
                {'H', 'G', 'J', 'C', 'A', 'D', 'L', 'I'},
                {'H', 'G', 'J', 'C', 'A', 'D', 'I', 'K'},
                {'C', 'J', 'I', 'D', 'A', 'F', 'L', 'K'},
                {'H', 'J', 'F', 'C', 'A', 'D', 'L', 'K'},
                {'H', 'F', 'I', 'C', 'A', 'D', 'L', 'K'},
                {'H', 'J', 'F', 'C', 'A', 'D', 'L', 'I'},
                {'H', 'J', 'F', 'C', 'A', 'D', 'I', 'K'},
                {'C', 'G', 'J', 'D', 'A', 'F', 'L', 'K'},
                {'C', 'G', 'I', 'D', 'A', 'F', 'L', 'K'},
                {'C', 'G', 'J', 'D', 'A', 'F', 'L', 'I'},
                {'C', 'G', 'J', 'D', 'A', 'F', 'I', 'K'},
                {'H', 'G', 'F', 'C', 'A', 'D', 'L', 'K'},
                {'C', 'G', 'J', 'D', 'A', 'F', 'L', 'H'},
                {'H', 'G', 'J', 'C', 'A', 'F', 'D', 'K'},
                {'H', 'G', 'F', 'C', 'A', 'D', 'L', 'I'},
                {'H', 'G', 'F', 'C', 'A', 'D', 'I', 'K'},
                {'H', 'G', 'J', 'C', 'A', 'F', 'D', 'I'},
                {'E', 'J', 'I', 'C', 'A', 'D', 'L', 'K'},
                {'H', 'J', 'E', 'C', 'A', 'D', 'L', 'K'},
                {'H', 'E', 'I', 'C', 'A', 'D', 'L', 'K'},
                {'H', 'J', 'E', 'C', 'A', 'D', 'L', 'I'},
                {'H', 'J', 'E', 'C', 'A', 'D', 'I', 'K'},
                {'E', 'G', 'J', 'C', 'A', 'D', 'L', 'K'},
                {'E', 'G', 'I', 'C', 'A', 'D', 'L', 'K'},
                {'E', 'G', 'J', 'C', 'A', 'D', 'L', 'I'},
                {'E', 'G', 'J', 'C', 'A', 'D', 'I', 'K'},
                {'H', 'G', 'E', 'C', 'A', 'D', 'L', 'K'},
                {'H', 'G', 'J', 'C', 'A', 'D', 'L', 'E'},
                {'H', 'G', 'J', 'C', 'A', 'D', 'E', 'K'},
                {'H', 'G', 'E', 'C', 'A', 'D', 'L', 'I'},
                {'H', 'G', 'E', 'C', 'A', 'D', 'I', 'K'},
                {'H', 'G', 'J', 'C', 'A', 'D', 'E', 'I'},
                {'C', 'J', 'E', 'D', 'A', 'F', 'L', 'K'},
                {'C', 'E', 'I', 'D', 'A', 'F', 'L', 'K'},
                {'C', 'J', 'E', 'D', 'A', 'F', 'L', 'I'},
                {'C', 'J', 'E', 'D', 'A', 'F', 'I', 'K'},
                {'H', 'E', 'F', 'C', 'A', 'D', 'L', 'K'},
                {'H', 'J', 'F', 'C', 'A', 'D', 'L', 'E'},
                {'H', 'J', 'E', 'C', 'A', 'F', 'D', 'K'},
                {'H', 'E', 'F', 'C', 'A', 'D', 'L', 'I'},
                {'H', 'E', 'F', 'C', 'A', 'D', 'I', 'K'},
                {'H', 'J', 'E', 'C', 'A', 'F', 'D', 'I'},
                {'C', 'G', 'E', 'D', 'A', 'F', 'L', 'K'},
                {'C', 'G', 'J', 'D', 'A', 'F', 'L', 'E'},
                {'C', 'G', 'J', 'D', 'A', 'F', 'E', 'K'},
                {'C', 'G', 'E', 'D', 'A', 'F', 'L', 'I'},
                {'C', 'G', 'E', 'D', 'A', 'F', 'I', 'K'},
                {'C', 'G', 'J', 'D', 'A', 'F', 'E', 'I'},
                {'H', 'G', 'F', 'C', 'A', 'D', 'L', 'E'},
                {'H', 'G', 'E', 'C', 'A', 'F', 'D', 'K'},
                {'H', 'G', 'J', 'C', 'A', 'F', 'D', 'E'},
                {'H', 'G', 'E', 'C', 'A', 'F', 'D', 'I'},
                {'H', 'J', 'B', 'A', 'I', 'G', 'L', 'K'},
                {'H', 'J', 'B', 'A', 'I', 'F', 'L', 'K'},
                {'I', 'J', 'B', 'F', 'A', 'G', 'L', 'K'},
                {'H', 'J', 'B', 'F', 'A', 'G', 'L', 'K'},
                {'H', 'G', 'B', 'A', 'I', 'F', 'L', 'K'},
                {'H', 'J', 'B', 'F', 'A', 'G', 'L', 'I'},
                {'H', 'J', 'B', 'F', 'A', 'G', 'I', 'K'},
                {'E', 'J', 'B', 'A', 'I', 'H', 'L', 'K'},
                {'E', 'J', 'B', 'A', 'I', 'G', 'L', 'K'},
                {'E', 'J', 'B', 'A', 'H', 'G', 'L', 'K'},
                {'E', 'G', 'B', 'A', 'I', 'H', 'L', 'K'},
                {'E', 'J', 'B', 'A', 'H', 'G', 'L', 'I'},
                {'E', 'J', 'B', 'A', 'H', 'G', 'I', 'K'},
                {'E', 'J', 'B', 'A', 'I', 'F', 'L', 'K'},
                {'E', 'J', 'B', 'F', 'A', 'H', 'L', 'K'},
                /* 301 */ { 'E','I','B','F','A','H','L','K' },
                /* 302 */ { 'E','J','B','F','A','H','L','I' },
                /* 303 */ { 'E','J','B','F','A','H','I','K' },
                /* 304 */ { 'E','J','B','F','A','G','L','K' },
                /* 305 */ { 'E','G','B','A','I','F','L','K' },
                /* 306 */ { 'E','J','B','F','A','G','L','I' },
                /* 307 */ { 'E','J','B','F','A','G','I','K' },
                /* 308 */ { 'E','G','B','F','A','H','L','K' },
                /* 309 */ { 'H','J','B','F','A','G','L','E' },
                /* 310 */ { 'H','J','B','F','A','G','E','K' },
                /* 311 */ { 'E','G','B','F','A','H','L','I' },
                /* 312 */ { 'E','G','B','F','A','H','I','K' },
                /* 313 */ { 'H','J','B','F','A','G','E','I' },
                /* 314 */ { 'I','J','B','D','A','H','L','K' },
                /* 315 */ { 'I','J','B','D','A','G','L','K' },
                /* 316 */ { 'H','J','B','D','A','G','L','K' },
                /* 317 */ { 'I','G','B','D','A','H','L','K' },
                /* 318 */ { 'H','J','B','D','A','G','L','I' },
                /* 319 */ { 'H','J','B','D','A','G','I','K' },
                /* 320 */ { 'I','J','B','D','A','F','L','K' },
                /* 321 */ { 'H','J','B','D','A','F','L','K' },
                /* 322 */ { 'H','I','B','D','A','F','L','K' },
                /* 323 */ { 'H','J','B','D','A','F','L','I' },
                /* 324 */ { 'H','J','B','D','A','F','I','K' },
                /* 325 */ { 'F','J','B','D','A','G','L','K' },
                /* 326 */ { 'I','G','B','D','A','F','L','K' },
                /* 327 */ { 'F','J','B','D','A','G','L','I' },
                /* 328 */ { 'F','J','B','D','A','G','I','K' },
                /* 329 */ { 'H','G','B','D','A','F','L','K' },
                /* 330 */ { 'H','G','B','D','A','F','L','J' },
                /* 331 */ { 'H','G','B','D','A','F','J','K' },
                /* 332 */ { 'H','G','B','D','A','F','L','I' },
                /* 333 */ { 'H','G','B','D','A','F','I','K' },
                /* 334 */ { 'H','G','B','D','A','F','I','J' },
                /* 335 */ { 'E','J','B','A','I','D','L','K' },
                /* 336 */ { 'E','J','B','D','A','H','L','K' },
                /* 337 */ { 'E','I','B','D','A','H','L','K' },
                /* 338 */ { 'E','J','B','D','A','H','L','I' },
                /* 339 */ { 'E','J','B','D','A','H','I','K' },
                /* 340 */ { 'E','J','B','D','A','G','L','K' },
                /* 341 */ { 'E','G','B','A','I','D','L','K' },
                /* 342 */ { 'E','J','B','D','A','G','L','I' },
                /* 343 */ { 'E','J','B','D','A','G','I','K' },
                /* 344 */ { 'E','G','B','D','A','H','L','K' },
                /* 345 */ { 'H','J','B','D','A','G','L','E' },
                /* 346 */ { 'H','J','B','D','A','G','E','K' },
                /* 347 */ { 'E','G','B','D','A','H','L','I' },
                /* 348 */ { 'E','G','B','D','A','H','I','K' },
                /* 349 */ { 'H','J','B','D','A','G','E','I' },
                /* 350 */ { 'E','J','B','D','A','F','L','K' },
                /* 351 */ { 'E','I','B','D','A','F','L','K' },
                /* 352 */ { 'E','J','B','D','A','F','L','I' },
                /* 353 */ { 'E','J','B','D','A','F','I','K' },
                /* 354 */ { 'H','E','B','D','A','F','L','K' },
                /* 355 */ { 'H','J','B','D','A','F','L','E' },
                /* 356 */ { 'H','J','B','D','A','F','E','K' },
                /* 357 */ { 'H','E','B','D','A','F','L','I' },
                /* 358 */ { 'H','E','B','D','A','F','I','K' },
                /* 359 */ { 'H','J','B','D','A','F','E','I' },
                /* 360 */ { 'E','G','B','D','A','F','L','K' },
                /* 361 */ { 'E','G','B','D','A','F','L','J' },
                /* 362 */ { 'E','G','B','D','A','F','J','K' },
                /* 363 */ { 'E','G','B','D','A','F','L','I' },
                /* 364 */ { 'E','G','B','D','A','F','I','K' },
                /* 365 */ { 'E','G','B','D','A','F','I','J' },
                /* 366 */ { 'H','G','B','D','A','F','L','E' },
                /* 367 */ { 'H','G','B','D','A','F','E','K' },
                /* 368 */ { 'H','G','B','D','A','F','E','J' },
                /* 369 */ { 'H','G','B','D','A','F','E','I' },
                /* 370 */ { 'I','J','B','C','A','H','L','K' },
                /* 371 */ { 'I','J','B','C','A','G','L','K' },
                /* 372 */ { 'H','J','B','C','A','G','L','K' },
                /* 373 */ { 'I','G','B','C','A','H','L','K' },
                /* 374 */ { 'H','J','B','C','A','G','L','I' },
                /* 375 */ { 'H','J','B','C','A','G','I','K' },
                /* 376 */ { 'I','J','B','C','A','F','L','K' },
                /* 377 */ { 'H','J','B','C','A','F','L','K' },
                /* 378 */ { 'H','I','B','C','A','F','L','K' },
                /* 379 */ { 'H','J','B','C','A','F','L','I' },
                /* 380 */ { 'H','J','B','C','A','F','I','K' },
                /* 381 */ { 'C','J','B','F','A','G','L','K' },
                /* 382 */ { 'I','G','B','C','A','F','L','K' },
                /* 383 */ { 'C','J','B','F','A','G','L','I' },
                /* 384 */ { 'C','J','B','F','A','G','I','K' },
                /* 385 */ { 'H','G','B','C','A','F','L','K' },
                /* 386 */ { 'H','G','B','C','A','F','L','J' },
                /* 387 */ { 'H','G','B','C','A','F','J','K' },
                /* 388 */ { 'H','G','B','C','A','F','L','I' },
                /* 389 */ { 'H','G','B','C','A','F','I','K' },
                /* 390 */ { 'H','G','B','C','A','F','I','J' },
                /* 391 */ { 'E','J','B','A','I','C','L','K' },
                /* 392 */ { 'E','J','B','C','A','H','L','K' },
                /* 393 */ { 'E','I','B','C','A','H','L','K' },
                /* 394 */ { 'E','J','B','C','A','H','L','I' },
                /* 395 */ { 'E','J','B','C','A','H','I','K' },
                /* 396 */ { 'E','J','B','C','A','G','L','K' },
                /* 397 */ { 'E','G','B','A','I','C','L','K' },
                /* 398 */ { 'E','J','B','C','A','G','L','I' },
                /* 399 */ { 'E','J','B','C','A','G','I','K' },
                /* 400 */ { 'E','G','B','C','A','H','L','K' },
                /* 401 */ { 'H','J','B','C','A','G','L','E' },
                /* 402 */ { 'H','J','B','C','A','G','E','K' },
                /* 403 */ { 'E','G','B','C','A','H','L','I' },
                /* 404 */ { 'E','G','B','C','A','H','I','K' },
                /* 405 */ { 'H','J','B','C','A','G','E','I' },
                /* 406 */ { 'E','J','B','C','A','F','L','K' },
                /* 407 */ { 'E','I','B','C','A','F','L','K' },
                /* 408 */ { 'E','J','B','C','A','F','L','I' },
                /* 409 */ { 'E','J','B','C','A','F','I','K' },
                /* 410 */ { 'H','E','B','C','A','F','L','K' },
                /* 411 */ { 'H','J','B','C','A','F','L','E' },
                /* 412 */ { 'H','J','B','C','A','F','E','K' },
                /* 413 */ { 'H','E','B','C','A','F','L','I' },
                /* 414 */ { 'H','E','B','C','A','F','I','K' },
                /* 415 */ { 'H','J','B','C','A','F','E','I' },
                /* 416 */ { 'E','G','B','C','A','F','L','K' },
                /* 417 */ { 'E','G','B','C','A','F','L','J' },
                /* 418 */ { 'E','G','B','C','A','F','J','K' },
                /* 419 */ { 'E','G','B','C','A','F','L','I' },
                /* 420 */ { 'E','G','B','C','A','F','I','K' },
                /* 421 */ { 'E','G','B','C','A','F','I','J' },
                /* 422 */ { 'H','G','B','C','A','F','L','E' },
                /* 423 */ { 'H','G','B','C','A','F','E','K' },
                /* 424 */ { 'H','G','B','C','A','F','E','J' },
                /* 425 */ { 'H','G','B','C','A','F','E','I' },
                /* 426 */ { 'I','J','B','C','A','D','L','K' },
                /* 427 */ { 'H','J','B','C','A','D','L','K' },
                /* 428 */ { 'H','I','B','C','A','D','L','K' },
                /* 429 */ { 'H','J','B','C','A','D','L','I' },
                /* 430 */ { 'H','J','B','C','A','D','I','K' },
                /* 431 */ { 'C','J','B','D','A','G','L','K' },
                /* 432 */ { 'I','G','B','C','A','D','L','K' },
                /* 433 */ { 'C','J','B','D','A','G','L','I' },
                /* 434 */ { 'C','J','B','D','A','G','I','K' },
                /* 435 */ { 'H','G','B','C','A','D','L','K' },
                /* 436 */ { 'H','G','B','C','A','D','L','J' },
                /* 437 */ { 'H','G','B','C','A','D','J','K' },
                /* 438 */ { 'H','G','B','C','A','D','L','I' },
                /* 439 */ { 'H','G','B','C','A','D','I','K' },
                /* 440 */ { 'H','G','B','C','A','D','I','J' },
                /* 441 */ { 'C','J','B','D','A','F','L','K' },
                /* 442 */ { 'C','I','B','D','A','F','L','K' },
                /* 443 */ { 'C','J','B','D','A','F','L','I' },
                /* 444 */ { 'C','J','B','D','A','F','I','K' },
                /* 445 */ { 'H','F','B','C','A','D','L','K' },
                /* 446 */ { 'C','J','B','D','A','F','L','H' },
                /* 447 */ { 'H','J','B','C','A','F','D','K' },
                /* 448 */ { 'H','F','B','C','A','D','L','I' },
                /* 449 */ { 'H','F','B','C','A','D','I','K' },
                /* 450 */ { 'H','J','B','C','A','F','D','I' },
                /* 451 */ { 'C','G','B','D','A','F','L','K' },
                /* 452 */ { 'C','G','B','D','A','F','L','J' },
                /* 453 */ { 'C','G','B','D','A','F','J','K' },
                /* 454 */ { 'C','G','B','D','A','F','L','I' },
                /* 455 */ { 'C','G','B','D','A','F','I','K' },
                /* 456 */ { 'C','G','B','D','A','F','I','J' },
                /* 457 */ { 'C','G','B','D','A','F','L','H' },
                /* 458 */ { 'H','G','B','C','A','F','D','K' },
                /* 459 */ { 'H','G','B','C','A','F','D','J' },
                /* 460 */ { 'H','G','B','C','A','F','D','I' },
                /* 461 */ { 'E','J','B','C','A','D','L','K' },
                /* 462 */ { 'E','I','B','C','A','D','L','K' },
                /* 463 */ { 'E','J','B','C','A','D','L','I' },
                /* 464 */ { 'E','J','B','C','A','D','I','K' },
                /* 465 */ { 'H','E','B','C','A','D','L','K' },
                /* 466 */ { 'H','J','B','C','A','D','L','E' },
                /* 467 */ { 'H','J','B','C','A','D','E','K' },
                /* 468 */ { 'H','E','B','C','A','D','L','I' },
                /* 469 */ { 'H','E','B','C','A','D','I','K' },
                /* 470 */ { 'H','J','B','C','A','D','E','I' },
                /* 471 */ { 'E','G','B','C','A','D','L','K' },
                /* 472 */ { 'E','G','B','C','A','D','L','J' },
                /* 473 */ { 'E','G','B','C','A','D','J','K' },
                /* 474 */ { 'E','G','B','C','A','D','L','I' },
                /* 475 */ { 'E','G','B','C','A','D','I','K' },
                /* 476 */ { 'E','G','B','C','A','D','I','J' },
                /* 477 */ { 'H','G','B','C','A','D','L','E' },
                /* 478 */ { 'H','G','B','C','A','D','E','K' },
                /* 479 */ { 'H','G','B','C','A','D','E','J' },
                /* 480 */ { 'H','G','B','C','A','D','E','I' },
                /* 481 */ { 'C','E','B','D','A','F','L','K' },
                /* 482 */ { 'C','J','B','D','A','F','L','E' },
                /* 483 */ { 'C','J','B','D','A','F','E','K' },
                /* 484 */ { 'C','E','B','D','A','F','L','I' },
                /* 485 */ { 'C','E','B','D','A','F','I','K' },
                /* 486 */ { 'C','J','B','D','A','F','E','I' },
                /* 487 */ { 'H','F','B','C','A','D','L','E' },
                /* 488 */ { 'H','E','B','C','A','F','D','K' },
                /* 489 */ { 'H','J','B','C','A','F','D','E' },
                /* 490 */ { 'H','E','B','C','A','F','D','I' },
                /* 491 */ { 'C','G','B','D','A','F','L','E' },
                /* 492 */ { 'C','G','B','D','A','F','E','K' },
                /* 493 */ { 'C','G','B','D','A','F','E','J' },
                /* 494 */ { 'C','G','B','D','A','F','E','I' },
                /* 495 */ { 'H','G','B','C','A','F','D','E' },

    };



typedef struct selecao
{
    char nome[100];
    int pontos;
    int vitorias;
    int derrotas;
    int empates;
    int gols_marcados;
    int gols_sofridos;
    char grupo;
}selecao;

typedef struct jogo{
    int gols_mandante;
    int gols_visitante;
}jogo;

typedef struct grupo{
    selecao a;
    selecao b;
    selecao c;
    selecao d;
}grupo;

typedef struct repescagem_euro{
    selecao a;
    selecao b;
    selecao c;
    selecao d;
}repescagem_euro;
typedef struct repescagem_mundo{
    selecao a;
    selecao b;
    selecao c;
}repescagem_mundo;

typedef struct terceiros_passados
{
   selecao classificadas[8];
   char grupos[8];    
}terceiros_passados;

jogo jogo_normal(selecao * a, selecao* b){
    jogo x;
    int gols_a,gols_b;
    printf("\nJOGO %s x %s \n", a->nome, b->nome);
    printf("Digite a quantidade de gols marcados por(a) %s ", a->nome);
    scanf("%d",&gols_a);
    printf("Digite a quantidade de gols marcados por(a) %s ", b->nome);
    scanf("%d",&gols_b);
    printf("Placar final: %s %d x %d %s", a->nome, gols_a, gols_b, b->nome);
    a->gols_marcados += gols_a;
    b->gols_marcados += gols_b;
    a->gols_sofridos += gols_b;
    b->gols_sofridos += gols_a;
    if(gols_a>gols_b){
        a->vitorias +=1;
        b->derrotas +=1;
        a->pontos += 3;
    }
    if(gols_a==gols_b){
        a->empates +=1;
        b->empates +=1;
        a->pontos += 1;
        b->pontos +=1;
    }
    if(gols_a<gols_b){
        b->vitorias +=1;
        a->derrotas +=1;
        b->pontos += 3;
    }
    x.gols_mandante = gols_a;
    x.gols_visitante = gols_b;
    return x;
}
selecao mata_mata(selecao a, selecao b){
    int gols_a,gols_b;
    printf("\nJOGO %s x %s \n", a.nome, b.nome);
    printf("Digite a quantidade de gols marcados por(a) %s ", a.nome);
    scanf("%d",&gols_a);
    printf("Digite a quantidade de gols marcados por(a) %s ", b.nome);
    scanf("%d",&gols_b);
    printf("Placar final: %s %d x %d %s", a.nome, gols_a, gols_b, b.nome);
    if(gols_a>gols_b){
        return a;
    }
    if(gols_a==gols_b){
        int gols_a_2, gols_b_2;
        printf("\nDigite a quantidade de gols marcados na prorrogacao por(a) %s ", a.nome);
        scanf("%d",&gols_a_2);
        printf("\nDigite a quantidade de gols marcados na prorrogacao por(a) %s ", b.nome);
        scanf("%d",&gols_b_2);
        printf("\nPlacar final: %s %d x %d %s", a.nome, gols_a+gols_a_2, gols_b+gols_b_2, b.nome);
        gols_a += gols_a_2;
        gols_b += gols_b_2;
        if(gols_a>gols_b){
            return a;
        }
        if(gols_a==gols_b){
            int gols_a_2, gols_b_2;
            printf("\nDigite a quantidade de gols marcados nos penâltis por(a) %s ", a.nome);
            scanf("%d",&gols_a_2);
            printf("\nDigite a quantidade de gols marcados nos penaltis por(a) %s ", b.nome);
            scanf("%d",&gols_b_2);
            printf("\nPlacar final: %s %d x %d %s", a.nome, gols_a_2, gols_b_2, b.nome);
            if(gols_a_2 > gols_b_2){
                return a;
            }
            if(gols_b_2 > gols_a_2){
                return b;
            }
            if(gols_a_2==gols_b_2){
                printf("Placar empatado, selecione um vencedor");
                int escolhido;
                printf("Digite 1 para %s e 2 para %s", a.nome, b.nome);
                scanf("%d", &escolhido);
                if(escolhido == 1){
                    return a;
                }
                if(escolhido == 2){
                    return b;
                }
            }
        }
        if(gols_a<gols_b){
            return b;
        }
    }
    if(gols_a<gols_b){
        return b;
    }
    selecao c = {0};
    return c;
}

//Cria-se as seleções
selecao cria_brasil(){
    selecao x;
    strcpy(x.nome, "Brasil");
    x.derrotas = 0;
    x.empates = 0;
    x.vitorias = 0;
    x.gols_marcados = 0;
    x.gols_sofridos = 0;
    x.pontos = 0;
    x.grupo = 'c';
    return x;
}
selecao cria_marrocos(){
    selecao x;
    strcpy(x.nome, "Marrocos");
    x.derrotas = 0;
    x.empates = 0;
    x.vitorias = 0;
    x.gols_marcados = 0;
    x.gols_sofridos = 0;
    x.pontos = 0;
    x.grupo = 'c';
    return x;
}
selecao cria_mexico(){
    selecao x;
    strcpy(x.nome, "Mexico");
    x.derrotas = 0;
    x.empates = 0;
    x.vitorias = 0;
    x.gols_marcados = 0;
    x.gols_sofridos = 0;
    x.pontos = 0;
    x.grupo = 'a';
    return x;
}
selecao cria_africa_do_sul(){
    selecao x;
    strcpy(x.nome, "Africa do Sul");
    x.derrotas = 0;
    x.empates = 0;
    x.vitorias = 0;
    x.gols_marcados = 0;
    x.gols_sofridos = 0;
    x.pontos = 0;
    x.grupo = 'a';
    return x;
}
selecao cria_coreia(){
    selecao x;
    strcpy(x.nome, "Coreia do Sul");
    x.derrotas = 0;
    x.empates = 0;
    x.vitorias = 0;
    x.gols_marcados = 0;
    x.gols_sofridos = 0;
    x.pontos = 0;
    x.grupo = 'a';
    return x;
}
selecao cria_dinamarca(){
    selecao x;
    strcpy(x.nome, "Dinamarca");
    x.derrotas = 0;
    x.empates = 0;
    x.vitorias = 0;
    x.gols_marcados = 0;
    x.gols_sofridos = 0;
    x.pontos = 0;
    x.grupo = 'a';
    return x;
}
selecao cria_macedonia(){
    selecao x;
    strcpy(x.nome, "Macedonia do Norte");
    x.derrotas = 0;
    x.empates = 0;
    x.vitorias = 0;
    x.gols_marcados = 0;
    x.gols_sofridos = 0;
    x.pontos = 0;
    x.grupo = 'a';
    return x;
}
selecao cria_tcheca(){
    selecao x;
    strcpy(x.nome, "Republica Tcheca");
    x.derrotas = 0;
    x.empates = 0;
    x.vitorias = 0;
    x.gols_marcados = 0;
    x.gols_sofridos = 0;
    x.pontos = 0;
    x.grupo = 'a';
    return x;
}
selecao cria_irlanda(){
    selecao x;
    strcpy(x.nome, "Irlanda");
    x.derrotas = 0;
    x.empates = 0;
    x.vitorias = 0;
    x.gols_marcados = 0;
    x.gols_sofridos = 0;
    x.pontos = 0;
    x.grupo = 'a';
    return x;
}
selecao cria_canada(){
    selecao x;
    strcpy(x.nome, "Canada");
    x.derrotas = 0;
    x.empates = 0;
    x.vitorias = 0;
    x.gols_marcados = 0;
    x.gols_sofridos = 0;
    x.pontos = 0;
    x.grupo = 'b';
    return x;
}
selecao cria_Congo(){
    selecao x;
    strcpy(x.nome, "Congo");
    x.derrotas = 0;
    x.empates = 0;
    x.vitorias = 0;
    x.gols_marcados = 0;
    x.gols_sofridos = 0;
    x.pontos = 0;
    x.grupo = 'k';
    return x;
}
selecao cria_Jamaica(){
    selecao x;
    strcpy(x.nome, "Jamaica");
    x.derrotas = 0;
    x.empates = 0;
    x.vitorias = 0;
    x.gols_marcados = 0;
    x.gols_sofridos = 0;
    x.pontos = 0;
    x.grupo = 'k';
    return x;
}
selecao cria_caledonia(){
    selecao x;
    strcpy(x.nome, "Nova caledonia");
    x.derrotas = 0;
    x.empates = 0;
    x.vitorias = 0;
    x.gols_marcados = 0;
    x.gols_sofridos = 0;
    x.pontos = 0;
    x.grupo = 'k';
    return x;
}
selecao cria_Qatar(){
    selecao x;
    strcpy(x.nome, "Qatar");
    x.derrotas = 0;
    x.empates = 0;
    x.vitorias = 0;
    x.gols_marcados = 0;
    x.gols_sofridos = 0;
    x.pontos = 0;
    x.grupo = 'b';
    return x;
}
selecao cria_Suica(){
    selecao x;
    strcpy(x.nome, "Suiça");
    x.derrotas = 0;
    x.empates = 0;
    x.vitorias = 0;
    x.gols_marcados = 0;
    x.gols_sofridos = 0;
    x.pontos = 0;
    x.grupo = 'b';
    return x;
}
selecao cria_Haiti(){
    selecao x;
    strcpy(x.nome, "Haiti");
    x.derrotas = 0;
    x.empates = 0;
    x.vitorias = 0;
    x.gols_marcados = 0;
    x.gols_sofridos = 0;
    x.pontos = 0;
    x.grupo = 'c';
    return x;
}
selecao cria_Escocia(){
    selecao x;
    strcpy(x.nome, "Escocia");
    x.derrotas = 0;
    x.empates = 0;
    x.vitorias = 0;
    x.gols_marcados = 0;
    x.gols_sofridos = 0;
    x.pontos = 0;
    x.grupo = 'c';
    return x;
}
selecao cria_USA(){
    selecao x;
    strcpy(x.nome, "Estados Unidos");
    x.derrotas = 0;
    x.empates = 0;
    x.vitorias = 0;
    x.gols_marcados = 0;
    x.gols_sofridos = 0;
    x.pontos = 0;
    x.grupo = 'd';
    return x;
}
selecao cria_Paraguai(){
    selecao x;
    strcpy(x.nome, "Paraguai");
    x.derrotas = 0;
    x.empates = 0;
    x.vitorias = 0;
    x.gols_marcados = 0;
    x.gols_sofridos = 0;
    x.pontos = 0;
    x.grupo = 'd';
    return x;
}
selecao cria_Australia(){
    selecao x;
    strcpy(x.nome, "Australia");
    x.derrotas = 0;
    x.empates = 0;
    x.vitorias = 0;
    x.gols_marcados = 0;
    x.gols_sofridos = 0;
    x.pontos = 0;
    x.grupo = 'd';
    return x;
}
selecao cria_Turquia(){
    selecao x;
    strcpy(x.nome, "Turquia");
    x.derrotas = 0;
    x.empates = 0;
    x.vitorias = 0;
    x.gols_marcados = 0;
    x.gols_sofridos = 0;
    x.pontos = 0;
    x.grupo = 'd';
    return x;
}
selecao cria_Romenia(){
    selecao x;
    strcpy(x.nome, "Romenia");
    x.derrotas = 0;
    x.empates = 0;
    x.vitorias = 0;
    x.gols_marcados = 0;
    x.gols_sofridos = 0;
    x.pontos = 0;
    x.grupo = 'd';
    return x;
}
selecao cria_Eslovaquia(){
    selecao x;
    strcpy(x.nome, "Eslovaquia");
    x.derrotas = 0;
    x.empates = 0;
    x.vitorias = 0;
    x.gols_marcados = 0;
    x.gols_sofridos = 0;
    x.pontos = 0;
    x.grupo = 'd';
    return x;
}
selecao cria_Kosovo(){
    selecao x;
    strcpy(x.nome, "Kosovo");
    x.derrotas = 0;
    x.empates = 0;
    x.vitorias = 0;
    x.gols_marcados = 0;
    x.gols_sofridos = 0;
    x.pontos = 0;
    x.grupo = 'd';
    return x;
}
selecao cria_Alemanha(){
    selecao x;
    strcpy(x.nome, "Alemanha");
    x.derrotas = 0;
    x.empates = 0;
    x.vitorias = 0;
    x.gols_marcados = 0;
    x.gols_sofridos = 0;
    x.pontos = 0;
    x.grupo = 'e';
    return x;
}
selecao cria_Curacao(){
    selecao x;
    strcpy(x.nome, "Curacao");
    x.derrotas = 0;
    x.empates = 0;
    x.vitorias = 0;
    x.gols_marcados = 0;
    x.gols_sofridos = 0;
    x.pontos = 0;
    x.grupo = 'e';
    return x;
}
selecao cria_Costa_do_Marfim(){
    selecao x;
    strcpy(x.nome, "Costa do Marfim");
    x.derrotas = 0;
    x.empates = 0;
    x.vitorias = 0;
    x.gols_marcados = 0;
    x.gols_sofridos = 0;
    x.pontos = 0;
    x.grupo = 'e';
    return x;
}
selecao cria_Equador(){
    selecao x;
    strcpy(x.nome, "Equador");
    x.derrotas = 0;
    x.empates = 0;
    x.vitorias = 0;
    x.gols_marcados = 0;
    x.gols_sofridos = 0;
    x.pontos = 0;
    x.grupo = 'e';
    return x;
}
selecao cria_Holanda(){
    selecao x;
    strcpy(x.nome, "Holanda");
    x.derrotas = 0;
    x.empates = 0;
    x.vitorias = 0;
    x.gols_marcados = 0;
    x.gols_sofridos = 0;
    x.pontos = 0;
    x.grupo = 'f';
    return x;
}
selecao cria_Japao(){
    selecao x;
    strcpy(x.nome, "Japao");
    x.derrotas = 0;
    x.empates = 0;
    x.vitorias = 0;
    x.gols_marcados = 0;
    x.gols_sofridos = 0;
    x.pontos = 0;
    x.grupo = 'f';
    return x;
}
selecao cria_Ucrania(){
    selecao x;
    strcpy(x.nome, "Ucrania");
    x.derrotas = 0;
    x.empates = 0;
    x.vitorias = 0;
    x.gols_marcados = 0;
    x.gols_sofridos = 0;
    x.pontos = 0;
    x.grupo = 'f';
    return x;
}
selecao cria_Suecia(){
    selecao x;
    strcpy(x.nome, "Suecia");
    x.derrotas = 0;
    x.empates = 0;
    x.vitorias = 0;
    x.gols_marcados = 0;
    x.gols_sofridos = 0;
    x.pontos = 0;
    x.grupo = 'f';
    return x;
}
selecao cria_Polonia(){
    selecao x;
    strcpy(x.nome, "Polonia");
    x.derrotas = 0;
    x.empates = 0;
    x.vitorias = 0;
    x.gols_marcados = 0;
    x.gols_sofridos = 0;
    x.pontos = 0;
    x.grupo = 'f';
    return x;
}
selecao cria_Albania(){
    selecao x;
    strcpy(x.nome, "Albania");
    x.derrotas = 0;
    x.empates = 0;
    x.vitorias = 0;
    x.gols_marcados = 0;
    x.gols_sofridos = 0;
    x.pontos = 0;
    x.grupo = 'f';
    return x;
}
selecao cria_Tunisia(){
    selecao x;
    strcpy(x.nome, "Tunisia");
    x.derrotas = 0;
    x.empates = 0;
    x.vitorias = 0;
    x.gols_marcados = 0;
    x.gols_sofridos = 0;
    x.pontos = 0;
    x.grupo = 'f';
    return x;
}
selecao cria_Belgica(){
    selecao x;
    strcpy(x.nome, "Belgica");
    x.derrotas = 0;
    x.empates = 0;
    x.vitorias = 0;
    x.gols_marcados = 0;
    x.gols_sofridos = 0;
    x.pontos = 0;
    x.grupo = 'g';
    return x;
}
selecao cria_Egito(){
    selecao x;
    strcpy(x.nome, "Egito");
    x.derrotas = 0;
    x.empates = 0;
    x.vitorias = 0;
    x.gols_marcados = 0;
    x.gols_sofridos = 0;
    x.pontos = 0;
    x.grupo = 'g';
    return x;
}
selecao cria_Iran(){
    selecao x;
    strcpy(x.nome, "Iran");
    x.derrotas = 0;
    x.empates = 0;
    x.vitorias = 0;
    x.gols_marcados = 0;
    x.gols_sofridos = 0;
    x.pontos = 0;
    x.grupo = 'g';
    return x;
}
selecao cria_Nova_Zelandia(){
    selecao x;
    strcpy(x.nome, "Nova Zelandia");
    x.derrotas = 0;
    x.empates = 0;
    x.vitorias = 0;
    x.gols_marcados = 0;
    x.gols_sofridos = 0;
    x.pontos = 0;
    x.grupo = 'g';
    return x;
}
selecao cria_Espanha(){
    selecao x;
    strcpy(x.nome, "Espanha");
    x.derrotas = 0;
    x.empates = 0;
    x.vitorias = 0;
    x.gols_marcados = 0;
    x.gols_sofridos = 0;
    x.pontos = 0;
    x.grupo = 'h';
    return x;
}
selecao cria_Cabo_Verde(){
    selecao x;
    strcpy(x.nome, "Cabo Verde");
    x.derrotas = 0;
    x.empates = 0;
    x.vitorias = 0;
    x.gols_marcados = 0;
    x.gols_sofridos = 0;
    x.pontos = 0;
    x.grupo = 'h';
    return x;
}
selecao cria_Arabia_Saudita(){
    selecao x;
    strcpy(x.nome, "Arabia Saudita");
    x.derrotas = 0;
    x.empates = 0;
    x.vitorias = 0;
    x.gols_marcados = 0;
    x.gols_sofridos = 0;
    x.pontos = 0;
    x.grupo = 'h';
    return x;
}
selecao cria_Uruguai(){
    selecao x;
    strcpy(x.nome, "Uruguai");
    x.derrotas = 0;
    x.empates = 0;
    x.vitorias = 0;
    x.gols_marcados = 0;
    x.gols_sofridos = 0;
    x.pontos = 0;
    x.grupo = 'h';
    return x;
}
selecao cria_Franca(){
    selecao x;
    strcpy(x.nome, "Franca");
    x.derrotas = 0;
    x.empates = 0;
    x.vitorias = 0;
    x.gols_marcados = 0;
    x.gols_sofridos = 0;
    x.pontos = 0;
    x.grupo = 'i';
    return x;
}
selecao cria_Senegal(){
    selecao x;
    strcpy(x.nome, "Senegal");
    x.derrotas = 0;
    x.empates = 0;
    x.vitorias = 0;
    x.gols_marcados = 0;
    x.gols_sofridos = 0;
    x.pontos = 0;
    x.grupo = 'i';
    return x;
}
selecao cria_Irlanda_Norte(){
    selecao x;
    strcpy(x.nome, "Irlanda do Norte");
    x.derrotas = 0;
    x.empates = 0;
    x.vitorias = 0;
    x.gols_marcados = 0;
    x.gols_sofridos = 0;
    x.pontos = 0;
    x.grupo = 'b';
    return x;
}
selecao cria_Gales(){
    selecao x;
    strcpy(x.nome, "Pais de Gales");
    x.derrotas = 0;
    x.empates = 0;
    x.vitorias = 0;
    x.gols_marcados = 0;
    x.gols_sofridos = 0;
    x.pontos = 0;
    x.grupo = 'b';
    return x;
}
selecao cria_Bosnia(){
    selecao x;
    strcpy(x.nome, "Bósnia");
    x.derrotas = 0;
    x.empates = 0;
    x.vitorias = 0;
    x.gols_marcados = 0;
    x.gols_sofridos = 0;
    x.pontos = 0;
    x.grupo = 'b';
    return x;
}
selecao cria_Italia(){
    selecao x;
    strcpy(x.nome, "Italia");
    x.derrotas = 0;
    x.empates = 0;
    x.vitorias = 0;
    x.gols_marcados = 0;
    x.gols_sofridos = 0;
    x.pontos = 0;
    x.grupo = 'b';
    return x;
}
selecao cria_Noruega(){
    selecao x;
    strcpy(x.nome, "Noruega");
    x.derrotas = 0;
    x.empates = 0;
    x.vitorias = 0;
    x.gols_marcados = 0;
    x.gols_sofridos = 0;
    x.pontos = 0;
    x.grupo = 'i';
    return x;
}
selecao cria_Argentina(){
    selecao x;
    strcpy(x.nome, "Argentina");
    x.derrotas = 0;
    x.empates = 0;
    x.vitorias = 0;
    x.gols_marcados = 0;
    x.gols_sofridos = 0;
    x.pontos = 0;
    x.grupo = 'j';
    return x;
}
selecao cria_Argelia(){
    selecao x;
    strcpy(x.nome, "Argelia");
    x.derrotas = 0;
    x.empates = 0;
    x.vitorias = 0;
    x.gols_marcados = 0;
    x.gols_sofridos = 0;
    x.pontos = 0;
    x.grupo = 'j';
    return x;
}
selecao cria_Austria(){
    selecao x;
    strcpy(x.nome, "Austria");
    x.derrotas = 0;
    x.empates = 0;
    x.vitorias = 0;
    x.gols_marcados = 0;
    x.gols_sofridos = 0;
    x.pontos = 0;
    x.grupo = 'j';
    return x;
}
selecao cria_Jordania(){
    selecao x;
    strcpy(x.nome, "Jordania");
    x.derrotas = 0;
    x.empates = 0;
    x.vitorias = 0;
    x.gols_marcados = 0;
    x.gols_sofridos = 0;
    x.pontos = 0;
    x.grupo = 'j';
    return x;
}
selecao cria_Portugal(){
    selecao x;
    strcpy(x.nome, "Portugal");
    x.derrotas = 0;
    x.empates = 0;
    x.vitorias = 0;
    x.gols_marcados = 0;
    x.gols_sofridos = 0;
    x.pontos = 0;
    x.grupo = 'k';
    return x;
}
selecao cria_Iraque(){
    selecao x;
    strcpy(x.nome, "Iraque");
    x.derrotas = 0;
    x.empates = 0;
    x.vitorias = 0;
    x.gols_marcados = 0;
    x.gols_sofridos = 0;
    x.pontos = 0;
    x.grupo = 'i';
    return x;
}
selecao cria_Bolivia(){
    selecao x;
    strcpy(x.nome, "Bolivia");
    x.derrotas = 0;
    x.empates = 0;
    x.vitorias = 0;
    x.gols_marcados = 0;
    x.gols_sofridos = 0;
    x.pontos = 0;
    x.grupo = 'i';
    return x;
}
selecao cria_Suriname(){
    selecao x;
    strcpy(x.nome, "Suriname");
    x.derrotas = 0;
    x.empates = 0;
    x.vitorias = 0;
    x.gols_marcados = 0;
    x.gols_sofridos = 0;
    x.pontos = 0;
    x.grupo = 'i';
    return x;
}
selecao cria_Uzbequistao(){
    selecao x;
    strcpy(x.nome, "Uzbequistao");
    x.derrotas = 0;
    x.empates = 0;
    x.vitorias = 0;
    x.gols_marcados = 0;
    x.gols_sofridos = 0;
    x.pontos = 0;
    x.grupo = 'k';
    return x;
}
selecao cria_Colombia(){
    selecao x;
    strcpy(x.nome, "Colombia");
    x.derrotas = 0;
    x.empates = 0;
    x.vitorias = 0;
    x.gols_marcados = 0;
    x.gols_sofridos = 0;
    x.pontos = 0;
    x.grupo = 'k';
    return x;
}
selecao cria_Inglaterra(){
    selecao x;
    strcpy(x.nome, "Inglaterra");
    x.derrotas = 0;
    x.empates = 0;
    x.vitorias = 0;
    x.gols_marcados = 0;
    x.gols_sofridos = 0;
    x.pontos = 0;
    x.grupo = 'l';
    return x;
}
selecao cria_Croacia(){
    selecao x;
    strcpy(x.nome, "Croacia");
    x.derrotas = 0;
    x.empates = 0;
    x.vitorias = 0;
    x.gols_marcados = 0;
    x.gols_sofridos = 0;
    x.pontos = 0;
    x.grupo = 'l';
    return x;
}
selecao cria_Gana(){
    selecao x;
    strcpy(x.nome, "Gana");
    x.derrotas = 0;
    x.empates = 0;
    x.vitorias = 0;
    x.gols_marcados = 0;
    x.gols_sofridos = 0;
    x.pontos = 0;
    x.grupo = 'l';
    return x;
}
selecao cria_Panama(){
    selecao x;
    strcpy(x.nome, "Panama");
    x.derrotas = 0;
    x.empates = 0;
    x.vitorias = 0;
    x.gols_marcados = 0;
    x.gols_sofridos = 0;
    x.pontos = 0;
    x.grupo = 'l';
    return x;
}





repescagem_mundo mundo_rep(selecao a,selecao b,selecao c){
    repescagem_mundo x;
    x.a = a;
    x.b = b;
    x.c = c;
    return x;
}
repescagem_euro euro_rep(selecao a,selecao b,selecao c,selecao d){
    repescagem_euro x;
    x.a = a;
    x.b = b;
    x.c = c;
    x.d = d;
    return x;
}
selecao rep_mundo_jogos(repescagem_mundo x){
    selecao um;
    um = mata_mata(x.b, x.c);
    return mata_mata(um, x.a);
}
selecao rep_euro_jogos(repescagem_euro x){
    selecao um;
    selecao dois;
    um = mata_mata(x.a, x.b);
    dois = mata_mata(x.c, x.d);
    return mata_mata(um, dois);
}
grupo cria_grupo(selecao a,selecao b,selecao c,selecao d){
    grupo x;
    x.a = a;
    x.b = b;
    x.c = c;
    x.d = d;
    return x;
}


int compara(selecao x, selecao y, jogo confronto_xy){

    if (x.pontos > y.pontos) return 1;
    if (x.pontos < y.pontos) return 0;

    if (confronto_xy.gols_mandante > confronto_xy.gols_visitante) return 1;
    if (confronto_xy.gols_mandante < confronto_xy.gols_visitante) return 0;


    int saldo_x = x.gols_marcados - x.gols_sofridos;
    int saldo_y = y.gols_marcados - y.gols_sofridos;

    if (saldo_x > saldo_y) return 1;
    if (saldo_x < saldo_y) return 0;


    if (x.gols_marcados > y.gols_marcados) return 1;
    if (x.gols_marcados < y.gols_marcados) return 0;

    // 5. Empate total → escolha manual
    printf("Empate TOTAL entre %s e %s!\n", x.nome, y.nome);
    printf("Digite 1 para %s ficar na frente ou 2 para %s: ",
           x.nome, y.nome);

    int escolha;
    scanf("%d", &escolha);

    return (escolha == 1);
}
int compara_sem_confronto(selecao x, selecao y){

    if (x.pontos > y.pontos) return 1;
    if (x.pontos < y.pontos) return 0;


    int saldo_x = x.gols_marcados - x.gols_sofridos;
    int saldo_y = y.gols_marcados - y.gols_sofridos;

    if (saldo_x > saldo_y) return 1;
    if (saldo_x < saldo_y) return 0;


    if (x.gols_marcados > y.gols_marcados) return 1;
    if (x.gols_marcados < y.gols_marcados) return 0;

    // 5. Empate total → escolha manual
    printf("Empate TOTAL entre %s e %s!\n", x.nome, y.nome);
    printf("Digite 1 para %s ficar na frente ou 2 para %s: ",
           x.nome, y.nome);

    int escolha;
    scanf("%d", &escolha);

    return (escolha == 1);
}



grupo simula_grupo(grupo a){
    jogo rodada_1 = jogo_normal(&a.a,&a.b);
    jogo rodada_2 = jogo_normal(&a.c,&a.d);
    jogo rodada_3 = jogo_normal(&a.a,&a.c);
    jogo rodada_4 = jogo_normal(&a.b,&a.d);
    jogo rodada_5 = jogo_normal(&a.a,&a.d);
    jogo rodada_6 =jogo_normal(&a.c,&a.b);
    grupo copia = a;
    selecao temp;
    int comparados[6];
    comparados[0] = compara(a.a, a.b, rodada_1);
    comparados[1] = compara(a.c, a.d, rodada_2);
    comparados[2] = compara(a.a, a.c, rodada_3);
    comparados[3] = compara(a.b, a.d, rodada_4);
    comparados[4] = compara(a.a, a.d, rodada_5);
    comparados[5] = compara(a.b, a.c, rodada_6);
    if(a.a.pontos == a.b.pontos && a.a.pontos == a.c.pontos && a.a.pontos == a.d.pontos){
        comparados[0] = compara_sem_confronto(a.a, a.b);
        comparados[1] = compara_sem_confronto(a.c, a.d);
        comparados[2] = compara_sem_confronto(a.a, a.c);
        comparados[3] = compara_sem_confronto(a.b, a.d);
        comparados[4] = compara_sem_confronto(a.a, a.d);
        comparados[5] = compara_sem_confronto(a.b, a.c);
    }
    if(a.a.pontos == a.b.pontos && a.a.pontos == a.c.pontos){
        comparados[0] = compara_sem_confronto(a.a, a.b);
        comparados[2] = compara_sem_confronto(a.a, a.c);
        comparados[5] = compara_sem_confronto(a.b, a.c);
    }
    if(a.a.pontos == a.b.pontos && a.a.pontos == a.d.pontos){
        comparados[0] = compara_sem_confronto(a.a, a.b);
        comparados[4] = compara_sem_confronto(a.a, a.d);
        comparados[3] = compara_sem_confronto(a.b, a.d);
    }
    if(a.a.pontos == a.d.pontos && a.a.pontos == a.c.pontos){
        comparados[4] = compara_sem_confronto(a.a, a.d);
        comparados[2] = compara_sem_confronto(a.a, a.c);
        comparados[1] = compara_sem_confronto(a.c, a.d);
    }
    if(a.d.pontos == a.b.pontos && a.d.pontos == a.c.pontos){
        comparados[5] = compara_sem_confronto(a.b, a.c);
        comparados[3] = compara_sem_confronto(a.b, a.d);
        comparados[1] = compara_sem_confronto(a.c, a.d);
    }
    int trocado;
    int caso_final;
    if(comparados[0] == 1 && comparados[2] == 1 && comparados[4] == 1){
        //Primeiro é a seleção a
        trocado = 1;
    }
    if(comparados[0] == 0 && comparados[3] == 1 && comparados[5] == 1){
        //primeiro é a seleção b
        temp = a.a;
        a.a = a.b;
        a.b =temp;
        trocado = 2;
    }
    if(comparados[1] == 1 && comparados[2] == 0 && comparados[5] == 0){
        //primeiro é a seleção c
        temp = a.a;
        a.a = a.c;
        a.c =temp;
        trocado = 3;
    }
    if(comparados[1] == 0 && comparados[3] == 0 && comparados[4] == 0){
        //primeiro é a seleção d
        temp = a.a;
        a.a = a.d;
        a.d =temp;
        trocado = 4;
    }
    //Primeiros e últimos é mais fácil a implementação
    //
    if(comparados[0] != 1 && comparados[2] != 1 && comparados[4] != 1){
        //ultimo é a seleção a
        switch (trocado)
        {
        case 2:
            temp = a.d;
            a.d = a.b;
            a.b = temp;
            a.b = copia.c;
            a.c = copia.d;
            caso_final = 1;
            break;
        case 3:
            temp = a.d;
            a.d = a.c;
            a.c = temp;
            caso_final = 3;
            break;
        case 4:
            caso_final = 5;
            break;
        default:
            break;
        }
    }
    if(comparados[0] != 0 && comparados[3] != 1 && comparados[5] != 1){
        //ultimo é a seleção b
        temp = a.d;
        a.d = a.b;
        a.b = temp;
        switch (trocado)
        {
        case 1:
            caso_final = 1;
            a.b = copia.c;
            a.c = copia.d;
            break;
        case 3:
            caso_final = 4;
            a.b = copia.a;
            a.c = copia.d;
            break;
        case 4:
            caso_final = 2;
            break;
        default:
            break;
        }
    }
    if(comparados[1] != 1 && comparados[2] != 0 && comparados[5] != 0){
        //ultimo é a seleção c
        temp = a.d;
        a.d = a.c;
        a.c = temp;
        switch (trocado)
        {
        case 1: 
            caso_final = 3;
            break;
        case 2:
            caso_final = 4;
            break;
        case 4:
            caso_final = 0;
            a.b = copia.a;
            a.c = copia.b;
            break;
        default:
            break;
        }
    }
    if(comparados[1] != 0 && comparados[3] != 0 && comparados[4] != 0){
        //ultimo é a seleção d
        switch (trocado)
        {
        case 1:
            caso_final = 1;
            break;
        case 2:
            caso_final = 2;
            break;
        case 3:
            caso_final = 0;
            a.b = copia.a;
            a.c = copia.b;
            break;
        default:
            break;
        }
    }
    if(comparados[caso_final]==0){
        temp = a.c;
        a.c = a.b;
        a.b = temp;
    }
    return a;
}

terceiros_passados melhores_terceiros(selecao a, selecao b, selecao c, selecao d,
                                      selecao e, selecao f, selecao g, selecao h,
                                      selecao i, selecao j, selecao k, selecao l){

    selecao terceiros[12] = {a,b,c,d,e,f,g,h,i,j,k,l};

    // Ordenação por "compara_sem_confronto"
    for(int in = 0; in < 12; in++){
        for(int jo = in + 1; jo < 12; jo++){
            int compara = compara_sem_confronto(terceiros[in], terceiros[jo]);

            // Se o segundo é melhor, troca
            if(compara == 0){
                selecao tmp = terceiros[in];
                terceiros[in] = terceiros[jo];
                terceiros[jo] = tmp;
            }
        }
    }

    terceiros_passados resp;

    // Pega os 8 melhores após ordenar
    for(int x = 0; x < 8; x++){
        resp.classificadas[x] = terceiros[x];       // salva seleções
        resp.grupos[x] = toupper(terceiros[x].grupo);  // salva o grupo
    }

    return resp;
}
terceiros_passados ordena2(terceiros_passados x, char y[]){
    terceiros_passados copia = x;
    for(int in = 0; in < 8; in++){
        for(int jo = 0; jo < 8; jo++){
            if(x.grupos[in] == y[jo]){
                copia.classificadas[jo] = x.classificadas[in];
            }
        }
    }
    return copia;
}

terceiros_passados ordena(terceiros_passados x, char y[]){
    int contador = 0;
    for(int in = 0; in < 8; in++){
        for(int jo = 0; jo< 8; jo++){
        if(x.grupos[in] == y[jo]){
            contador ++;
        }
    }
    }
    if(contador == 8){
        return ordena2(x, y);
    }

        return x;


}
terceiros_passados ordena3(terceiros_passados x, char y[495][8]){
    for(int i = 0; i<495; i++ ){
        x = ordena(x,y[i]);
    }
    return x;
}
int main(){
    //selecao brasil = cria_brasil();
    //selecao marrocos = cria_marrocos();
    //selecao canada = cria_canada();
    selecao mexico = cria_mexico();
    selecao africa_do_sul = cria_africa_do_sul();
    selecao coreia = cria_coreia();
    selecao dinamarca = cria_dinamarca();
    selecao macedonia = cria_macedonia();
    selecao tcheca = cria_tcheca();
    selecao irlanda = cria_irlanda();

    //grupo b
    selecao canada = cria_canada();
    selecao italia = cria_Italia();
    selecao irlanda_do_norte = cria_Irlanda_Norte();
    selecao pais_de_gales = cria_Gales();
    selecao bosnia = cria_Bosnia();
    selecao Qatar = cria_Qatar();
    selecao suica = cria_Suica();

    //grupo c
    selecao brasil = cria_brasil();
    selecao marrocos = cria_marrocos();
    selecao haiti = cria_Haiti();
    selecao escocia = cria_Escocia();

    //grupo d
    selecao USA = cria_USA();
    selecao paraguai = cria_Paraguai();
    selecao australia = cria_Australia();
    selecao turquia = cria_Turquia();
    selecao romenia = cria_Romenia();
    selecao eslovaquia = cria_Eslovaquia();
    selecao kosovo = cria_Kosovo();

    //grupo e
    selecao alemanha = cria_Alemanha();
    selecao curacao = cria_Curacao();
    selecao costa_do_marfim = cria_Costa_do_Marfim();
    selecao equador = cria_Equador();

    //grupo f
    selecao holanda = cria_Holanda();
    selecao japao = cria_Japao();
    selecao ucrania = cria_Ucrania();
    selecao suecia = cria_Suecia();
    selecao polonia = cria_Polonia();
    selecao albania = cria_Albania();
    selecao tunisia = cria_Tunisia();

    //grupo g
    selecao belgica = cria_Belgica();
    selecao egito = cria_Egito();
    selecao iran = cria_Iran();
    selecao nova_zelandia = cria_Nova_Zelandia();

    //grupo h
    selecao espanha = cria_Espanha();
    selecao cab_verde = cria_Cabo_Verde();
    selecao arabia_saudita = cria_Arabia_Saudita();
    selecao uruguai = cria_Uruguai();

    //grupo i
    selecao franca = cria_Franca();
    selecao senegal = cria_Senegal();
    selecao iraque = cria_Iraque();
    selecao bolivia = cria_Bolivia();
    selecao suriname = cria_Suriname();
    selecao noruega = cria_Noruega();

    //grupo j
    selecao argentina = cria_Argentina();
    selecao argelia = cria_Argelia();
    selecao austria = cria_Austria();
    selecao jordania = cria_Jordania();

    //grupo k
    selecao portugal = cria_Portugal();
    selecao congo = cria_Congo();
    selecao jamaica = cria_Jamaica();
    selecao nova_caledonia = cria_caledonia();
    selecao uzbequistao = cria_Uzbequistao();
    selecao colombia = cria_Colombia();

    //grupo l 
    selecao inglaterra = cria_Inglaterra();
    selecao croacia = cria_Croacia();
    selecao gana = cria_Gana();
    selecao panama = cria_Panama();

    repescagem_euro po_4 = euro_rep(dinamarca,macedonia,tcheca,irlanda);
    repescagem_euro po_3 = euro_rep(turquia,romenia,eslovaquia,kosovo);
    repescagem_euro po_2 = euro_rep(ucrania,suecia,polonia,albania);
    repescagem_euro po_1 = euro_rep(italia,irlanda_do_norte,pais_de_gales,bosnia);
    repescagem_mundo rep_b = mundo_rep(congo, jamaica, nova_caledonia);
    repescagem_mundo rep_a = mundo_rep(iraque, bolivia,suriname);
    

    grupo gru_a = cria_grupo(mexico, africa_do_sul, coreia, rep_euro_jogos(po_4));
    grupo gru_b = cria_grupo(canada, rep_euro_jogos(po_1),Qatar, suica);
    grupo gru_c = cria_grupo(brasil, marrocos,haiti, escocia);
    grupo gru_d = cria_grupo(USA,paraguai,australia, rep_euro_jogos(po_3));
    grupo gru_e = cria_grupo(alemanha,curacao,costa_do_marfim,equador);
    grupo gru_f = cria_grupo(holanda,japao,rep_euro_jogos(po_2),tunisia);
    grupo gru_g = cria_grupo(belgica,egito,iran,nova_zelandia);
    grupo gru_h = cria_grupo(espanha,cab_verde,arabia_saudita,uruguai);
    grupo gru_i = cria_grupo(franca,senegal,rep_mundo_jogos(rep_a),noruega);
    grupo gru_j = cria_grupo(argentina,argelia,austria,jordania);
    grupo gru_k = cria_grupo(portugal, rep_mundo_jogos(rep_b),uzbequistao,colombia);
    grupo gru_l = cria_grupo(inglaterra,croacia,gana,panama);


    printf("\nGrupo A: \n%s\n%s\n%s\n%s",gru_a.a.nome,gru_a.b.nome,gru_a.c.nome,gru_a.d.nome);
    gru_a = simula_grupo(gru_a);
    printf("\nGrupo A: \n%s %d\n%s %d\n%s %d\n%s %d",gru_a.a.nome,gru_a.a.pontos,gru_a.b.nome,gru_a.b.pontos,gru_a.c.nome,gru_a.c.pontos,gru_a.d.nome,gru_a.d.pontos);


    printf("\nGrupo B: \n%s\n%s\n%s\n%s",gru_b.a.nome,gru_b.b.nome,gru_b.c.nome,gru_b.d.nome);
    gru_b = simula_grupo(gru_b);
    printf("\nGrupo B: \n%s %d\n%s %d\n%s %d\n%s %d",gru_b.a.nome,gru_b.a.pontos,gru_b.b.nome,gru_b.b.pontos,gru_b.c.nome,gru_b.c.pontos,gru_b.d.nome,gru_b.d.pontos);
    printf("\nGrupo C: \n%s\n%s\n%s\n%s",
    gru_c.a.nome, gru_c.b.nome, gru_c.c.nome, gru_c.d.nome);

    gru_c = simula_grupo(gru_c);

    printf("\nGrupo C: \n%s %d\n%s %d\n%s %d\n%s %d",
        gru_c.a.nome, gru_c.a.pontos,
        gru_c.b.nome, gru_c.b.pontos,
        gru_c.c.nome, gru_c.c.pontos,
        gru_c.d.nome, gru_c.d.pontos);

    // GRUPO D
    printf("\nGrupo D: \n%s\n%s\n%s\n%s",
        gru_d.a.nome, gru_d.b.nome, gru_d.c.nome, gru_d.d.nome);

    gru_d = simula_grupo(gru_d);

    printf("\nGrupo D: \n%s %d\n%s %d\n%s %d\n%s %d",
        gru_d.a.nome, gru_d.a.pontos,
        gru_d.b.nome, gru_d.b.pontos,
        gru_d.c.nome, gru_d.c.pontos,
        gru_d.d.nome, gru_d.d.pontos);

    // GRUPO E
    printf("\nGrupo E: \n%s\n%s\n%s\n%s",
        gru_e.a.nome, gru_e.b.nome, gru_e.c.nome, gru_e.d.nome);

    gru_e = simula_grupo(gru_e);

    printf("\nGrupo E: \n%s %d\n%s %d\n%s %d\n%s %d",
        gru_e.a.nome, gru_e.a.pontos,
        gru_e.b.nome, gru_e.b.pontos,
        gru_e.c.nome, gru_e.c.pontos,
        gru_e.d.nome, gru_e.d.pontos);

    // GRUPO F
    printf("\nGrupo F: \n%s\n%s\n%s\n%s",
        gru_f.a.nome, gru_f.b.nome, gru_f.c.nome, gru_f.d.nome);

    gru_f = simula_grupo(gru_f);

    printf("\nGrupo F: \n%s %d\n%s %d\n%s %d\n%s %d",
        gru_f.a.nome, gru_f.a.pontos,
        gru_f.b.nome, gru_f.b.pontos,
        gru_f.c.nome, gru_f.c.pontos,
        gru_f.d.nome, gru_f.d.pontos);

    // GRUPO G
    printf("\nGrupo G: \n%s\n%s\n%s\n%s",
        gru_g.a.nome, gru_g.b.nome, gru_g.c.nome, gru_g.d.nome);

    gru_g = simula_grupo(gru_g);

    printf("\nGrupo G: \n%s %d\n%s %d\n%s %d\n%s %d",
        gru_g.a.nome, gru_g.a.pontos,
        gru_g.b.nome, gru_g.b.pontos,
        gru_g.c.nome, gru_g.c.pontos,
        gru_g.d.nome, gru_g.d.pontos);

    // GRUPO H
    printf("\nGrupo H: \n%s\n%s\n%s\n%s",
        gru_h.a.nome, gru_h.b.nome, gru_h.c.nome, gru_h.d.nome);

    gru_h = simula_grupo(gru_h);

    printf("\nGrupo H: \n%s %d\n%s %d\n%s %d\n%s %d",
        gru_h.a.nome, gru_h.a.pontos,
        gru_h.b.nome, gru_h.b.pontos,
        gru_h.c.nome, gru_h.c.pontos,
        gru_h.d.nome, gru_h.d.pontos);

    // GRUPO I
    printf("\nGrupo I: \n%s\n%s\n%s\n%s",
        gru_i.a.nome, gru_i.b.nome, gru_i.c.nome, gru_i.d.nome);

    gru_i = simula_grupo(gru_i);

    printf("\nGrupo I: \n%s %d\n%s %d\n%s %d\n%s %d",
        gru_i.a.nome, gru_i.a.pontos,
        gru_i.b.nome, gru_i.b.pontos,
        gru_i.c.nome, gru_i.c.pontos,
        gru_i.d.nome, gru_i.d.pontos);

    // GRUPO J
    printf("\nGrupo J: \n%s\n%s\n%s\n%s",
        gru_j.a.nome, gru_j.b.nome, gru_j.c.nome, gru_j.d.nome);

    gru_j = simula_grupo(gru_j);

    printf("\nGrupo J: \n%s %d\n%s %d\n%s %d\n%s %d",
        gru_j.a.nome, gru_j.a.pontos,
        gru_j.b.nome, gru_j.b.pontos,
        gru_j.c.nome, gru_j.c.pontos,
        gru_j.d.nome, gru_j.d.pontos);

    // GRUPO K
    printf("\nGrupo K: \n%s\n%s\n%s\n%s",
        gru_k.a.nome, gru_k.b.nome, gru_k.c.nome, gru_k.d.nome);

    gru_k = simula_grupo(gru_k);

    printf("\nGrupo K: \n%s %d\n%s %d\n%s %d\n%s %d",
        gru_k.a.nome, gru_k.a.pontos,
        gru_k.b.nome, gru_k.b.pontos,
        gru_k.c.nome, gru_k.c.pontos,
        gru_k.d.nome, gru_k.d.pontos);
    // GRUPO L
    printf("\nGrupo L: \n%s\n%s\n%s\n%s",
        gru_l.a.nome, gru_l.b.nome, gru_l.c.nome, gru_l.d.nome);

    gru_l = simula_grupo(gru_l);

    printf("\nGrupo K: \n%s %d\n%s %d\n%s %d\n%s %d",
        gru_l.a.nome, gru_l.a.pontos,
        gru_l.b.nome, gru_l.b.pontos,
        gru_l.c.nome, gru_l.c.pontos,
        gru_l.d.nome, gru_l.d.pontos);
    terceiros_passados passaram =melhores_terceiros(
        gru_a.c,gru_b.c,gru_c.c,
        gru_d.c,gru_e.c,gru_f.c,
        gru_g.c,gru_h.c,gru_i.c,
        gru_j.c,gru_k.c,gru_l.c);
    passaram = ordena3(passaram, tabela);
    
    selecao semi1 = mata_mata(mata_mata(mata_mata(gru_e.a,passaram.classificadas[3]),mata_mata(gru_i.a,passaram.classificadas[5])),mata_mata(mata_mata(gru_a.b,gru_b.b),mata_mata(gru_f.a,gru_c.b)));
    selecao semi2 = mata_mata(mata_mata(mata_mata(gru_k.b,gru_l.b),mata_mata(gru_h.a,gru_j.b)),mata_mata(mata_mata(gru_d.a,passaram.classificadas[2]),mata_mata(gru_g.a,passaram.classificadas[4])));
    selecao semi3 = mata_mata(mata_mata(mata_mata(gru_c.a,gru_f.b),mata_mata(gru_e.b,gru_i.b)),mata_mata(mata_mata(gru_a.a,passaram.classificadas[0]),mata_mata(gru_l.a,passaram.classificadas[7])));
    selecao semi4 = mata_mata(mata_mata(mata_mata(gru_j.a,gru_h.b),mata_mata(gru_d.b,gru_g.b)),mata_mata(mata_mata(gru_b.a,passaram.classificadas[1]),mata_mata(gru_k.a,passaram.classificadas[6])));
    selecao final1 = mata_mata(semi1,semi2);
    selecao final2 = mata_mata(semi3,semi4);
    printf("\n-----Final------\n");
    selecao campea = mata_mata(final1,final2);
    printf("%s",campea.nome);
}
