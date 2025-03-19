/*
 * File:   menu.c
 * Author: GOUTHAM M
 *
 * Created on 8 January, 2025, 8:13 AM
 */


#include "main.h"

char count=0,s_flag=0;
extern unsigned char state;
extern char key;
void menu(void) 
{
    char ME[4][17]={"View_log    ","Download_log","Clear_log   ","Set_time    "};
    
    if(key == ALL_RELEASED)
    {
        clcd_print(ME[count],LINE1(3));
        clcd_print(ME[count+1],LINE2(3));
    }
    if(s_flag == 0)
    {
        clcd_print("*",LINE1(0));
        clcd_print(" ",LINE2(0));
    }
    else
    {
        clcd_print(" ",LINE1(0));
        clcd_print("*",LINE2(0));
    }
    if(key == SW2 )
    {
        if(s_flag == 0)
        {
            s_flag=1;
        }
        else if(count<2)
        {
            count++;
        }
    }
    else if(key == SW1 )
    {
       if(s_flag == 1)
        {
            s_flag=0;
        }
        else if(count>=1)
        {
            count--;
        }
    }
    
    if(key == SW4){
        if(count+s_flag == 0) state = e_view;
        else if(count+s_flag == 1) state = e_download;
        else if(count+s_flag == 2) state = e_clear;
        else if(count+s_flag == 3) state = e_set_time;
    }
    else if(key == SW5)
    {
        CLEAR_DISP_SCREEN;
        state = e_Dashboard;
    }
}
