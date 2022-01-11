from bs4 import BeautifulSoup as bs
import urllib.parse, urllib.request,urllib.error

url=input("Enter a URL: ")
dict1=dict()
def get_urls(url):
    try:
        dict1[url]=dict1.get(url,0)+1
        if dict1[url]==1:
            html= urllib.request.urlopen(url).read()
            soup=bs(html,'html.parser')
            tags=soup('a')
            for tag in tags:
                print(tag.get('href', None))
                get_urls(tag.get('href',None))
    except: 
        print("End of ", url)
get_urls(url)