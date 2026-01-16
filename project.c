#include<reg51.h>

// --- LCD Pins ---
sbit RS = P3^5;
sbit RW = P3^6;
sbit EN = P3^7;
#define LCD_PORT P2

//---Keypad Pins---
sbit R1 = P1^0; sbit R2 = P1^1; sbit R3 = P1^2; sbit R4 = P1^3;
sbit C1 = P1^4; sbit C2 = P1^5; sbit C3 = P1^6; sbit C4 = P1^7;
// --- Output Pins ---
sbit Motor = P3^0;
sbit Buzzer = P3^1;
void delay(unsigned int ms) {
    unsigned int i, j;
    for(i=0; i<ms; i++) for(j=0; j<1275; j++);
}

void lcd_cmd(unsigned char cmd) {
    LCD_PORT = cmd; RS = 0; RW = 0; EN = 1; delay(1); EN = 0;
}
void lcd_data(unsigned char dat) {
    LCD_PORT = dat; RS = 1; RW = 0; EN = 1; delay(1); EN = 0;
}

void lcd_str(char *s) {
    while(*s) lcd_data(*s++);
}

char keypad() {
    while(1) {
        R1=0; R2=1; R3=1; R4=1;
        if(C1==0) { while(C1==0); return '7'; }
        if(C2==0) { while(C2==0); return '8'; }
        if(C3==0) { while(C3==0); return '9'; }
        
        R1=1; R2=0; R3=1; R4=1;
        if(C1==0) { while(C1==0); return '4'; }
        if(C2==0) { while(C2==0); return '5'; }
        if(C3==0) { while(C3==0); return '6'; }

        R1=1; R2=1; R3=0; R4=1;
        if(C1==0) { while(C1==0); return '1'; }
        if(C2==0) { while(C2==0); return '2'; }
        if(C3==0) { while(C3==0); return '3'; }
    }
}
void main() {
    char pass[4];
    int i;
    Motor = 0; Buzzer = 0;
    lcd_cmd(0x38); lcd_cmd(0x0C); lcd_cmd(0x01);
    
    while(1) {
        lcd_cmd(0x01); lcd_str("Enter PIN:");
        lcd_cmd(0xC0); // Move to second line
        
        for(i=0; i<4; i++) {
            pass[i] = keypad();
            lcd_data('*'); // Show star for security
        }
        
        if(pass[0]=='1' && pass[1]=='2' && pass[2]=='3' && pass[3]=='4') {
            lcd_cmd(0x01); lcd_str("Access Granted");
            Motor = 1; delay(500); Motor = 0;
        } else {
            lcd_cmd(0x01); lcd_str("Wrong PIN!");
            Buzzer = 1; delay(500); Buzzer = 0;
        }
        delay(1000);
    }

}




