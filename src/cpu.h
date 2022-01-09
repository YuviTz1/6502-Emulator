#pragma once
#include<iostream>
#include<fstream>
using namespace std;

class cpu
{
private:

	uint16_t pc=0x200;	//program counter
	uint16_t sp=0x100;	//stack pointer

	uint8_t acc=0x0;	//accumulator
	uint8_t x=0x0;		//x register
	uint8_t y=0x0;		//y register

	//status flags
	bool cf = 0;		//carry flag
	bool zf = 0;		//zero flag
	bool id = 0;		//interrupt disable
	bool dm = 0;		//decimal mode
	bool bk = 0;		//break
	bool of = 0;		//overflow flag
	bool nf = 0;		//negative flag

	uint8_t memory[64 * 1024];
	uint8_t opcode;

public:

	typedef void(cpu::*op)();

	op opTable[256]{ &cpu::NOP };

	/*//do nothing
	void Null();*/

	cpu();
	void loadRom(string filename);
	void status();
	void cycle();

	
	//LSR
	void LSR();

	//LDA
	void LDA_im();
	void LDA_zp();
	void LDA_zp_x();
	void LDA_abs();
	void LDA_abs_x();
	void LDA_abs_y();

	//ADC
	void ADC_im();
	void ADC_zp();
	void ADC_zp_x();
	void ADC_abs();
	void ADC_abs_x();
	void ADC_abs_y();

	//AND	
	void AND_im();
	void AND_zp();
	void AND_zp_x();
	void AND_abs();
	void AND_abs_x();
	void AND_abs_y();

	//ASL
	void ASL();
	void ASL_zp();
	void ASL_zp_x();
	void ASL_abs();
	void ASL_abs_x();


	//BCC
	void BCC();

	//BCS
	void BCS();

	//BEQ
	void BEQ();

	//BMI
	void BMI();

	//BNE
	void BNE();

	//BPL
	void BPL();

	//BVC
	void BVC();

	//BVS
	void BVS();

	//CLC
	void CLC();

	//CLD
	void CLD();

	//CLI
	void CLI();

	//CLV
	void CLV();

	//CMP
	void CMP_im();
	void CMP_zp();
	void CMP_zp_x();
	void CMP_abs();
	void CMP_abs_x();
	void CMP_abs_y();

	//CPX
	void CPX_im();
	void CPX_zp();
	void CPX_abs();

	//CPY
	void CPY_im();
	void CPY_zp();
	void CPY_abs();

	//DEX
	void DEX();

	//DEY
	void DEY();

	//EOR
	void EOR_im();
	void EOR_zp();
	void EOR_zp_x();
	void EOR_abs();
	void EOR_abs_x();
	void EOR_abs_y();

	//INX
	void INX();

	//INY
	void INY();

	//LDX
	void LDX_im();
	void LDX_zp();
	void LDX_abs();
	void LDX_abs_y();

	//LDY
	void LDY_im();
	void LDY_zp();
	void LDY_zp_x();
	void LDY_abs();
	void LDY_abs_x();

	//NOP
	void NOP();

	//ORA
	void ORA_im();
	void ORA_zp();
	void ORA_zp_x();
	void ORA_abs();
	void ORA_abs_x();
	void ORA_abs_y();

	//SEC
	void SEC();

	//SED
	void SED();

	//SEI
	void SEI();

	//TAX;
	void TAX();

	//TAY
	void TAY();

	//DEC
	void DEC_zp();
	void DEC_zp_x();
	void DEC_abs();
	void DEC_abs_x();

	//INC
	void INC_zp();
	void INC_zp_x();
	void INC_abs();
	void INC_abs_x();

	//STA
	void STA_zp();

	//STX
	void STX_zp();

	//STY
	void STY_zp();

	void BIT_zp();
	void BIT_abs();

	void JMP_abs();

	void ROL_acc();
	void ROL_zp();
	void ROL_zp_x();
	void ROL_abs();
	void ROL_abs_x();

	void TXA();

	void TYA();


	//BRK

	//JSR
	//PHA
	//PHP
	//PLA
	//PLP
	// 
	//ROR
	//RTI
	//RTS
	//SBC
	//STA
	//STX
	//STY
	//TSX
	//TXS

};