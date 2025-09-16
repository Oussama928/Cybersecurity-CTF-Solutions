# decode_flag.py
filename = "encoded.bmp"
flag_length = 50        
header_bytes = 2000  #these are the bytes to skip     

flag_bits = []

with open(filename, "rb") as f:
    f.read(header_bytes)
    
    for _ in range(flag_length * 8):
        byte = f.read(1)
        if not byte:
            break
        # extract the lsb here
        flag_bits.append(ord(byte) & 1) 

flag = ""
for i in range(0, len(flag_bits), 8):
    byte_bits = flag_bits[i:i+8]
    val = 0
    for bit_index, bit in enumerate(byte_bits):
        val |= (bit << bit_index)     
    flag += chr(val + 5)

print("Flag:", flag)
