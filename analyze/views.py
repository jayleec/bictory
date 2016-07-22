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

            # MARK : Check

            # Number of Statements(9), Number of Distinct Operands(9), Number of Distinct Operators(9),
            # Number of Operand Occurences(9), Number of Operator Occurrences(9), Vocabulary Size(9),
            # Component Length(10), Average Statement Size(9), Cyclomatic Number(9), Number of Decision Statements(9),
            # Number of Structuring Levels(9)
            ComplexityScoreOfFunction = 100  # 메트릭이 범위를 벗어나면 그 메트릭의 비율만큼 감점

            # Complexity(25), Structuredness(25), Testability(25), Understandabilty(25)
            MaintainabilityScoreOfFunction = 100

            # Cyclomatic Number(20), Number of Entry Point(20), Number of Exit Points(20),
            # Number of Structuring Levels(20), Number of Unconditional Jumps(20)
            StructurednessScoreOfFunction = 100

            # Cyclomatic Number(25), Number of Distinct Operands(25),
            # Number of Unconditional Jumps(25), Number of Decision Statements(25)
            TestabilityScoreOfFunction = 100

            # Number of Statements(15), Number of Distinct Operands(15), Number of Distinct Operators(15),
            # Vocabulary Size(15), Average Statement Size(15), Component Length(25)
            UnderstandabilityScoreOfFunction = 100

            for child3 in child2: # function 단위로 for loop
                if child3.tag == 'stmt_num':
                    if int(child3.text) > 80: # 80이하여야 한다.
                        UnderstandabilityScoreOfFunction -= 15

                if child3.tag == 'cyclomatic':
                    if int(child3.text) > 5:
                        StructurednessScoreOfFunction -= 20
                        TestabilityScoreOfFunction -= 25

                # 고유의 오퍼랜드 개수가 50개를 넘어가면 이해도가 감소할 것이다.
                if child3.tag == 'd_oprd':
                    if int(child3.text) > 50:
                        TestabilityScoreOfFunction -= 25
                        UnderstandabilityScoreOfFunction -= 15

                if child3.tag == 'd_optr':
                    if int(child3.text) > 35: # 제한은 35이다.
                        UnderstandabilityScoreOfFunction -= 15

                if child3.tag == 'cpnt_voca':
                    if int(child3.text) < 3 or int(child3.text) > 75:
                        UnderstandabilityScoreOfFunction -= 15

                if child3.tag == 'avg_stmt':
                    if float(child3.text) > 8:
                        UnderstandabilityScoreOfFunction -= 15

                if child3.tag == 'cpnt_len':
                    if int(child3.text) < 3 or int(child3.text) > 250:
                        UnderstandabilityScoreOfFunction -= 25
                # Number of Decision Statements의 총 개수는 9보다 작아야 한다.
                if child3.tag == 'dcs_stmt':
                    if int(child3.text) > 8:
                         TestabilityScoreOfFunction -= 25

                if child3.tag == 'entry_ptr':
                    if int(child3.text) != 1:
                        StructurednessScoreOfFunction -= 20

                if child3.tag == 'exit_pnt':
                    if int(child3.text) != 1:
                        StructurednessScoreOfFunction -= 20

                if child3.tag == 'strc_lv':
                    if int(child3.text) > 7:
                        StructurednessScoreOfFunction -= 20

                if child3.tag == 'uncond_num':
                    if int(child3.text) > 0:
                        StructurednessScoreOfFunction -= 20
                        TestabilityScoreOfFunction -= 25


            funcdict['ID'] = "1." + str(numberOfFile) + "." + str(function_number) + ".Structuredness"
            funcdict['Structuredness'] = str(StructurednessScoreOfFunction)
            funcarr.append(funcdict)
            funcdict = {}

            funcdict['ID'] = "1." + str(numberOfFile) + "." + str(function_number) + ".Complexity"
            funcdict['Complexity'] = str(ComplexityScoreOfFunction)
            funcarr.append(funcdict)
            funcdict = {}

            funcdict['ID'] = "1." + str(numberOfFile) + "." + str(function_number) + ".Testability"
            funcdict['Testability'] = str(TestabilityScoreOfFunction)
            funcarr.append(funcdict)
            funcdict = {}

            funcdict['ID'] = "1." + str(numberOfFile) + "." + str(function_number) + ".Understandabilty"
            funcdict['Understandabilty'] = str(UnderstandabilityScoreOfFunction)
            funcarr.append(funcdict)
            funcdict = {}

            MaintainabilityScoreOfFunction = 0.25 * ComplexityScoreOfFunction + 0.25 * StructurednessScoreOfFunction + 0.25 * TestabilityScoreOfFunction + 0.25 * UnderstandabilityScoreOfFunction
            funcdict['ID'] = "1." + str(numberOfFile) + "." + str(function_number) + ".Maintainability"
            funcdict['Maintainability'] = str(MaintainabilityScoreOfFunction)
            funcarr.append(funcdict)


            # 이거를 Dictionnary에다가 넣어서 저장 1.100.1  (프로젝트 번호.파일 번호. 펑션 번호)


        averageCpntLenOfFile = totalCpntLenOfFunction / numberOfFunction
        totalCpntLenOfProject += averageCpntLenOfFile
        cpntLenOfFuntion = 0
        totalCpntLenOfFunction = 0

    print("Print Structredness Result")
    for i in funcarr:
        print(i)

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
