#include"cpu.h"

cpu::cpu()
{
	opTable[0x05] = &cpu::ORA_zp;
	opTable[0x06] = &cpu::ASL_zp;
	opTable[0x09] = &cpu::ORA_im;
	opTable[0x0A] = &cpu::ASL;
	opTable[0x0D] = &cpu::ORA_abs;
	opTable[0x0E] = &cpu::ASL_abs;
	opTable[0x10] = &cpu::BPL;
	opTable[0x15] = &cpu::ORA_zp_x;
	opTable[0x16] = &cpu::ASL_zp_x;
	opTable[0x18] = &cpu::CLC;
	opTable[0x19] = &cpu::ORA_abs_y;
	opTable[0x1D] = &cpu::ORA_abs_x;
	opTable[0x1E] = &cpu::ASL_abs_x;
	opTable[0x24] = &cpu::BIT_zp;
	opTable[0x25] = &cpu::AND_zp;
	opTable[0x26] = &cpu::ROL_zp;
	opTable[0x29] = &cpu::AND_im;
	opTable[0x2A] = &cpu::ROL_acc;
	opTable[0x2C] = &cpu::BIT_abs;
	opTable[0x2D] = &cpu::AND_abs;
	opTable[0x2E] = &cpu::ROL_abs;
	opTable[0x30] = &cpu::BMI;
	opTable[0x35] = &cpu::AND_zp_x;
	opTable[0x36] = &cpu::ROL_zp_x;
	opTable[0x38] = &cpu::SEC;
	opTable[0x39] = &cpu::AND_abs_y;
	opTable[0x3D] = &cpu::AND_abs_x;
	opTable[0x3E] = &cpu::ROL_abs_x;
	opTable[0x45] = &cpu::EOR_zp;
	opTable[0x49] = &cpu::EOR_im;
	opTable[0x4A] = &cpu::LSR;
	opTable[0x4C] = &cpu::JMP_abs;
	opTable[0x4D] = &cpu::EOR_abs;
	opTable[0x50] = &cpu::BVC;
	opTable[0x55] = &cpu::EOR_zp_x;
	opTable[0x58] = &cpu::CLI;
	opTable[0x59] = &cpu::EOR_abs_y;
	opTable[0x5D] = &cpu::EOR_abs_x;
	opTable[0x65] = &cpu::ADC_zp;
	opTable[0x69] = &cpu::ADC_im;
	opTable[0x6D] = &cpu::ADC_abs;
	opTable[0X70] = &cpu::BVS;
	opTable[0x75] = &cpu::ADC_zp_x;
	opTable[0x78] = &cpu::SEI;
	opTable[0x79] = &cpu::ADC_abs_y;
	opTable[0x7D] = &cpu::ADC_abs_x;
	opTable[0x84] = &cpu::STY_zp;
	opTable[0x85] = &cpu::STA_zp;
	opTable[0x86] = &cpu::STX_zp;
	opTable[0x88] = &cpu::DEY;
	opTable[0x8A] = &cpu::TXA;
	opTable[0x90] = &cpu::BCC;
	opTable[0x98] = &cpu::TYA;
	opTable[0xA0] = &cpu::LDY_im;
	opTable[0xA2] = &cpu::LDX_im;
	opTable[0xA4] = &cpu::LDY_zp;
	opTable[0xA5] = &cpu::LDA_zp;
	opTable[0xA6] = &cpu::LDX_zp;
	opTable[0xA8] = &cpu::TAY;
	opTable[0xA9] = &cpu::LDA_im;
	opTable[0xAA] = &cpu::TAX;
	opTable[0xAC] = &cpu::LDY_abs;
	opTable[0xAD] = &cpu::LDA_abs;
	opTable[0xAE] = &cpu::LDX_abs;
	opTable[0xB0] = &cpu::BCS;
	opTable[0xB4] = &cpu::LDY_zp_x;
	opTable[0xB5] = &cpu::LDA_zp_x;
	opTable[0xB8] = &cpu::CLV;
	opTable[0xB9] = &cpu::LDA_abs_y;
	opTable[0xBC] = &cpu::LDY_abs_x;
	opTable[0xBD] = &cpu::LDA_abs_x;
	opTable[0xBE] = &cpu::LDX_abs_y;
	opTable[0xC0] = &cpu::CPY_im;
	opTable[0xC4] = &cpu::CPY_zp;
	opTable[0xC5] = &cpu::CMP_zp;
	opTable[0xC6] = &cpu::DEC_zp;
	opTable[0xC8] = &cpu::INY;
	opTable[0xC9] = &cpu::CMP_im;
	opTable[0xCA] = &cpu::DEX;
	opTable[0xCC] = &cpu::CPY_abs;
	opTable[0xCD] = &cpu::CMP_abs;
	opTable[0xCE] = &cpu::DEC_abs;
	opTable[0xD0] = &cpu::BNE;
	opTable[0xD5] = &cpu::CMP_zp_x;
	opTable[0xD6] = &cpu::DEC_zp_x;
	opTable[0xD8] = &cpu::CLD;
	opTable[0xD9] = &cpu::CMP_abs_y;
	opTable[0xDD] = &cpu::CMP_abs_x;
	opTable[0xDE] = &cpu::DEC_abs_x;
	opTable[0xE0] = &cpu::CPX_im;
	opTable[0xE4] = &cpu::CPX_zp;
	opTable[0xE6] = &cpu::INC_zp;
	opTable[0xE8] = &cpu::INX;
	opTable[0xEA] = &cpu::NOP;
	opTable[0xEC] = &cpu::CPX_abs;
	opTable[0xEE] = &cpu::INC_abs;
	opTable[0xF0] = &cpu::BEQ;
	opTable[0xF6] = &cpu::INC_zp_x;
	opTable[0xF8] = &cpu::SED;
	opTable[0xFE] = &cpu::INC_abs_x;
}

