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