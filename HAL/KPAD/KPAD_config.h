#ifndef KPAD_CONFIG_H
#define KPAD_CONFIG_H

/*KeyPad connection port*/
#define KPAD_PORT  portB
/*Column Pins*/
#define KPAD_C0_PIN pin3__
#define KPAD_C1_PIN pin2__
#define KPAD_C2_PIN pin0__
#define KPAD_C3_PIN pin1__
/*Row Pins*/
#define KPAD_R0_PIN pin5__
#define KPAD_R1_PIN pin4__
#define KPAD_R2_PIN pin6__
#define KPAD_R3_PIN pin7__
/*Return if no key is pressed*/
#define KEY_NOT_PRESSED 100
/*Characters to print on LCD respective to each PUSH button*/
#define USER_NUMBERS {{'1','2','3','4'},\
					  {'5','6','7','8'},\
					  {'9','0','m','o'},\
					  {'a','z','!','!'}}
#endif