void cpu::LSR()
{
	acc = acc >> 1;
	pc++;
}


void cpu::LDA_im()
{
	pc++;
	uint8_t b = memory[pc];
	acc = b;
	
	if (b == 0)
	{
		zf = 1;
	}

	uint8_t y = acc;
	y = y >> 7;
	if (y == 1)
	{
		nf = 1;
	}

	pc++;
}

void cpu::LDA_zp()
{
	pc++;
	uint8_t b = memory[memory[pc]];
	acc = b;

	if (acc == 0)
	{
		zf = 1;
	}
	if ((acc>>7) == 1)
	{
		nf = 1;
	}

	pc++;
}

void cpu::LDA_zp_x()
{
	pc++;
	uint8_t res = memory[pc] + x;
	uint8_t b = memory[res];
	acc = b;

	if (acc == 0)
	{
		zf = 1;
	}
	if ((acc >> 7) == 1)
	{
		nf = 1;
	}

	pc++;
}

void cpu::LDA_abs()
{
	pc++;
	uint16_t res = (((uint16_t)memory[pc++] << 8) | memory[pc]);
	uint8_t b = memory[res];
	acc = b;

	if (acc == 0)
	{
		zf = 1;
	}
	if ((acc >> 7) == 1)
	{
		nf = 1;
	}

	pc++;
}

void cpu::LDA_abs_x()
{
	pc++;
	uint16_t res = (((uint16_t)memory[pc++] << 8) | memory[pc]);
	res = res + x;
	uint8_t b = memory[res];
	acc = b;

	if (acc == 0)
	{
		zf = 1;
	}
	if ((acc >> 7) == 1)
	{
		nf = 1;
	}

	pc++;
}

void cpu::LDA_abs_y()
{
	pc++;
	uint16_t res = (((uint16_t)memory[pc++] << 8) | memory[pc]);
	res = res + y;
	uint8_t b = memory[res];
	acc = b;

	if (acc == 0)
	{
		zf = 1;
	}
	if ((acc >> 7) == 1)
	{
		nf = 1;
	}

	pc++;
}

void cpu::ADC_im()
{
	pc++;

	uint8_t b = memory[pc];
	uint16_t sum = acc + b + cf;

	acc = sum & 0xff;

	if (sum > 0xff)
	{
		cf = 1;
	}

	uint8_t y = acc;
	y = y >> 7;
	if (y == 1)
	{
		nf = 1;
	}

	if (acc == 0)
	{
		zf = 1;
	}

	uint8_t z = ~(acc ^ b) & (acc ^ (uint8_t)sum) & 0x80;
	if (z != 0)
	{
		of = 1;
	}

	pc++;
}

void cpu::ADC_zp()
{
	pc++;

	uint8_t b = memory[memory[pc]];
	uint16_t sum = acc + b + cf;

	acc = sum & 0xff;

	if (sum > 0xff)
	{
		cf = 1;
	}

	uint8_t y = acc;
	y = y >> 7;
	if (y == 1)
	{
		nf = 1;
	}

	if (acc == 0)
	{
		zf = 1;
	}

	uint8_t z = ~(acc ^ b) & (acc ^ (uint8_t)sum) & 0x80;
	if (z != 0)
	{
		of = 1;
	}

	pc++;
}

void cpu::ADC_zp_x()
{
	pc++;

	uint8_t res = memory[pc] + x;
	uint8_t b = memory[res];
	uint16_t sum = acc + b + cf;

	acc = sum & 0xff;

	if (sum > 0xff)
	{
		cf = 1;
	}

	uint8_t y = acc;
	y = y >> 7;
	if (y == 1)
	{
		nf = 1;
	}

	if (acc == 0)
	{
		zf = 1;
	}

	uint8_t z = ~(acc ^ b) & (acc ^ (uint8_t)sum) & 0x80;
	if (z != 0)
	{
		of = 1;
	}

	pc++;
}

