from PIL import Image
import sys
i = Image.open(sys.argv[1])

pixels = i.load()
width, height = i.size

for y in range(height):
    for x in range(width):
        (r, g, b, a) = pixels[x, y]
        print("0x{:02x}{:02x}{:02x}".format(r, g, b), end=",")
    print("")
