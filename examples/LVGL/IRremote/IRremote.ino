#pragma mark - Depend Arduino-IRremote library
/*
cd ~/Arduino/libraries
git clone https://github.com/lewisxhe/Arduino-IRremote.git
*/

// Only supports TWATCH-2020

#include "config.h"
#include <IRremote.h>       //Depend  https://github.com/lewisxhe/Arduino-IRremote.git

TTGOClass *ttgo;

//! Use Arduino-IRremote/examples/IRrecvDumpV2 to generate RAW
//! Use Arduino-IRremote/examples/IRrecvDumpV2 to generate RAW
//! Use Arduino-IRremote/examples/IRrecvDumpV2 to generate RAW
const unsigned int  airOFF[211] = {9050, 4400, 600, 1550, 650, 1550, 600, 450, 600, 400, 650, 400, 650, 400, 650, 1550, 600, 1550, 650, 1550, 600, 1550, 600, 1550, 650, 400, 650, 1550, 600, 450, 600, 450, 600, 1550, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 400, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 600, 450, 600, 1550, 650, 400, 650, 1550, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 400, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 600, 450, 600, 1550, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 400, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 1550, 600, 450, 600, 1550, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 650, 1550, 600, 1550, 600, 1550, 650, 1550, 600, 1550, 650, 400, 650, 400, 650, 400, 700}; // NEC C3E90000
const unsigned int  airLevel30[211] = {9000, 4400, 600, 1550, 600, 1550, 650, 400, 650, 400, 650, 400, 650, 400, 650, 1550, 600, 1550, 600, 1550, 650, 1550, 600, 1550, 650, 400, 650, 1550, 600, 1550, 650, 400, 600, 1600, 600, 400, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 550, 450, 650, 400, 650, 1550, 600, 450, 600, 1550, 650, 400, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 400, 650, 400, 650, 1550, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 400, 650, 400, 650, 400, 600, 450, 650, 400, 650, 400, 650, 400, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 1550, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 600, 450, 600, 400, 650, 400, 700, 350, 700, 350, 650, 400, 650, 400, 700, 350, 650, 400, 650, 400, 650, 1500, 650, 400, 650, 1550, 650, 1500, 650, 400, 650, 1550, 650, 400, 650}; // NEC C3ED0000
const unsigned int  airLevel29[211] = {9000, 4400, 650, 1550, 600, 1550, 650, 400, 650, 400, 600, 450, 600, 450, 600, 1550, 650, 1550, 600, 1550, 650, 1550, 600, 1550, 600, 1600, 600, 400, 650, 1550, 600, 450, 600, 1550, 650, 400, 650, 400, 650, 400, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 400, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 650, 1550, 600, 450, 600, 1550, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 400, 650, 400, 650, 400, 650, 400, 650, 400, 650, 1550, 600, 450, 600, 450, 600, 450, 600, 450, 600, 400, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 400, 650, 400, 650, 1550, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 400, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 1550, 650, 400, 650, 400, 650, 1550, 600, 450, 600, 1550, 600, 450, 600}; // NEC C3F50000
const unsigned int  airLevel28[211] = {9050, 4400, 650, 1550, 600, 1550, 600, 450, 600, 450, 600, 450, 600, 450, 600, 1550, 650, 1550, 600, 1550, 600, 1600, 600, 1550, 600, 450, 600, 450, 600, 1550, 650, 400, 650, 1550, 600, 450, 600, 450, 600, 400, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 1550, 600, 450, 600, 1550, 650, 400, 650, 400, 650, 400, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 1550, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 400, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 1550, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 400, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 600, 1600, 600, 450, 600, 1550, 600, 450, 600, 450, 600, 1550, 650, 400, 650}; // NEC C3E50000
const unsigned int  airLevel27[211] = {9000, 4450, 600, 1550, 600, 1550, 650, 400, 650, 400, 650, 400, 650, 400, 650, 1550, 600, 1550, 600, 1600, 600, 1550, 600, 1550, 650, 1550, 600, 1550, 650, 400, 650, 400, 650, 1550, 600, 450, 600, 400, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 400, 650, 1550, 600, 450, 600, 1550, 650, 400, 650, 400, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 1550, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 400, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 1550, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 400, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 600, 450, 600, 1600, 600, 400, 650, 400, 650, 400, 650, 400, 650, 1550, 600, 450, 600}; // NEC C3F90000
const unsigned int  airLevel26[211] = {9000, 4450, 600, 1550, 600, 1600, 600, 450, 600, 400, 650, 400, 650, 400, 650, 1550, 600, 1550, 650, 1550, 600, 1550, 600, 1550, 650, 400, 650, 1550, 600, 450, 600, 450, 600, 1550, 650, 400, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 400, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 600, 450, 600, 450, 600, 1550, 650, 400, 650, 1550, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 400, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 600, 1600, 600, 450, 600, 400, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 400, 650, 400, 650, 400, 650, 400, 600, 1600, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 400, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 1550, 650, 400, 650, 1550, 600, 1550, 600, 1550, 650, 400, 650, 400, 650}; // NEC C3E90000
const unsigned int  airLevel25[211] = {9000, 4400, 650, 1550, 600, 1550, 650, 400, 650, 400, 650, 400, 600, 450, 600, 1600, 600, 1550, 600, 1550, 650, 1550, 600, 1550, 650, 1550, 600, 450, 600, 450, 600, 400, 650, 1550, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 400, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 1550, 650, 400, 650, 1550, 600, 400, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 600, 450, 600, 450, 600, 450, 600, 450, 600, 1550, 650, 400, 650, 400, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 400, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 600, 450, 600, 450, 600, 1550, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 400, 650, 400, 650, 1550, 600, 450, 600, 450, 600, 1550, 650, 1550, 600, 450, 600, 400, 650}; // NEC C3F10000
const unsigned int  airLevel24[211] = {8950, 4400, 650, 1550, 600, 1550, 650, 400, 650, 400, 650, 400, 650, 400, 650, 1550, 600, 1550, 600, 1550, 650, 1550, 600, 1550, 650, 400, 650, 400, 650, 400, 600, 450, 600, 1550, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 400, 650, 400, 650, 400, 650, 1550, 600, 450, 600, 1550, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 400, 650, 1550, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 400, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 1550, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 400, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 600, 450, 600, 450, 600, 450, 600, 1550, 650, 400, 650, 1550, 600, 450, 600, 1550, 650, 400, 600, 450, 600}; // NEC C3E10000
const unsigned int  airLevel23[211] = {8950, 4450, 600, 1550, 650, 1550, 600, 450, 600, 450, 600, 450, 600, 450, 600, 1550, 600, 1550, 650, 1550, 600, 1550, 650, 1550, 600, 1550, 600, 1600, 600, 1550, 600, 1550, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 400, 650, 400, 650, 400, 650, 400, 600, 450, 650, 400, 650, 1550, 600, 450, 600, 1550, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 400, 650, 400, 650, 400, 650, 400, 650, 400, 650, 1550, 600, 450, 600, 450, 600, 450, 600, 400, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 400, 650, 400, 650, 1550, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 400, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 1550, 650, 400, 650, 400, 600, 450, 600, 1600, 600, 400, 650, 400, 650}; // NEC C3FE0000
const unsigned int  airLevel22[211] = {9000, 4450, 600, 1550, 600, 1550, 650, 400, 650, 400, 650, 400, 650, 400, 600, 1600, 600, 1550, 600, 1550, 650, 1550, 600, 1550, 650, 400, 650, 1550, 600, 1550, 600, 1600, 600, 450, 600, 400, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 400, 650, 400, 650, 400, 650, 400, 650, 1550, 600, 450, 600, 1550, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 400, 650, 400, 650, 400, 650, 1550, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 400, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 1550, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 400, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 600, 450, 600, 450, 600, 450, 600, 1550, 650, 400, 650, 1550, 600, 1550, 650, 400, 600, 450, 600, 450, 600}; // NEC C3EE0000
const unsigned int  airLevel21[211] = {8900, 4400, 650, 1550, 600, 1550, 650, 400, 650, 400, 650, 400, 600, 450, 600, 1550, 650, 1550, 600, 1550, 650, 1550, 600, 1550, 650, 1550, 600, 450, 600, 1550, 600, 1550, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 400, 650, 400, 650, 400, 600, 450, 650, 1550, 600, 450, 600, 1550, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 400, 650, 400, 650, 400, 650, 1550, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 400, 650, 400, 650, 400, 650, 400, 650, 400, 600, 450, 650, 400, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 1550, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 550, 500, 600, 400, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 600, 450, 600, 450, 600, 450, 600, 450, 600, 1550, 650, 400, 650, 400, 650, 1550, 650, 400, 650, 400, 600, 450, 600}; // NEC C3F60000
const unsigned int  airLevel20[211] = {9050, 4400, 650, 1550, 600, 1550, 650, 400, 600, 450, 600, 450, 600, 450, 600, 1550, 650, 1550, 600, 1550, 650, 1550, 600, 1550, 600, 450, 600, 450, 600, 1550, 650, 1550, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 400, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 1550, 600, 450, 600, 1550, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 1550, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 400, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 600, 450, 600, 450, 600, 450, 600, 450, 600, 1550, 650, 400, 650, 400, 650, 400, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 400, 650, 400, 650, 400, 650, 400, 650, 1550, 600, 450, 600, 1550, 600, 450, 600, 450, 600, 450, 600, 450, 600}; // NEC C3E60000
const unsigned int  airLevel19[211] = {9050, 4400, 600, 1600, 600, 1550, 600, 450, 600, 450, 600, 450, 600, 450, 600, 1550, 650, 1550, 600, 1550, 600, 1550, 650, 1550, 600, 1550, 650, 1550, 600, 450, 600, 1550, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 400, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 600, 450, 600, 450, 600, 450, 600, 1550, 650, 400, 650, 1550, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 400, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 600, 450, 600, 1550, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 400, 650, 400, 650, 400, 650, 400, 650, 400, 650, 1550, 600, 450, 600, 450, 600, 450, 600, 400, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 1550, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600}; // NEC C3FA0000
const unsigned int  airLevel18[211] = {9000, 4450, 600, 1550, 600, 1550, 650, 400, 650, 400, 650, 400, 650, 400, 600, 1600, 600, 1550, 600, 1550, 650, 1550, 600, 1550, 650, 400, 650, 1550, 600, 450, 600, 1550, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 400, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 1550, 650, 400, 650, 1550, 600, 450, 600, 450, 600, 400, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 600, 450, 600, 450, 600, 450, 600, 1550, 650, 400, 650, 400, 650, 400, 650, 400, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 400, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 600, 450, 600, 1600, 600, 450, 600, 400, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 400, 650, 1550, 600, 450, 600, 1550, 650, 1550, 600, 1550, 650, 1550, 600, 1550, 600}; // NEC C3EA0000
const unsigned int  airLevel17[211] = {9000, 4400, 650, 1550, 600, 1550, 650, 400, 650, 400, 650, 400, 600, 450, 600, 1550, 650, 1550, 600, 1550, 650, 1550, 600, 1550, 650, 1550, 600, 450, 600, 450, 600, 1550, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 400, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 1550, 650, 400, 600, 1600, 600, 400, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 1550, 650, 400, 650, 400, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 400, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 600, 450, 600, 450, 600, 1550, 650, 400, 650, 400, 650, 400, 650, 400, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 400, 650, 400, 650, 400, 650, 1550, 600, 450, 600, 450, 600, 1550, 600, 1550, 650, 1550, 600, 1550, 650}; // NEC C3F20000
const unsigned int  airLevel16[211] = {9000, 4450, 600, 1550, 650, 1550, 600, 450, 600, 450, 600, 450, 600, 450, 600, 1550, 600, 1550, 650, 1550, 600, 1550, 650, 1550, 600, 450, 600, 450, 600, 450, 600, 1550, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 400, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 1550, 650, 400, 600, 1600, 600, 400, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 1550, 650, 400, 650, 400, 650, 400, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 400, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 600, 450, 600, 450, 600, 1550, 650, 400, 650, 400, 650, 400, 650, 400, 650, 400, 600, 450, 600, 450, 600, 450, 600, 450, 600, 450, 600, 1550, 650, 400, 650, 400, 650, 400, 650, 400, 600, 450, 600, 450, 600, 450, 600, 1550, 650, 1550, 600, 450, 600, 1550, 600, 450, 600, 1550, 650, 1550, 600, 1550, 650}; // NEC C3E20000

