#ifndef BIT_MATH_H  //file guard
#define BIT_MATH_H

#define SET_BIT(REGISTER, BITNO)       (REGISTER|=1<<BITNO)  
#define CLR_BIT(REGISTER, BITNO)       (REGISTER&=~(1<<BITNO))  
#define GET_BIT(REGISTER, BITNO)       ((REGISTER>>BITNO)&1)  
#define TOGGLE_BIT(REGISTER, BITNO)    (REGISTER^=(1<<BITNO))  

#define SET_BYTE(Reg,value)              ( Reg = value )

#define CONC_BIT(b7,b6,b5,b4,b3,b2,b1,b0) Conc_help(b7,b6,b5,b4,b3,b2,b1,b0)
#define Conc_help(b7,b6,b5,b4,b3,b2,b1,b0) 0b##b7##b6##b5##b4##b3##b2##b1##b0


#endif
//#define SET_BIT(Reg, bitnum)       (Reg |=1<<bitnum)
//#define CLR_BIT(Reg, bitnum)       (Reg &=~(1<<bitnum))
//#define GET_BIT(Reg, bitnum)       ((Reg>>bitnum)& 0x01)
//#define TOGGLE_BIT(Reg, bitnum)    (Reg ^=(1<<bitnum))
