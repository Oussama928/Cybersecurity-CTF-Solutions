
def extract_flag(path="encoded.bmp", out="decoded_flag.bin"):
    with open(path, "rb") as f:
        data = f.read()

    p = 723 
    flag_bytes = []

    for i in range(100):
        if (i & 1) == 0:
            byte_val = 0
            for bit_index in range(8):
                b = data[p]
                lsb = b & 1
                byte_val |= (lsb << bit_index)
                p += 1
            flag_bytes.append(byte_val)
        else:
            p += 1

    flag = bytes(flag_bytes)

    with open(out, "wb") as f:
        f.write(flag)

    try:
        print("Flag (UTF-8):", flag.decode("utf-8"))
    except UnicodeDecodeError:
        print("Flag (hex):", flag.hex())



if __name__ == "__main__":
    extract_flag()
