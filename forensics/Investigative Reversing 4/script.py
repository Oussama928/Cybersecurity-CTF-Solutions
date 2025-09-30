import glob, re

def find_files():
    files = glob.glob("Item*_cp.bmp")
    def keyfn(name):
        m = re.search(r"Item(\d+)_cp\.bmp$", name)
        return -int(m.group(1)) if m else 0
    return sorted(files, key=keyfn)

def extract_flag(flag_length=50):
    bits = []
    files = find_files()

    for fname in files:
        with open(fname, "rb") as f:
            data = f.read()

        data = data[2019:] 
        i = 0
        local_14 = 0

        while local_14 < flag_length and i < len(data):
            if local_14 % 5 == 0:
                for j in range(8):
                    if i+j < len(data):
                        bits.append(data[i+j] & 1)
                i += 8
                local_14 += 1
            else:
                i += 1
                local_14 += 1

        if len(bits) >= flag_length * 8:
            break

    flag_bytes = bytearray()
    for i in range(0, len(bits), 8):
        byte = 0
        for j in range(8):
            byte |= (bits[i+j] << j)
        flag_bytes.append(byte)

    return bytes(flag_bytes)

if __name__ == "__main__":
    flag = extract_flag()
    print(flag.decode(errors="ignore"))
