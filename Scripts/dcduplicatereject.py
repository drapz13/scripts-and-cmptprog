#! python3
import time
import ssl
import os
import datetime
import urllib.request
import json
import requests
from bs4 import BeautifulSoup
import re
import subprocess

print("Enter 'search' and then 'filename' to start search for file or enter to exit . . . . .")
query,searchquery=map(str,input().split(" ",1))
timetosleep=0
#query=querylist[0]
while(query=="search"):
    counter=1
    startpagenum=1
    #searchquery=querylist[1]
    searchquery=searchquery.replace(" ","%20")
    #print(searchquery)
    url1="http://172.16.32.222/dchub/search/"+searchquery+'&page='
    url=url1+str(startpagenum)
    #print(url)
    while(True):
        s=urllib.request.urlopen(url)
        s=s.read().decode("UTF-8")
        s=s.replace('\n','\n')

        begintable = s.find("table")
        endtable = s.find("</table>")
        s=s[begintable:endtable]


        nameslist=[]
        userslist=[]
        magnetlist=[]
        sizelist=[]
        startname="dn="
        endname=">"
        startusername="users"
        endusername="<"
        startmagnet="magnet:"
        endmagnet='>'
        startsize="xl="
        endsize='&'
        counter=1
        for it,ituser,itmagnet,itsize in zip(re.finditer(startname,s),re.finditer(startusername,s),re.finditer(startmagnet,s),re.finditer(startsize,s)):
            namelocstart=s.find(startname,it.start())+3
            namelocend=s.find(endname,it.start())-1
            filename= s[namelocstart:namelocend].replace('+',' ').replace('%5B','[').replace('%5D',']')
            nameslist.append(filename)
            '''
            if(ituser.start() < it.start()) :
                ituser=ituser+1
            '''
            userlocstart=s.find('>',ituser.start())+1
            userlocend=s.find(endusername,ituser.start())
            #print(userlocstart)
            #print(userlocend)
            username= s[userlocstart:userlocend].replace('+',' ').replace('%5B','[').replace('%5D',']')
            userslist.append(username)
            
            magnetlocstart=s.find(startmagnet,itmagnet.start())
            magnetlocend=s.find(endmagnet,itmagnet.start())-1
            filemagnet= s[magnetlocstart:magnetlocend]
            magnetlist.append(filemagnet)
            
            sizelocstart=s.find(startsize,itsize.start())+3
            sizelocend=s.find(endsize,itsize.start())
            filesize= s[sizelocstart:sizelocend]
            sizelist.append(int(int(filesize)/(1024*1024)))
        for i,j,k in zip(nameslist,userslist,sizelist):
            print()
            print("File: ",end="")
            print(i)
            print("Filesize: ",end="")
            print(k,end=" MB\n")
            print("User: ",end="")
            print(j)
            print("UID : ",end="")
            print(counter)
            print()
            counter=counter+1
        #print(s)
        if len(nameslist)==0:
            print("Enter 'search' and then 'filename' to start search for file . . . . .")
            query,searchquery=map(str,input().split(" ",1))
            break
        else :
            print("Enter UIDs to start download or 'change' to change search query or Press 'enter' to Append More Results or 'exit' to exit . . . . . . ")
            uid=input()
            if(uid=='exit'):
                query='exit'
                break
            elif(uid=='change'):
                print("Enter 'search' and then 'filename' to start search for file . . . . .")
                query,searchquery=map(str,input().split(" ",1))
                break
            elif(uid!=""):
                uidlist=[]
                uidlist=map(int,uid.split())
                for i in uidlist:
                    #print(magnetlist[i-1])
                    os.startfile(magnetlist[i-1])
                startpagenum=startpagenum+1
                url=url1+str(startpagenum)

                print("Enter 'exit' to EXIT or 's' to change search query or Press 'enter' to Append More Results . . . . . . ")
                wait=input()
                if(wait=="exit"):
                    query='exit'
                    break
                elif(wait=='s'):
                    print("Enter 'search' to start search for file or enter to exit . . . . .")
                    query,searchquery=map(str,input().split(" ",1))
                    break
            elif(uid==""):            
                startpagenum=startpagenum+1
                url=url1+str(startpagenum)
