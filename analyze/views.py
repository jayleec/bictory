from django.shortcuts import render, HttpResponse
import xml.etree.ElementTree as ET
import sys
# Create your views here.

def index(request):
    print("Work Here!")
    return render(request, 'analyze/index.html')

def calculate(request):
    print("Calculating...")
    print("...")

    data = ET.parse("/Users/Sohn/Desktop/crulechk.0.xml")
    root = data.getroot()
    print(root[0][1][0][5].text)

    # 전체 파일 개수
    numberOfFile = 0
    for child in root:
        numberOfFile += 1
        print(child[0].text) # 파일 경로를 출력

    print("Total File : ", numberOfFile) # 전체 파일 개수 출력



    # functionsRoot = fileRoot.findall("functions")

    # for child in fileRoot:
    #     print(child[1])
    # for child in root:
    #     print(child[1].tag)
    # Find specific tag
    # file_tag = root.find("file")
    # print(file_tag.attrib)




    return HttpResponse("Calculating...")
