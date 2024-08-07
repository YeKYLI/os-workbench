from PIL import Image

img = Image.open('lenna.jpg')

width, height = img.size

pix = img.load()

with open('../kernel/image.h', 'w') as f:
    f.write("int imageWidth = " + str(width) + ";\n")
    f.write("int imageHeight = " + str(height) + ";\n")

    f.write("uint32_t image[" + str(width) + "][" + str(height) + "] = ")
    f.write("{")
    for x in range(width):
        f.write("{")
        for y in range(height):
            #hexRow.append(pix[x,y][0] * 0xFFFF + pix[x,y][1] * 0xFF + pix[x,y][2])
            #print(pix[x,y])
            #print(pix[x,y][0] * 0xFFFF + pix[x,y][1] * 0xFF + pix[x,y][2])
            f.write(str(pix[x,y][0] * 0xFFFF + pix[x,y][1] * 0xFF + pix[x,y][2]))
            if y != height - 1:
                f.write(",")
        if x != width - 1:
            f.write("},\n")
        else :
            f.write("}")

    f.write("};")

