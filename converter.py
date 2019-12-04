# Import the python image library
from PIL import Image
# Import sys for the arguments
import sys
i = Image.open(sys.argv[1])
# Load the pixels from the image
pixels = i.load()
# Get the image width and height
width, height = i.size
# Loop through each of the pixels
for y in range(height):
    for x in range(width):
        # Extract the rgba value
        (r, g, b, a) = pixels[x, y]
        # Print out the value as a C hex value
        print("0x{:02x}{:02x}{:02x}".format(r, g, b), end=",")
    # Print a newline
    print("")
