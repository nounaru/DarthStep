/*
    License.cpp - DarthStep license UIView.
    Created by Daniel Esteban, January 26, 2013.
*/

#include "License.h"

prog_char licenseText1[] PROGMEM = "DarthStep | (C) 2013 Daniel Esteban";
prog_char licenseText2[] PROGMEM = "This program is free software: you can";
prog_char licenseText3[] PROGMEM = "redistribute it and/or modify it under";
prog_char licenseText4[] PROGMEM = "the terms of the GNU General Public";
prog_char licenseText5[] PROGMEM = "License as published by the Free";
prog_char licenseText6[] PROGMEM = "Software Foundation, either version 3";
prog_char licenseText7[] PROGMEM = "of the License, or (at your option)";
prog_char licenseText8[] PROGMEM = "any later version.";
prog_char licenseText9[] PROGMEM = "This program is distributed in the";
prog_char licenseText10[] PROGMEM = "hope that it will be useful, but";
prog_char licenseText11[] PROGMEM = "WITHOUT ANY WARRANTY; without even the";
prog_char licenseText12[] PROGMEM = "implied warranty of MERCHANTABILITY or";
prog_char licenseText13[] PROGMEM = "FITNESS FOR A PARTICULAR PURPOSE. See";
prog_char licenseText14[] PROGMEM = "the GNU General Public License for";
prog_char licenseText15[] PROGMEM = "more details.";

PROGMEM const char * licenseTexts[] = {
	licenseText1,
	licenseText2,
	licenseText3,
	licenseText4,
	licenseText5,
	licenseText6,
	licenseText7,
	licenseText8,
	licenseText9,
	licenseText10,
	licenseText11,
	licenseText12,
	licenseText13,
	licenseText14,
	licenseText15
};

License::License() {
	availableOrientations[PORTRAIT] = 0;
}

void License::render(UTFT tft) {
	tft.clrScr();
	tft.setFont(SmallFont);

	char buffer[64];
	byte offset = 0;
	for(byte x=0; x<15; x++) {
		strcpy_P(buffer, (char *) pgm_read_word(&(licenseTexts[x])));
		if(x == 0) {
			tft.setColor(255, 255, 255);
			tft.fillRect(0, 0, tft.getDisplayXSize() - 1, 12);
			tft.setBackColor(255, 255, 255);
			tft.setColor(0, 0, 0);
			tft.print(buffer, 10, 0);

			tft.setBackColor(0, 0, 0);
			tft.setColor(255, 255, 255);
			continue;
		}
		x == 8 && (offset += 15);
		tft.print(buffer, 10, (x * 15) + offset);
	}
}
