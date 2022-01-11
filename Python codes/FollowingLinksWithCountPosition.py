from urllib.request import urlopen
from bs4 import BeautifulSoup
import ssl
ctx = ssl.create_default_context()
ctx.check_hostname = False
ctx.verify_mode = ssl.CERT_NONE
def get_tags(url,count,position):
    html = urlopen(url, context=ctx).read()
    soup = BeautifulSoup(html, "html.parser")
    tags = soup('a')
    if count==0:
        print("Last url is: ",url)
        return None
    print("Retrieving: ",tags[position-1].get('href', None))
    get_tags(tags[position-1].get('href', None),count-1,position)
url=input("Enter URL: ")
count=int(input("Enter count: "))
position=int(input("Enter position: "))
get_tags(url,count,position)