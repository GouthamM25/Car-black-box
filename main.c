/*
 * File:   main.c
 * Author: GOUTHAM M
 *
 * Created on 6 January, 2025, 11:48 AM
 */
#include "main.h"
char time[9] = "00:00:00";
void init_config()//configuration
{
    init_clcd();
    init_adc();
    init_mkp();
    init_uart();
    init_i2c();
    init_ds1307();
}
char i,s_f,state = e_Dashboard,key;
void menu()
{
    char menu[][17]={"View log        ","Download log    ","Clear log       ","Set time        "};
    if(i<3)
    {
      clcd_print(menu[i],LINE1(2));
      clcd_print(menu[i+1],LINE2(2));  
    }
     
    if(s_f == 0)
    {
        clcd_print("*",LINE1(0));
        clcd_print(" ",LINE2(0));
    }
    else
    {
        clcd_print(" ",LINE1(0));
        clcd_print("*",LINE2(0));
    }
    
    if(key == SW2)
    {
        if(s_f == 0)
        s_f = 1;
        else if(i<2)
        i++;
    }
    else if(key == SW1)
    {
        if(s_f == 1)
        s_f = 0;
        else if(i>0)
        i--;
    }
    if(key == SW4)
    {
        CLEAR_DISP_SCREEN;
        if(i+s_f == 0) state = e_view;
        else if(i+s_f == 1) state = e_download;
        else if(i+s_f == 2) state = e_clear;
        else if(i+s_f == 3) state = e_set_time;
    }
    else if(key == SW5){
        CLEAR_DISP_SCREEN;
        state = e_Dashboard;
        
    }
}

void main(void) 
{  
    init_config();
    
    while(1)
    {
        key = read_matrix_keypad(STATE);
        switch(state)
        {
        case e_Dashboard : 
            dashboard(); 
            break;
        case e_menu :
            //CLEAR_DISP_SCREEN;
            menu();
             break; 
        case e_view : 
            view();
            break;
        case e_download : 
            download_log();
            break;
        case e_clear : 
            clear_log();
            break;
        case e_set_time : 
            set_time();
            break;
    }
  }
}