const unsigned int *airArray[] = {
    airLevel16,
    airLevel17,
    airLevel18,
    airLevel19,
    airLevel20,
    airLevel21,
    airLevel22,
    airLevel23,
    airLevel24,
    airLevel25,
    airLevel26,
    airLevel27,
    airLevel28,
    airLevel29,
    airLevel30
};

LV_FONT_DECLARE(BGPNG);
LV_FONT_DECLARE(Number_128);
LV_FONT_DECLARE(Add1PNG);
LV_FONT_DECLARE(Add2PNG);
LV_FONT_DECLARE(Less1PNG);
LV_FONT_DECLARE(Less2PNG);

IRsend irsend(TWATCH_2020_IR_PIN);

void ir_air_off()
{
    irsend.sendRaw(airOFF, 211, 38);
}

void ir_send_to_air(int level)
{
    irsend.sendRaw(airArray[level - sizeof(airArray) / sizeof(airArray[0]) - 1], 211, 38);
}

static lv_obj_t *text, *gContainer, *imgbtn1, *imgbtn2;
static int level = 24;


void click_event(lv_obj_t *obj, lv_event_t event)
{
    if (event == LV_EVENT_CLICKED) {
        if (obj == imgbtn1) {
            level = level + 1 > 30 ? 30 : level + 1;
        } else if (obj == imgbtn2) {
            level = level - 1 < 16 ? 16 : level - 1;
        }
        lv_label_set_text_fmt(text, "%d", level);
        ir_send_to_air(level);
    }
}

