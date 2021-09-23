import PIL
from PIL import ImageEnhance
from PIL import ImageFilter
from PIL import Image

def saveimg(img):
    choice=input("Do you want to save the image: y/n\n").lower()
    if choice=='y':
        sloc=input("Enter File location to save:- ")
        name=input('Enter Name with which to save:- \n*NOTE:- Entering same name as existing image will replace the original image\n')
        img.save(sloc+'/'+ name+".png")
        
def blendimg():
    loc1=input("Enter Background location: ")
    loc2=input("Enter Foreground location: ")
    choice=int(input("Choose Transparency:-\n1)More background\n2)50-50\n3)More foreground\nPress any key for custon alpha"))
    if choice==1:
        alpha=0.3
    elif choice==2:
        alpha=0.5
    elif choice==3:
        alpha=0.7
    else:
        alpha=float(input("Enter alpha(Background fraction(from 0-1)): "))
    image1=Image.open(loc1).convert("RGBA")
    image2=Image.open(loc2).convert("RGBA")
    #print(image1.size)
    #print(image1.size)
    image1.thumbnail(image2.size)
    img1_edit=image1.resize(image2.size)
    blend=Image.blend(img1_edit,image2,alpha)
    blend.show()
    saveimg(blend)
print("start")  
#blendimg()

def alphimg():
    aloc1=input("Enter Background  ")
    aloc2=input("Enter Foreground  ")
    print("*NOTE-If foreground is not RGBA and has tranceparency, only Foreground is shown")
    aimage1=Image.open(aloc1).convert("RGBA")
    aimage2=Image.open(aloc2).convert("RGBA")
    aimage1.thumbnail(aimage2.size)
    aimg1_edit=aimage1.resize(aimage2.size)
    amix=Image.alpha_composite(aimg1_edit,aimage2)
    amix.show()
    saveimg(amix)
print("start")
alphimg()

def compimg():
    cloc1=input("Enter Background  ")
    cloc2=input("Enter Foreground  ")
    cloc3=input("Enter third img  ")
    print("*NOTE-Third image is cut from foreground to show background, so 3rd should of transperent type")
    cimage1=Image.open(cloc1).convert("RGBA")
    cimage2=Image.open(cloc2).convert("RGBA")
    cimage3=Image.open(cloc3).convert("RGBA")
    cimage1.thumbnail(cimage2.size)
    cimg1_edit=cimage1.resize(cimage2.size)
    cimage3.thumbnail(cimage2.size)
    cimg3_edit=cimage3.resize(cimage2.size)
    compos=Image.composite(cimg1_edit,cimage2,cimg3_edit)
    compos.show()
    saveimg(compos)
print("start")
##compimg()

def newimg():
    mode1=input("Enter Mode:RGB, RGBA or L  ")
    size1=int(input("Enter size:\nWidth  "))
    size2=int(input("Enter size:\nHeight  "))
    colour1=input("Enter colour:\nBlack\nWhite\nRed\nMaroon\nMagenta\nLime\nGreen\nTeal\nBlue\nCyan\nNavy\nPurple\nYellow\nOlive\nSilver\nGrey\n")
    if colour1=="Black" and mode1!='L':
        makenew=Image.new(mode1,(size1,size2),(0,0,0))
    elif colour1=="White" and mode1!='L':
        makenew=Image.new(mode1,(size1,size2),(255,255,255))
    elif colour1=="Red" and mode1!='L':
        makenew=Image.new(mode1,(size1,size2),(255,0,0))
    elif colour1=="Maroon" and mode1!='L':
        makenew=Image.new(mode1,(size1,size2),(128,0,0))
    elif colour1=="Magenta" and mode1!='L':
        makenew=Image.new(mode1,(size1,size2),(255,0,255))
    elif colour1=="Lime" and mode1!='L':
        makenew=Image.new(mode1,(size1,size2),(0,255,0))
    elif colour1=="Green" and mode1!='L':
        makenew=Image.new(mode1,(size1,size2),(0,128,0))
    elif colour1=="Teal" and mode1!='L':
        makenew=Image.new(mode1,(size1,size2),(0,128,128))
    elif colour1=="Blue" and mode1!='L':
        makenew=Image.new(mode1,(size1,size2),(0,0,255))
    elif colour1=="Cyan" and mode1!='L':
        makenew=Image.new(mode1,(size1,size2),(0,255,255))
    elif colour1=="Navy" and mode1!='L':
        makenew=Image.new(mode1,(size1,size2),(0,0,128))
    elif colour1=="Purple" and mode1!='L':
        makenew=Image.new(mode1,(size1,size2),(128,0,128))
    elif colour1=="Yellow" and mode1!='L':
        makenew=Image.new(mode1,(size1,size2),(255,255,0))
    elif colour1=="Olive" and mode1!='L':
        makenew=Image.new(mode1,(size1,size2),(128,128,0))
    elif colour1=="Silver" and mode1!='L':
        makenew=Image.new(mode1,(size1,size2),(192,192,192))
    elif colour1=="Green" and mode1!='L':
        makenew=Image.new(mode1,(size1,size2),(128,128,128))
    elif colour1=="Black" and mode1=='L':
        makenew=Image.new(mode1,(size1,size2),0)
    elif colour1=="White" and mode1=='L':
        makenew=Image.new(mode1,(size1,size2),255)
    else:
        print("Mode and colour not compatible ")
    makenew.show()
    saveimg(makenew)

print("start")
newimg()

def flipimg():
    image1=input("Enter Image  ")
    flip=input("Enter Image orientation \n1)Flip Left to Right\n2)Flip Top to Bottom\n3)Transpose\n4)Transverse\n")
    oimage1=Image.open(image1)
    if flip=="1":
        dis=oimage1.transpose(PIL.Image.FLIP_LEFT_RIGHT)
    elif flip=="2":
        dis=oimage1.transpose(PIL.Image.FLIP_TOP_BOTTOM)
    elif flip=="3":
        dis=oimage1.transpose(PIL.Image.TRANSPOSE)
    elif flip=="4":
        dis=oimage1.transpose(PIL.Image.TRANSVERSE)
    dis.show()
    saveimg(dis)

print("start")
flipimg()