#ifndef Ext_eeprom
#define Ext_eeprpm

#define SLAVE_READ1		0xA1
#define SLAVE_WRITE1		0xA0

void write_ext_eeprom(unsigned char address1,  unsigned char data);
unsigned char read_ext_eeprom(unsigned char address1);

#endif