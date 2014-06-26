#!/usr/bin/env python
import regs

def write (s,data, addr):
   s.write(chr( addr & ~0x80))
   s.write(chr( data ))

def read (s,addr):
   s.write(chr( addr | 0x80))
   return ord(s.read()) 

def byte (val, index):
   return ((val>>(8*index)) & 0xff)

def write_key(Key,s):
    write(s,byte(Key, 0), regs.REG_KEY_00)
    write(s,byte(Key, 1), regs.REG_KEY_01)
    write(s,byte(Key, 2), regs.REG_KEY_02)
    write(s,byte(Key, 3), regs.REG_KEY_03)
    write(s,byte(Key, 4), regs.REG_KEY_04)
    write(s,byte(Key, 5), regs.REG_KEY_05)
    write(s,byte(Key, 6), regs.REG_KEY_06)
    write(s,byte(Key, 7), regs.REG_KEY_07)
    write(s,byte(Key, 8), regs.REG_KEY_08)
    write(s,byte(Key, 9), regs.REG_KEY_09)
    write(s,byte(Key,10), regs.REG_KEY_10)
    write(s,byte(Key,11), regs.REG_KEY_11)

def write_pText(pText,s):
    write(s,byte(pText,0), regs.REG_PTEXT_0)
    write(s,byte(pText,1), regs.REG_PTEXT_1)
    write(s,byte(pText,2), regs.REG_PTEXT_2)
    write(s,byte(pText,3), regs.REG_PTEXT_3)
    write(s,byte(pText,4), regs.REG_PTEXT_4)
    write(s,byte(pText,5), regs.REG_PTEXT_5)
    write(s,byte(pText,6), regs.REG_PTEXT_6)
    write(s,byte(pText,7), regs.REG_PTEXT_7)

def encrypt(s):
    write(s,    1 , regs.REG_START)

def read_cText(s):
    cText  =  read(s,regs.REG_CIPHER_0)
    cText  =  read(s,regs.REG_CIPHER_1) <<  8 | cText
    cText  =  read(s,regs.REG_CIPHER_2) << 16 | cText
    cText  =  read(s,regs.REG_CIPHER_3) << 24 | cText
    cText  =  read(s,regs.REG_CIPHER_4) << 32 | cText
    cText  =  read(s,regs.REG_CIPHER_5) << 40 | cText
    cText  =  read(s,regs.REG_CIPHER_6) << 48 | cText
    cText  =  read(s,regs.REG_CIPHER_7) << 56 | cText
    return cText