void cpu::ADC_abs()
{
	pc++;

	uint8_t res1 = memory[pc];
	pc++;
	uint8_t res2 = memory[pc];
	uint16_t res = ((res2 << 8) | res1);


	uint8_t b = memory[res];
	uint16_t sum = acc + b + cf;

	acc = sum & 0xff;

	if (sum > 0xff)
	{
		cf = 1;
	}

	uint8_t y = acc;
	y = y >> 7;
	if (y == 1)
	{
		nf = 1;
	}

	if (acc == 0)
	{
		zf = 1;
	}

	uint8_t z = ~(acc ^ b) & (acc ^ (uint8_t)sum) & 0x80;
	if (z != 0)
	{
		of = 1;
	}

	pc++;
}

void cpu::ADC_abs_x()
{
	pc++;

	uint8_t res1 = memory[pc];
	pc++;
	uint8_t res2 = memory[pc];
	uint16_t res = ((res2 << 8) | res1);
	res = res + x;

	uint8_t b = memory[res];
	uint16_t sum = acc + b + cf;

	acc = sum & 0xff;

	if (sum > 0xff)
	{
		cf = 1;
	}

	uint8_t y = acc;
	y = y >> 7;
	if (y == 1)
	{
		nf = 1;
	}

	if (acc == 0)
	{
		zf = 1;
	}

	uint8_t z = ~(acc ^ b) & (acc ^ (uint8_t)sum) & 0x80;
	if (z != 0)
	{
		of = 1;
	}

	pc++;
}

void cpu::ADC_abs_y()
{
	pc++;

	uint8_t res1 = memory[pc];
	pc++;
	uint8_t res2 = memory[pc];
	uint16_t res = ((res2 << 8) | res1);
	res = res + y;

	uint8_t b = memory[res];
	uint16_t sum = acc + b + cf;

	acc = sum & 0xff;

	if (sum > 0xff)
	{
		cf = 1;
	}

	uint8_t y = acc;
	y = y >> 7;
	if (y == 1)
	{
		nf = 1;
	}

	if (acc == 0)
	{
		zf = 1;
	}

	uint8_t z = ~(acc ^ b) & (acc ^ (uint8_t)sum) & 0x80;
	if (z != 0)
	{
		of = 1;
	}

	pc++;
}

void cpu::AND_im()
{
	pc++;

	uint8_t b = memory[pc];
	acc = acc & b;

	if (acc == 0)
	{
		zf = 1;
	}

	uint8_t y = acc;
	y = y >> 7;
	if (y == 1)
	{
		nf = 1;
	}


	pc++;
}

void cpu::AND_zp()
{
	pc++;

	uint8_t b = memory[memory[pc]];
	acc = acc & b;

	if (acc == 0)
	{
		zf = 1;
	}
	if ((acc>>7) == 1)
	{
		nf = 1;
	}

	pc++;
}

void cpu::AND_zp_x()
{
	pc++;

	uint8_t res = memory[pc] + x;
	uint8_t b = memory[res];
	acc = acc & b;

	if (acc == 0)
	{
		zf = 1;
	}
	if ((acc >> 7) == 1)
	{
		nf = 1;
	}

	pc++;
}

void cpu::AND_abs()
{
	pc++;

	uint16_t res = (((uint16_t)memory[pc++] << 8) | memory[pc]);

	uint8_t b = memory[res];
	acc = acc & b;

	if (acc == 0)
	{
		zf = 1;
	}
	if ((acc >> 7) == 1)
	{
		nf = 1;
	}

	pc++;
}

void cpu::AND_abs_x()
{
	pc++;
	uint16_t res = (((uint16_t)memory[pc++] << 8) | memory[pc]);
	res = res + x;
	uint8_t b = memory[res];
	acc = acc & b;

	if (acc == 0)
	{
		zf = 1;
	}
	if ((acc >> 7) == 1)
	{
		nf = 1;
	}

	pc++;
}

void cpu::AND_abs_y()
{
	pc++;
	uint16_t res = (((uint16_t)memory[pc++] << 8) | memory[pc]);
	res = res + y;
	uint8_t b = memory[res];
	acc = acc & b;

	if (acc == 0)
	{
		zf = 1;
	}
	if ((acc >> 7) == 1)
	{
		nf = 1;
	}

	pc++;
}

void cpu::ASL()
{
	uint8_t b = acc>>7;
	cf = b;
	acc = acc << 1;

	if (acc == 0)
	{
		zf = 1;
	}

	if ((acc >> 7) == 1)
	{
		nf = 1;
	}

	pc++;
}

