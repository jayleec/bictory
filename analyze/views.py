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
    StructurednessScoreOfFile = 0

    funcarr = []
    funcdict = {}

    for child in root:
        numberOfFile += 1
        sumOfTheNumberOfFunctions += len(child[1])
        print("File Path : ", child[0].text) # 파일 경로 출력
        print("Number of functions: ", len(child[1])) # function의 개수
        numberOfFunction = len(child[1])
        function_number = 0
        for child2 in child[1]: # 소스파일 단위로 for loop
            function_number += 1
            funcdict = {}
            # print(child2[5].text) # component length 출력
            cpntLenOfFunction = float(child2[5].text)
            totalCpntLenOfFunction += cpntLenOfFunction
            # structuredness 계산
            # MARK : Check
            StructurednessScoreOfFile = 100 # 메트릭 범위가 벗어나면 감점하는 식으로
            for child3 in child2: # function 단위로 for loop
                if child3.tag == 'cyclomatic':
                    if int(child3.text) > 5:
                        StructurednessScoreOfFile -= 20

                if child3.tag == 'entry_ptr':
                    if int(child3.text) != 1:
                        StructurednessScoreOfFile -= 20

                if child3.tag == 'exit_pnt':
                    if int(child3.text) != 1:
                        StructurednessScoreOfFile -= 20

                if child3.tag == 'strc_lv':
                    if int(child3.text) > 7:
                        StructurednessScoreOfFile -= 20

                if child3.tag == 'uncond_num':
                    if int(child3.text) > 0:
                        StructurednessScoreOfFile -= 20

            print("Function score(Structuredness) : ", StructurednessScoreOfFile)
            funcdict['ID'] = "1." + str(numberOfFile) + "." + str(function_number)
            funcdict['Structuredness'] = str(StructurednessScoreOfFile)
            funcarr.append(funcdict)

            # 이거를 Dictionnary에다가 넣어서 저장 1.100.1  (프로젝트 번호.파일 번호. 펑션 번호)


        averageCpntLenOfFile = totalCpntLenOfFunction / numberOfFunction
        totalCpntLenOfProject += averageCpntLenOfFile
        cpntLenOfFuntion = 0
        totalCpntLenOfFunction = 0

    print("Print Structredness Result")
    for i in funcarr:
        print(i['ID'], "Structredness Score: ",i['Structuredness'])

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

def visualize(request):
    return render(request, 'analyze/visualize.html')
