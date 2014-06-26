#!/usr/bin/env python

import os
import io
import Image
import struct
import serial
from simon import *
from enc_function import *

bsize=64
ksize=96
key=0x131211100b0a090803020100
ser = serial.Serial('/dev/ttyUSB0',115200,xonxoff=0, rtscts=0,bytesize=8, parity='N', stopbits=1)
if not ser.isOpen():
    ser.open()
my_simon = SIMON(bsize, ksize, key)

# key globally defined as int
#plaintext/ciphertext input as byte array

def image_to_byte(path): # convert an image into a bytearray

    img=bytearray()
   
    f = open(path, "rb")
    try:
        for i in range(0, 4):
            line = f.readline().strip()
        data = []
        while line != "":
            data.extend((line.split(' ')))                 
            line = f.readline().strip() # next 8 bytes

            #b=bytearray.fromhex(hex(data)[2:]))

    finally:
        #print data
        print len(data)/ 8.0
        
        f.close()
        return data




def byte_to_image(byte_list, path):  # convert a bytearray into an image

    f = open(path, "w")
    f.write('P2\n') #headers
    f.write('512 512\n')
    f.write('255\n')
    f.write(' '.join(byte_list))
    f.write('\n')
    f.close()
    
        

def int_to_bytes(val, num_bytes):
    return [(val & (0xff << pos*8)) >> pos*8 for pos in range(num_bytes)]

def encrypt_simon(plaintext):
    plain=int(plaintext,16)
    encrypted = hex(my_simon.encrypt(plain))
    if encrypted[-1]=='L': encrypted= encrypted[:-1]
    return (encrypted)[2:].zfill(16)

def decrypt_simon(ciphertext):
    cipher=int(ciphertext,16)
    decrypted = hex(my_simon.decrypt(cipher))
    if decrypted[-1]=='L': decrypted= decrypted[:-1]
    return (decrypted)[2:].zfill(16)

def enc_on_card(plaintext):
    write_pText(int(plaintext,16),ser)
    encrypt(ser)
    encrypted= hex(read_cText(ser))
    if encrypted[-1]=='L': encrypted= encrypted[:-1]
    return (encrypted)[2:].zfill(16)


def list_to_enc_list(l):
    enc_data=[]
    for i in range(len(l)/8+1):
        data=l[8*i:8*i+8]
        data.extend(['00'] * (8 - len(data)))
        hex_data=[hex(int(x))[2:].zfill(2) for x in data]
        plaintext= ''.join(hex_data)
        ciphertext=encrypt_simon(plaintext)
        hex_list=[str(int(ciphertext[i:i+2],16)).zfill(2) for i in range(0, len(ciphertext), 2)]
        enc_data.extend(hex_list)
    return enc_data

def list_to_enc_list_on_card(l):
    enc_data=[]
    write_key(key,ser)
    for i in range(len(l)/8+1):
        data=l[8*i:8*i+8]
        data.extend(['00'] * (8 - len(data)))
        hex_data=[hex(int(x))[2:].zfill(2) for x in data]
        plaintext= ''.join(hex_data)
        ciphertext=enc_on_card(plaintext)
        hex_list=[str(int(ciphertext[i:i+2],16)).zfill(2) for i in range(0, len(ciphertext), 2)]
        enc_data.extend(hex_list)
    return enc_data


def list_to_dec_list(l):
    dec_data=[]
    for i in range(len(l)/8+1):
        data=l[8*i:8*i+8]
        data.extend(['00'] * (8 - len(data)))
        hex_data=[hex(int(x))[2:].zfill(2) for x in data]
        plaintext= ''.join(hex_data)
        ciphertext=decrypt_simon(plaintext)
        hex_list=[str(int(ciphertext[i:i+2],16)).zfill(2) for i in range(0, len(ciphertext), 2)]
        dec_data.extend(hex_list)
    return dec_data

byte_to_image(list_to_enc_list_on_card(image_to_byte("lena.pgm")),"lena_enc.pgm")
ser.close()    
byte_to_image(list_to_dec_list(image_to_byte("lena_enc.pgm")),"lena_dec.pgm")