void cpu::ASL_zp()
{
	pc++;
	uint8_t b = memory[memory[pc]];
	if ((b >> 7) == 1)
	{
		cf = 1;
	}

	b = b << 1;
	if (b == 0)
	{
		zf = 1;
	}
	if ((b >> 7) == 1)
	{
		nf = 1;
	}
	memory[memory[pc]] = b;
	pc++;
}

void cpu::ASL_zp_x()
{
	pc++;

	uint8_t res = memory[pc] + x;
	uint8_t b = memory[res];
	if ((b >> 7) == 1)
	{
		cf = 1;
	}

	b = b << 1;
	if (b == 0)
	{
		zf = 1;
	}
	if ((b >> 7) == 1)
	{
		nf = 1;
	}
	memory[res] = b;
	pc++;
}

void cpu::ASL_abs()
{
	pc++;

	uint16_t res = (((uint16_t)memory[pc++] << 8) | memory[pc]);

	uint8_t b = memory[res];
	if ((b >> 7) == 1)
	{
		cf = 1;
	}

	b = b << 1;
	if (b == 0)
	{
		zf = 1;
	}
	if ((b >> 7) == 1)
	{
		nf = 1;
	}
	memory[res] = b;
	pc++;
}

void cpu::ASL_abs_x()
{
	pc++;
	uint16_t res = (((uint16_t)memory[pc++] << 8) | memory[pc]);
	res = res + x;

	uint8_t b = memory[res];
	if ((b >> 7) == 1)
	{
		cf = 1;
	}

	b = b << 1;
	if (b == 0)
	{
		zf = 1;
	}
	if ((b >> 7) == 1)
	{
		nf = 1;
	}
	memory[res] = b;
	pc++;
}

void cpu::BCC()
{
	pc++;
	uint8_t b = memory[pc];

	if (cf == 0)
	{
		pc = pc + b;
	}

	pc++;
}

void cpu::BCS()
{
	pc++;
	uint8_t b = memory[pc];

	if (cf == 1)
	{
		pc = pc + b;
	}

	pc++;
}

void cpu::BEQ()
{
	pc++;
	uint8_t b = memory[pc];

	if (zf == 1)
	{
		pc = pc + b;
	}
	pc++;
}

void cpu::BMI()
{
	pc++;
	uint8_t b = memory[pc];

	if (nf == 1)
	{
		pc = pc + b;
	}
	pc++;
}

void cpu::BNE()
{
	pc++;
	uint8_t b = memory[pc];

	if (zf == 0)
	{
		pc = pc + b;
	}
	pc++;
}

void cpu::BPL()
{
	pc++;
	uint8_t b = memory[pc];

	if (nf == 0)
	{
		pc = pc + b;
	}
	pc++;
}

void cpu::BVC()
{
	pc++;
	uint8_t b = memory[pc];
	if (of == 0)
	{
		pc = pc + b;
	}
	pc++;
}

void cpu::BVS()
{
	pc++;
	uint8_t b = memory[pc];
	if (of == 1)
	{
		pc = pc + b;
	}
	pc++;
}

void cpu::CLC()
{
	cf = 0;
	pc++;
}

void cpu::CLD()
{
	dm = 0;
	pc++;
}

void cpu::CLI()
{
	id = 0;
	pc++;
}

void cpu::CLV()
{
	of = 0;
	pc++;
}

void cpu::CMP_im()
{
	pc++;
	uint8_t b = memory[pc];
	
	if (acc >= b)
	{
		cf = 1;
	}
	if (acc == b)
	{
		zf = 1;
	}
	uint8_t diff = acc - b;
	diff = diff >> 7;
	if (diff == 1)
	{
		nf = 1;
	}
	pc++;
}

void cpu::CMP_zp()
{
	pc++;
	uint8_t b = memory[memory[pc]];

	if (acc >= b)
	{
		cf = 1;
	}
	if (acc == b)
	{
		zf = 1;
	}
	uint8_t diff = acc - b;
	diff = diff >> 7;
	if (diff == 1)
	{
		nf = 1;
	}
	pc++;
}

void cpu::CMP_zp_x()
{
	pc++;

	uint8_t res = memory[pc] + x;
	uint8_t b = memory[res];

	if (acc >= b)
	{
		cf = 1;
	}
	if (acc == b)
	{
		zf = 1;
	}
	uint8_t diff = acc - b;
	diff = diff >> 7;
	if (diff == 1)
	{
		nf = 1;
	}
	pc++;
}

void cpu::CMP_abs()
{
	pc++;

	uint16_t res = (((uint16_t)memory[pc++] << 8) | memory[pc]);

	uint8_t b = memory[res];

	if (acc >= b)
	{
		cf = 1;
	}
	if (acc == b)
	{
		zf = 1;
	}
	uint8_t diff = acc - b;
	diff = diff >> 7;
	if (diff == 1)
	{
		nf = 1;
	}
	pc++;
}

