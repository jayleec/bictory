from django.shortcuts import render, HttpResponse
import xml.etree.ElementTree as ET
# Create your views here.

def index(request):
    print("Work Here!")
    return render(request, 'analyze/index.html')

def calculate(request):
    print("Calculatings...")
    print("...")

    data = ET.parse("analyze/crulechk.0.xml")
    root = data.getroot()
    print(len(root))

    # 메트릭 개수는 항상 27개
    # 전체 파일 개수
    sumOfTheNumberOfFunctions = 0
    numberOfFile = 0
    totalCpntLenOfFunction = 0
    averageCpntLenOfFile = 0
    cpntLenOfFunction = 0
    numberOfFunction = 0
    totalCpntLenOfProject = 0

    for child in root:
        numberOfFile += 1
        sumOfTheNumberOfFunctions += len(child[1])
        print("File Path : ", child[0].text) # 파일 경로 출력
        print("Number of functions: ", len(child[1])) # function의 개수
        numberOfFunction = len(child[1])
        for child2 in child[1]: # 소스파일 단위로 for loop
            print(child2[5].text) # component length 출력
            cpntLenOfFunction = float(child2[5].text)
            totalCpntLenOfFunction += cpntLenOfFunction

        averageCpntLenOfFile = totalCpntLenOfFunction / numberOfFunction
        totalCpntLenOfProject += averageCpntLenOfFile
        cpntLenOfFuntion = 0
        totalCpntLenOfFunction = 0

    print("Average Cpnt length of each file in this project : ", totalCpntLenOfProject / numberOfFile)
    print("Average Number of Function : ", sumOfTheNumberOfFunctions / numberOfFile)
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
