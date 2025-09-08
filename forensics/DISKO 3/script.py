from pyfatfs.PyFatFS import PyFatFS

IMAGE = "disko-3.dd"
fs = PyFatFS(IMAGE, read_only=True)

with fs.openbin("/log/FLAG.GZ", "r") as f:
    data = f.read()
with open("FLAG.GZ", "wb") as out:
    out.write(data)

print("FLAG.GZ extracted")