void cpu::CMP_abs_x()
{
	pc++;

	uint16_t res = (((uint16_t)memory[pc++] << 8) | memory[pc]);
	res = res + x;
	uint8_t b = memory[res];

	if (acc >= b)
	{
		cf = 1;
	}
	if (acc == b)
	{
		zf = 1;
	}
	uint8_t diff = acc - b;
	diff = diff >> 7;
	if (diff == 1)
	{
		nf = 1;
	}
	pc++;
}

void cpu::CMP_abs_y()
{
	pc++;

	uint16_t res = (((uint16_t)memory[pc++] << 8) | memory[pc]);
	res = res + y;
	uint8_t b = memory[res];

	if (acc >= b)
	{
		cf = 1;
	}
	if (acc == b)
	{
		zf = 1;
	}
	uint8_t diff = acc - b;
	diff = diff >> 7;
	if (diff == 1)
	{
		nf = 1;
	}
	pc++;
}

void cpu::CPX_im()
{
	pc++;
	uint8_t b = memory[pc];

	if (x >= b)
	{
		cf = 1;
	}
	if (x == b)
	{
		zf = 1;
	}

	uint8_t diff = x - b;
	diff = diff >> 7;
	if (diff == 1)
	{
		nf = 1;
	}
	pc++;
}

void cpu::CPX_zp()
{
	pc++;
	uint8_t b = memory[memory[pc]];

	if (x >= b)
	{
		cf = 1;
	}
	if (x == b)
	{
		zf = 1;
	}

	uint8_t diff = x - b;
	diff = diff >> 7;
	if (diff == 1)
	{
		nf = 1;
	}
	pc++;
}

void cpu::CPX_abs()
{
	pc++;

	uint16_t res = (((uint16_t)memory[pc++] << 8) | memory[pc]);

	uint8_t b = memory[res];

	if (x >= b)
	{
		cf = 1;
	}
	if (x == b)
	{
		zf = 1;
	}

	uint8_t diff = x - b;
	diff = diff >> 7;
	if (diff == 1)
	{
		nf = 1;
	}
	pc++;
}

void cpu::CPY_im()
{
	pc++;
	uint8_t b = memory[pc];

	if (y >= b)
	{
		cf = 1;
	}
	if (y == b)
	{
		zf = 1;
	}

	uint8_t diff = y - b;
	diff = diff >> 7;
	if (diff == 1)
	{
		nf = 1;
	}
	pc++;
}

void cpu::CPY_zp()
{
	pc++;
	uint8_t b = memory[memory[pc]];

	if (y >= b)
	{
		cf = 1;
	}
	if (y == b)
	{
		zf = 1;
	}

	uint8_t diff = y - b;
	diff = diff >> 7;
	if (diff == 1)
	{
		nf = 1;
	}
	pc++;
}

void cpu::CPY_abs()
{
	pc++;

	uint16_t res = (((uint16_t)memory[pc++] << 8) | memory[pc]);
	uint8_t b = memory[res];

	if (y >= b)
	{
		cf = 1;
	}
	if (y == b)
	{
		zf = 1;
	}

	uint8_t diff = y - b;
	diff = diff >> 7;
	if (diff == 1)
	{
		nf = 1;
	}
	pc++;
}

void cpu::DEX()
{
	x--;
	if (x == 0)
	{
		zf = 1;
	}
	if ((x >> 7) == 1)
	{
		nf = 1;
	}
	pc++;
}

void cpu::DEY()
{
	y--;
	if (y == 0)
	{
		zf = 1;
	}
	if ((y >> 7) == 1)
	{
		nf = 1;
	}
	pc++;
}

void cpu::EOR_im()
{
	pc++;
	uint8_t b = memory[pc];

	acc = acc ^ b;
	if (acc == 0)
	{
		zf = 1;
	}
	if ((acc>>7)==1)
	{
		nf = 1;
	}

	pc++;
}

void cpu::EOR_zp()
{
	pc++;
	uint8_t b = memory[memory[pc]];

	acc = acc ^ b;
	if (acc == 0)
	{
		zf = 1;
	}
	if ((acc >> 7) == 1)
	{
		nf = 1;
	}
	pc++;
}

void cpu::EOR_zp_x()
{
	pc++;
	uint8_t res = memory[pc] + x;
	uint8_t b = memory[res];

	acc = acc ^ b;
	if (acc == 0)
	{
		zf = 1;
	}
	if ((acc >> 7) == 1)
	{
		nf = 1;
	}
	pc++;
}

void cpu::EOR_abs()
{
	pc++;
	uint16_t res = (((uint16_t)memory[pc++] << 8) | memory[pc]);
	uint8_t b = memory[res];

	acc = acc ^ b;
	if (acc == 0)
	{
		zf = 1;
	}
	if ((acc >> 7) == 1)
	{
		nf = 1;
	}
	pc++;
}

