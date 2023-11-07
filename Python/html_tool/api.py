from bs4 import BeautifulSoup
import json
import requests
import os
import time

from msg import *

class Debug():
    
    def __init__(self, log:bool=False, **headers) -> None:
        self.log = True if log else False
        self.headers = headers if headers else dict()
        self.rec = False
    
    def listen(self):
        if self.log: print(f"{INFO}Listen mod activated{TAIL}")
        inp = input(":")
        args = inp.split()
        while args[0] != "exit":
            if self.log: print(f"{INFO}args: {args}{TAIL}")
            if len(args) > 1:
                self.eval(args[0])(*args[1:])
            else:
                self.eval(args[0])
            inp = input(":")
            args = inp.split()
        if self.log: print(f"{INFO}Listen mod exited{TAIL}")

    def get(self, f, url, params):
        requests.get(url=url, params=params, headers=self.headers)

    def man(self):
        with open("manual.txt", "r") as f:
            print(f.read())

    # def make_soup(self, html, name=None):
    #     self.soup = BeautifulSoup(html, "lxml")
    #     self.soup_name = name
    
    # def find(self, tag, **attrs):
    #     ret = self.soup.find(tag, attrs=attrs)
    #     if (ret == None) and self.log:
    #         raise Exception(f"{ERRO}Empty tag: {tag} in soup: {self.soup_name}{TAIL}")
    #     return ret
    
    # def record(self, filename):
    #     self.f = open(filename, "w")
    #     self.rec = True
    
    # def debug(self):
    #     if self.log: print(f"{INFO}Debug mod activated{TAIL}")
    #     inp = input(":")
    #     args = inp.split()
    #     while args[0] != "exit":
    #         if self.log: print(f"{INFO}args: {args}{TAIL}")
    #         self.eval(args[0])(*args[1:])
    #         inp = input(":")
    #         args = inp.split()
    
    # def rd(self, line):
    #     for i in self.soup.contents.split("\n")[:line]:
    #         print(i)
    
if __name__ == "__main__":
    Debug(log=True).listen()