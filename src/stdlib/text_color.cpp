/*
    Copyright 2014 Matthew Fosdick

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

     http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/
#include <utf8.h>
#include <stdlib.h>
#include <stdint.h>
namespace std {
	namespace TC {
		char RED[6];
		char BLUE[6];
		char GREEN[6];
		char YELLOW[6];
		char MAGENTA[6];
		char CYAN[6];
		char WHITE[6];
		char BLACK[6];

		char DRED[6];
		char DBLUE[6];
		char DGREEN[6];
		char DYELLOW[6];
		char DMAGENTA[6];
		char DCYAN[6];
		char DGRAY[6];
		char LGRAY[6];
		char BACKCOLOR[6];

		char *init_colors() {
			static char b[6]= {0};
			encode_five(0x80000|(0xF<<8),RED);
			encode_five(0x80000|(0xF<<4),GREEN);
			encode_five(0x80000|0xF,BLUE);
			encode_five(0x80000|(0xF<<8)|(0xF<<4),YELLOW);
			encode_five(0x80000|(0xF<<8)|0xF,MAGENTA);
			encode_five(0x80000|(0xF<<4)|0xF,CYAN);
			encode_five(0x80000|(0xF<<8)|(0xF<<4)|0xF,WHITE);
			encode_five(0x80000,BLACK);

			encode_five(0x80000|(0x7<<8),DRED);
			encode_five(0x80000|(0x7<<4),DGREEN);
			encode_five(0x80000|0x7,DBLUE);
			encode_five(0x80000|(0x7<<8)|(0x7<<4),DYELLOW);
			encode_five(0x80000|(0x7<<8)|0x7,DMAGENTA);
			encode_five(0x80000|(0x7<<4)|0x7,DCYAN);
			encode_five(0x80000|(0x5<<8)|(0x5<<4)|0x5,DGRAY);
			encode_five(0x80000|(0xA<<8)|(0xA<<4)|0xA,LGRAY);
			encode_five(0x80000|(0xA<<8)|(0xA<<4)|0xA,LGRAY);
			encode_five(0x81000,BACKCOLOR);
			return b;
		}


		//lazy trick to make an init function implicit
		static char *buf=init_colors();
		char *getColor(uint8_t red, uint8_t green, uint8_t blue) {
			encode_five(0x80000|((red&0xF)<<8)|((green&0xF)<<4)|(blue&0xF),buf);
			return buf;
		}
	}
}