import PIL
from PIL import ImageEnhance
from PIL import ImageFilter
from PIL import Image
def effectnoise():
    print("Make an image containing noise:")
    noiseinp=input("1)Size is 256x256\n2)Size is 720x720\n3)Size is 1080x1080\n4)Size is 2000x2000\n5)Custom\n")
    if noiseinp=="1":
        size=(256,256)
        sigma=500
    elif noiseinp=="2":
        size=(720,720)
        sigma=500
    elif noiseinp=="3":
        size=(1080,1080)
        sigma=500
    elif noiseinp=="4":
        size=(2000,2000)
        sigma=500
    elif noiseinp=="Custom":
        width=int(input("Enter Width: "))
        height=int(input("Enter Height: "))
        size=(width,height)
        sigma=int(input("Enter Sigma for noise: "))
    noiseeffect=Image.effect_noise(size, sigma)
    noiseeffect.show() 
    save=input("Enter save to save OR press any key to end:- ")
    if save=='save':
        sloc=input("Enter File location to save:- ")
        name=input('Enter Name with which to save:- \n*NOTE:- Entering same name as existing image will replace the original image\n')
        noiseeffect.save(sloc+'/'+ name+".png")
print("start")
#effectnoise()
def linear_gradient():
    lig=Image.linear_gradient("L")
    lig.show()
    save=input("Enter save to save OR press any key to end:- ")
    if save=='save':
        sloc=input("Enter File location to save:- ")
        name=input('Enter Name with which to save:- \n*NOTE:- Entering same name as existing image will replace the original image\n')
        lig.save(sloc+'/'+ name+".png")
print("start")
#linear_gradient()

def radial_gradient():
    rad=Image.radial_gradient("L")
    rad.show()
    save=input("Enter save to save OR press any key to end:- ")
    if save=='save':
        sloc=input("Enter File location to save:- ")
        name=input('Enter Name with which to save:- \n*NOTE:- Entering same name as existing image will replace the original image\n')
        rad.save(sloc+'/'+ name+".png")
print("start")
#radial_gradient()

def crop():
    croploc=input("Enter image loaction  ")
    x1,y1=input("Enter starting x and y coordinate as x,y ").split(",")
    x2,y2=input("Enter ending x and y coordinate as x,y ").split(",")
    cropopen=Image.open(croploc)
    cropped=cropopen.crop((int(x1),int(y1),int(x2),int(y2)))
    cropped.show()
    save=input("Enter save to save OR press any key to end:- ")
    if save=='save':
        sloc=input("Enter File location to save:- ")
        name=input('Enter Name with which to save:- \n*NOTE:- Entering same name as existing image will replace the original image\n')
        cropped.save(sloc+'/'+ name+".png")
print("start")
#crop()
def resize():
    resizeloc=input("Enter image loaction  ")
    rx,ry=input("Enter starting x and y coordinate as x,y.\n*NOTE:- Resize will resize the image if new size is smaller than original size. ").split(",")
    resizeopen=Image.open(resizeloc)
    resized=resizeopen.resize((int(rx),int(ry)))
    resized.show()
    save=input("Enter save to save OR press any key to end:- ")
    if save=='save':
        sloc=input("Enter File location to save:- ")
        name=input('Enter Name with which to save:- \n*NOTE:- Entering same name as existing image will replace the original image\n')
        resized.save(sloc+'/'+ name+".png")
print("start")
#resize()

def filter_func():
    filterloc=input("Enter image location:- ")
    fil1=Image.open(filterloc)
    filinp=input("Select a filter:- \n1)Spread blur\n2)Enhance Colour\n3)Enhance Contrast\n4)Enhance Brightness\n5)Enhance Sharpness\n6)Gaussian Blur\n7)Contour\n8)Detailed\n9)Enhance Edges\n10)Smoothen\n")
    value=1
    if filinp=="1":
        value=int(input("Enter value for spreading the pixels:- "))
        filtered=fil1.effect_spread(value)
        filtered.show()
    elif filinp=="2":
        value=float(input("Enter value Enhancing Colour (Default is 1):- "))
        filtered=ImageEnhance.Color(fil1).enhance(value)
        filtered.show()
    elif filinp=="3":
        value=float(input("Enter value Enhancing Contrast (Default is 1):- "))
        filtered=ImageEnhance.Contrast(fil1).enhance(value)
        filtered.show()
    elif filinp=="4":
        value=float(input("Enter value Enhancing Brightness (Default is 1):- "))
        filtered=ImageEnhance.Brightness(fil1).enhance(value)
        filtered.show()
    elif filinp=="5":
        value=float(input("Enter value Enhancing Sharpness (Default is 1):- "))
        filtered=ImageEnhance.Sharpness(fil1).enhance(value)
        filtered.show()
    elif filinp=="6":
        value=float(input("Enter radius for Gaussian blur :- "))
        filtered=fil1.filter(ImageFilter.GaussianBlur(value))
        filtered.show()
    elif filinp=="7":
        filtered=fil1.filter(ImageFilter.CONTOUR)
        filtered.show()
    elif filinp=="8":
        filtered=fil1.filter(ImageFilter.DETAIL)
        filtered.show()
    elif filinp=="9":
        filtered=fil1.filter(ImageFilter.EDGE_ENHANCE)
        filtered.show()
    elif filinp=="10":
        filtered=fil1.filter(ImageFilter.SMOOTH)
        filtered.show() 
    save=input("Enter save to save OR press any key to end:- ")
    if save=='save':
        sloc=input("Enter File location to save:- ")
        name=input('Enter Name with which to save:- \n*NOTE:- Entering same name as existing image will replace the original image\n')
        filtered.save(sloc+'/'+ name+".png")
print("start")
filter_func()

def copyimg():
    copyloc=input("Enter image location to copy:- ")
    copopen=Image.open(copyloc)
    new_copied=copopen.copy()
    new_copied.show()
    save=input("Enter save to save OR press any key to end:- ")
    if save=='save':
        sloc=input("Enter File location to save:- ")
        name=input('Enter Name with which to save:- \n*NOTE:- Entering same name as existing image will replace the original image\n')
        new_copied.save(sloc+'/'+ name+".png")
print("start")
copyimg()