#include <avr/io.h>
#include <avr/interrupt.h>

ISR(PCINT1_vect){
  if(!(PINC & (1<<2))){           // Quando receber 0 no port A3 executa o que esta dentro desta parte 
    PORTB |= 0b00100000;          // Para teste liga o P5 ou o pino13 do arduino

  }else if(!(PINC & (1<<3))){     // Quando receber 0 no port A2 executa o que esta dentro desta parte 
    PORTB &= 0b11011111;          // Para teste desliga o P5 ou o pino13 do arduino
    
  }
}
void setup() {  
  DDRB	= 0xFF;                   // Habilita o PORTB todos como saida 
  PORTB = 0x00;                   // Deixa todos os pinos em nivel baixo
  
  DDRC	  = 0x00;                 // Habilita o PORTC todos como entrada
  
  PCICR	  = 0b00000010;           // Habilita a chave de interrupção PCINT1
  PCMSK1  = 0b00001100;           // Habilita a chave dos pinos de A2 e A3
  sei();                          // Chave geral das interrupções 

}

void loop() {                     // Loop fica disponivel para colocar o programa de reptição h

}