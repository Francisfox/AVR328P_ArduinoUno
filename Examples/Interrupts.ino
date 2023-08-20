
ISR(PCINT1_vect){
  if(!(PINC & (1<<2))){           // quando receber 0 no port A3 executa o que esta dentro desta parte 
    PORTB |= 0b00100000;          //para teste liga o P5 ou o pino13 do arduino

  }else if(!(PINC & (1<<3))){     // quando receber 0 no port A2 executa o que esta dentro desta parte 
    PORTB &= 0b11011111;          //para teste desliga o P5 ou o pino13 do arduino
    
  }
}
void setup() {  
  DDRB	= 0xFF;
  PORTB = 0x00;
  
  DDRC	  = 0x00;
  PORTC   = 0b00001100;
  
  PCICR	  = 0b00000010; //PCINT1
  PCMSK1  = 0b00001100;
  sei();

}

void loop() {

}