void cpu::EOR_abs_x()
{
	pc++;
	uint16_t res = (((uint16_t)memory[pc++] << 8) | memory[pc]);
	res = res + x;
	uint8_t b = memory[res];

	acc = acc ^ b;
	if (acc == 0)
	{
		zf = 1;
	}
	if ((acc >> 7) == 1)
	{
		nf = 1;
	}
	pc++;
}

void cpu::EOR_abs_y()
{
	pc++;
	uint16_t res = (((uint16_t)memory[pc++] << 8) | memory[pc]);
	res = res + y;
	uint8_t b = memory[res];

	acc = acc ^ b;
	if (acc == 0)
	{
		zf = 1;
	}
	if ((acc >> 7) == 1)
	{
		nf = 1;
	}
	pc++;
}

void cpu::INX()
{
	x++;
	if (x == 0)
	{
		zf = 1;
	}
	if ((x >> 7) == 1)
	{
		nf = 1;
	}
	pc++;
}

void cpu::INY()
{
	y++;
	if (y == 0)
	{
		zf = 1;
	}
	if ((y >> 7) == 1)
	{
		nf = 1;
	}
	pc++;
}

void cpu::LDX_im()
{
	pc++;
	uint8_t b = memory[pc];

	x = b;
	if (x == 0)
	{
		zf = 1;
	}
	if ((x >> 7) == 1)
	{
		nf = 1;
	}

	pc++;
}

void cpu::LDX_zp()
{
	pc++;
	uint8_t b = memory[memory[pc]];

	x = b;
	if (x == 0)
	{
		zf = 1;
	}
	if ((x >> 7) == 1)
	{
		nf = 1;
	}

	pc++;
}

void cpu::LDX_abs()
{
	pc++;
	uint16_t res = (((uint16_t)memory[pc++] << 8) | memory[pc]);
	uint8_t b = memory[res];

	x = b;
	if (x == 0)
	{
		zf = 1;
	}
	if ((x >> 7) == 1)
	{
		nf = 1;
	}

	pc++;
}

void cpu::LDX_abs_y()
{
	pc++;
	uint16_t res = (((uint16_t)memory[pc++] << 8) | memory[pc]);
	res = res + y;
	uint8_t b = memory[res];

	x = b;
	if (x == 0)
	{
		zf = 1;
	}
	if ((x >> 7) == 1)
	{
		nf = 1;
	}

	pc++;
}

void cpu::LDY_im()
{
	pc++;
	uint8_t b = memory[pc];

	y = b;
	if (y == 0)
	{
		zf = 1;
	}
	if ((y >> 7) == 1)
	{
		nf = 1;
	}
	pc++;
}

void cpu::LDY_zp()
{
	pc++;
	uint8_t b = memory[memory[pc]];

	y = b;
	if (y == 0)
	{
		zf = 1;
	}
	if ((y >> 7) == 1)
	{
		nf = 1;
	}
	pc++;
}

void cpu::LDY_zp_x()
{
	pc++;
	uint8_t res = memory[pc] + x;
	uint8_t b = memory[res];

	y = b;
	if (y == 0)
	{
		zf = 1;
	}
	if ((y >> 7) == 1)
	{
		nf = 1;
	}
	pc++;
}

void cpu::LDY_abs()
{
	pc++;
	uint16_t res = (((uint16_t)memory[pc++] << 8) | memory[pc]);
	uint8_t b = memory[res];

	y = b;
	if (y == 0)
	{
		zf = 1;
	}
	if ((y >> 7) == 1)
	{
		nf = 1;
	}
	pc++;
}

void cpu::LDY_abs_x()
{
	pc++;
	uint16_t res = (((uint16_t)memory[pc++] << 8) | memory[pc]);
	res = res + x;
	uint8_t b = memory[res];

	y = b;
	if (y == 0)
	{
		zf = 1;
	}
	if ((y >> 7) == 1)
	{
		nf = 1;
	}
	pc++;
}

void cpu::NOP()
{
	pc++;
}

void cpu::ORA_im()
{
	pc++;
	uint8_t b = memory[pc];

	acc = acc | b;

	if (acc == 0)
	{
		zf = 1;
	}
	if ((acc >> 7) == 1)
	{
		nf = 1;
	}

	pc++;
}

void cpu::ORA_zp()
{
	pc++;
	uint8_t b = memory[memory[pc]];

	acc = acc | b;

	if (acc == 0)
	{
		zf = 1;
	}
	if ((acc >> 7) == 1)
	{
		nf = 1;
	}

	pc++;
}

void cpu::ORA_zp_x()
{
	pc++;
	uint8_t res = memory[pc] + x;
	uint8_t b = memory[res];

	acc = acc | b;

	if (acc == 0)
	{
		zf = 1;
	}
	if ((acc >> 7) == 1)
	{
		nf = 1;
	}

	pc++;
}