void setup()
{
    ttgo = TTGOClass::getWatch();
    ttgo->begin();
    ttgo->openBL();
    ttgo->lvgl_begin();

    irsend.enableIROut(38);

    static lv_style_t style1;
    lv_style_init(&style1);
    lv_style_set_text_color(&style1, LV_STATE_DEFAULT, LV_COLOR_WHITE);
    lv_style_set_text_font(&style1, LV_STATE_DEFAULT, &Number_128);

    static lv_style_t cont_style;
    lv_style_init(&cont_style);
    lv_style_set_border_width(&cont_style, LV_OBJ_PART_MAIN, 0);

    gContainer = lv_cont_create(lv_scr_act(), NULL);
    lv_obj_set_size(gContainer,  LV_HOR_RES, LV_VER_RES);
    lv_obj_add_style(gContainer, LV_OBJ_PART_MAIN, &cont_style);

    lv_obj_t *wp = lv_img_create(gContainer, NULL);
    lv_img_set_src(wp, &BGPNG);
    lv_obj_set_size(wp, LV_HOR_RES, LV_VER_RES);

    text = lv_label_create(gContainer, NULL);
    lv_label_set_text(text, "24");
    lv_obj_add_style(text, LV_OBJ_PART_MAIN, &style1);
    lv_obj_align(text, gContainer, LV_ALIGN_IN_TOP_MID, 0, 20);

    imgbtn1 = lv_imgbtn_create(gContainer, NULL);
    lv_imgbtn_set_src(imgbtn1, LV_BTN_STATE_ACTIVE, &Add2PNG);
    lv_imgbtn_set_src(imgbtn1, LV_BTN_STATE_RELEASED, &Add1PNG);
    lv_imgbtn_set_src(imgbtn1, LV_BTN_STATE_PRESSED, &Add2PNG);
    lv_imgbtn_set_src(imgbtn1, LV_BTN_STATE_CHECKED_RELEASED, &Add2PNG);
    lv_imgbtn_set_src(imgbtn1, LV_BTN_STATE_CHECKED_PRESSED, &Add1PNG);

    lv_obj_align(imgbtn1, NULL, LV_ALIGN_IN_RIGHT_MID, -30, 45);
    lv_obj_set_event_cb(imgbtn1, click_event);

    imgbtn2 = lv_imgbtn_create(gContainer, NULL);
    lv_imgbtn_set_src(imgbtn2, LV_BTN_STATE_ACTIVE, &Less2PNG);
    lv_imgbtn_set_src(imgbtn2, LV_BTN_STATE_RELEASED, &Less1PNG);
    lv_imgbtn_set_src(imgbtn2, LV_BTN_STATE_PRESSED, &Less2PNG);
    lv_imgbtn_set_src(imgbtn2, LV_BTN_STATE_CHECKED_RELEASED, &Less2PNG);
    lv_imgbtn_set_src(imgbtn2, LV_BTN_STATE_CHECKED_PRESSED, &Less1PNG);

    lv_obj_align(imgbtn2, NULL, LV_ALIGN_IN_LEFT_MID, 30, 45);
    lv_obj_set_event_cb(imgbtn2, click_event);
}

void loop()
{
    lv_task_handler();
    delay(5);
}



