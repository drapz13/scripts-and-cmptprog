#! python3
import time
import ssl
import os
import datetime
import urllib.request
import json
import requests
from bs4 import BeautifulSoup

url="http://172.16.32.222/db/"
s=urllib.request.urlopen(url)
s=s.read().decode("UTF-8")
s=s.replace('\n','\n')
orgpage=s
ajaxform=s.find("<form")
s=s[ajaxform:]
endajaxform=s.find("</form>")
#print(endajaxform)
s=s[:endajaxform+len("</form>")]


inputcols='input name='
arr=[]
prevstart=0
currend=len(s)+1
#print(s.find(inputcols))
#s=s[s.find(inputcols):]
#print(s[196+len(inputcols):])
while(True):
    inputadd=s.find(inputcols,prevstart,currend)
    #print(inputadd)
    if(inputadd==-1):
        break
    prevstart=inputadd+len(inputcols)
    printbreak=s.find('"',prevstart+1,currend)
    '''
    print(printbreak,end=" ")
    print(prevstart,end="")
    print("darpan")
    print(s[(prevstart+1):printbreak])
    '''
    arr.append(s[(prevstart+1):printbreak])
    #prevstart=s.find(inputcols,prevstart,currend)+len(inputcols)
    #print(prevstart)



datatosend= urllib.parse.urlencode({'auth[server]':'verlihub', 'auth[username]':'verlihub', 'auth[db]':'verlihub' }).encode(encoding="UTF-8")
post=urllib.request.urlopen(url,datatosend)
pos=post.read().decode("UTF-8")
pos=pos.replace('\n','\n')
print(pos)
#print(arr)