void cpu::ORA_abs()
{
	pc++;
	uint16_t res = (((uint16_t)memory[pc++] << 8) | memory[pc]);
	uint8_t b = memory[res];

	acc = acc | b;

	if (acc == 0)
	{
		zf = 1;
	}
	if ((acc >> 7) == 1)
	{
		nf = 1;
	}

	pc++;
}

void cpu::ORA_abs_x()
{
	pc++;
	uint16_t res = (((uint16_t)memory[pc++] << 8) | memory[pc]);
	res = res + x;
	uint8_t b = memory[res];

	acc = acc | b;

	if (acc == 0)
	{
		zf = 1;
	}
	if ((acc >> 7) == 1)
	{
		nf = 1;
	}

	pc++;
}

void cpu::ORA_abs_y()
{
	pc++;
	uint16_t res = (((uint16_t)memory[pc++] << 8) | memory[pc]);
	res = res + y;
	uint8_t b = memory[res];

	acc = acc | b;

	if (acc == 0)
	{
		zf = 1;
	}
	if ((acc >> 7) == 1)
	{
		nf = 1;
	}

	pc++;
}

void cpu::SEC()
{
	cf = 1;
	pc++;
}

void cpu::SED()
{
	dm = 1;
	pc++;
}

void cpu::SEI()
{
	id = 1;
	pc++;
}

void cpu::TAX()
{
	x = acc;
	if (x == 0)
	{
		zf = 1;
	}
	if ((x >> 7) == 1)
	{
		nf = 1;
	}
	pc++;
}

void cpu::TAY()
{
	y = acc;
	if (y == 0)
	{
		zf = 1;
	}
	if ((y >> 7) == 1)
	{
		nf = 1;
	}
	pc++;
}

void cpu::DEC_zp()
{
	pc++;
	uint8_t b = memory[memory[pc]];

	b--;
	if (b == 0)
	{
		zf = 1;
	}
	if ((b >> 7) == 1)
	{
		nf = 1;
	}
	memory[memory[pc]] = b;
	pc++;
}

void cpu::DEC_zp_x()
{
	pc++;
	uint8_t res = memory[pc]+x;
	uint8_t b = memory[res];

	b--;
	if (b == 0)
	{
		zf = 1;
	}
	if ((b >> 7) == 1)
	{
		nf = 1;
	}
	memory[res] = b;
	pc++;
}

void cpu::DEC_abs()
{
	pc++;
	uint16_t res = (((uint16_t)memory[pc++] << 8) | memory[pc]);
	uint8_t b = memory[res];

	b--;
	if (b == 0)
	{
		zf = 1;
	}
	if ((b >> 7) == 1)
	{
		nf = 1;
	}
	memory[res] = b;
	pc++;
}

void cpu::DEC_abs_x()
{
	pc++;
	uint16_t res = (((uint16_t)memory[pc++] << 8) | memory[pc]);
	res = res + x;
	uint8_t b = memory[res];

	b--;
	if (b == 0)
	{
		zf = 1;
	}
	if ((b >> 7) == 1)
	{
		nf = 1;
	}
	memory[res] = b;
	pc++;
}

void cpu::INC_zp()
{
	pc++;
	uint8_t b = memory[memory[pc]];
	b++;
	if (b == 0)
	{
		zf = 1;
	}
	if ((b >> 7) == 1)
	{
		nf = 1;
	}
	memory[memory[pc]] = b;
	pc++;
}

void cpu::INC_zp_x()
{
	pc++;
	uint8_t res = memory[pc] + x;
	uint8_t b = memory[res];
	b++;
	if (b == 0)
	{
		zf = 1;
	}
	if ((b >> 7) == 1)
	{
		nf = 1;
	}
	memory[res] = b;
	pc++;
}

void cpu::INC_abs()
{
	pc++;
	uint16_t res = (((uint16_t)memory[pc++] << 8) | memory[pc]);
	uint8_t b = memory[res];
	b++;
	if (b == 0)
	{
		zf = 1;
	}
	if ((b >> 7) == 1)
	{
		nf = 1;
	}
	memory[res] = b;
	pc++;
}

void cpu::INC_abs_x()
{
	pc++;
	uint16_t res = (((uint16_t)memory[pc++] << 8) | memory[pc]);
	res = res + x;
	uint8_t b = memory[res];
	b++;
	if (b == 0)
	{
		zf = 1;
	}
	if ((b >> 7) == 1)
	{
		nf = 1;
	}
	memory[res] = b;
	pc++;
}

void cpu::STA_zp()
{
	pc++;
	memory[memory[pc]] = acc;
	pc++;
}

void cpu::STX_zp()
{
	pc++;
	memory[memory[pc]] = x;
	pc++;
}

