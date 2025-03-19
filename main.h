/* 
 * File:   main.h
 * Author: GOUTHAM M
 *
 * Created on 6 January, 2025, 11:48 AM
 */

#ifndef MAIN_H
#define	MAIN_H

#include <xc.h>
#include "clcd.h"
#include "adc.h"
#include "mkp.h"
#include "ext_eeprom.h"
#include "uart.h"
#include "ds1307.h"
#include "i2c.h"

void dashboard(void);
void menu(void) ;
void view(void);
void clear_log();
void download_log();
void get_time(void);
void display_time(void);
void set_time(void);

enum mode{e_view,e_download,e_clear,e_set_time,e_Dashboard,e_menu};

#endif	/* MAIN_H */

