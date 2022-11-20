from PIL import Image
import PIL
import os
import glob


dirr = "./"
file_list = os.listdir(dirr)
print(file_list)

for i in file_list:
    if (not i.endswith("png")):
        continue

    i=dirr+i
    b=i.replace("png","bmp").replace("jpg","bmp")
    print("[*] file : "+b)
    img=Image.open(i)
    print(img.size)
    img.save(b,optimize=True,quality=80)