void cpu::STY_zp()
{
	pc++;
	memory[memory[pc]] = y;
	pc++;
}

void cpu::BIT_zp()
{
	pc++;
	uint8_t b = memory[memory[pc]];
	uint8_t res = (b & acc);

	if (res == 0)
	{
		zf = 1;
	}
	nf = (b & 0x80);
	of = (b & 0x40);
	pc++;
}

void cpu::BIT_abs()
{
	pc++;
	uint16_t res = (((uint16_t)memory[pc++] << 8) | memory[pc]);
	uint8_t b = memory[res];
	uint8_t an = (b & acc);

	if (an == 0)
	{
		zf = 1;
	}
	nf = (b & 0x80);
	of = (b & 0x40);
	pc++;
}

void cpu::JMP_abs()
{
	pc++;
	uint16_t res = (((uint16_t)memory[pc++] << 8) | memory[pc]);
	pc = res;
}

void cpu::ROL_acc()
{
	bool b = (acc & 0x80);
	acc = (acc << 1);
	cf = b;

	if (acc == 0)
	{
		zf = 1;
	}
	if ((acc >> 7) == 1)
	{
		nf = 1;
	}

	pc++;
}

void cpu::ROL_zp()
{
	pc++;
	uint8_t b = memory[memory[pc]];
	bool temp = (b & 0x80);
	b = (b << 1);
	cf = temp;

	if (b == 0)
	{
		zf = 1;
	}
	if ((b >> 7) == 1)
	{
		nf = 1;
	}
	memory[memory[pc]] = b;
	pc++;
}

void cpu::ROL_zp_x()
{
	pc++;
	uint8_t res = memory[pc] + x;
	uint8_t b = memory[res];
	bool temp = (b & 0x80);
	b = (b << 1);
	cf = temp;

	if (b == 0)
	{
		zf = 1;
	}
	if ((b >> 7) == 1)
	{
		nf = 1;
	}
	memory[res] = b;
	pc++;
}

void cpu::ROL_abs()
{
	pc++;
	uint16_t res = (((uint16_t)memory[pc++] << 8) | memory[pc]);
	uint8_t b = memory[res];

	bool temp = (b & 0x80);
	b = (b << 1);
	cf = temp;

	if (b == 0)
	{
		zf = 1;
	}
	if ((b >> 7) == 1)
	{
		nf = 1;
	}
	memory[res] = b;
	pc++;
}

void cpu::ROL_abs_x()
{
	pc++;
	uint16_t res = (((uint16_t)memory[pc++] << 8) | memory[pc]);
	res = res + x;
	uint8_t b = memory[res];

	bool temp = (b & 0x80);
	b = (b << 1);
	cf = temp;

	if (b == 0)
	{
		zf = 1;
	}
	if ((b >> 7) == 1)
	{
		nf = 1;
	}
	memory[res] = b;
	pc++;
}

void cpu::TXA()
{
	acc = x;
	if (acc == 0)
	{
		zf = 1;
	}
	if ((acc >> 7) == 1)
	{
		nf = 1;
	}
	pc++;
}

void cpu::TYA()
{
	acc = y;
	if (acc == 0)
	{
		zf = 1;
	}
	if ((acc >> 7) == 1)
	{
		nf = 1;
	}
	pc++;
}

void cpu::loadRom(string filename)
{
	ifstream file(filename, ios::binary);
	/*uint8_t op;

	//file.open(filename.c_str());

	if (file.fail())
	{
		cerr << "Error opening file" << endl;
		exit(1);
	}

	uint16_t start = 0x0200;
	while (!file.eof())
	{
		file >> op;
		memory[start] = op;
		start++;
	}*/

	if (file.fail())
	{
		cerr << "Error opening file" << endl;
		exit(1);
	}

	file.seekg(0, file.end);

	int length = file.tellg();

	file.seekg(0, file.beg);

	char* buffer = new char[length];
	file.read(buffer, length);
	file.close();

	uint16_t index = 0x0200;
	for (int i = 0; i < length; i++)
	{
		memory[index] = buffer[i];
		index++;
	}

	delete[] buffer;
}

void cpu::status()
{
	cout << "X: " << (int)x << endl;
	cout << "Y: " << (int)y << endl;

	cout << "Acc: " << (int)acc << endl;

	cout << "PC: " << (int)pc << endl;
	cout << "SP: " << (int)sp << endl;
	cout << endl;
	cout << "cf: " << (int)cf << endl;
	cout << "zf: " << (int)zf << endl;
	cout << "id: " << (int)id << endl;
	cout << "dm: " << (int)dm << endl;
	cout << "bk: " << (int)bk << endl;
	cout << "of: " << (int)of << endl;
	cout << "nf: " << (int)nf << endl;
}

void cpu::cycle()
{
	opcode = memory[pc];
	((*this).*opTable[opcode])();
}
