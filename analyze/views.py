from django.shortcuts import render, HttpResponse
import xml.etree.ElementTree as ET
from analyze.models import Project, File, Function, ScoreCard
import csv
import os
import json

# Create your views here.

def index(request):
    print("Work Here!")
    return render(request, 'analyze/index.html')

def calculate(request):
    print("Calculatings...")
    print("...")


    # json file 생성
    jsondict = {"name": "Project"}

    data = ET.parse("analyze/crulechk.0.xml")
    root = data.getroot()

    csv_file = open('tmp_csv', "w")
    cw = csv.writer(csv_file, delimiter=',', quotechar='|')
    cw.writerow(["\"name\"", "\"ID\""])
    cw.writerow(["\"project\"", "\"\""])
    cw.writerow(["\"directory\"", "\"1\""])

    csv_file2 = open('Reduced Metric for Function.csv', "w")
    cw2 = csv.writer(csv_file2, delimiter=',', quotechar='|')
    cw2.writerow(["\"ID\"","\"age\"", "\"value\""])
    # cw2.writerow(["\"age\"", "\"\""])
    # cw2.writerow(["\"value\"", "\"1\""])

    # 메트릭 개수는 항상 27개
    # 전체 파일 개수
    sumOfTheNumberOfFunctions = 0
    numberOfFile = 0
    totalCpntLenOfFunction = 0
    averageCpntLenOfFile = 0
    cpntLenOfFunction = 0
    numberOfFunction = 0
    totalCpntLenOfProject = 0
    TotalComplexityScore = 0
    TotalStructurednessScore = 0
    TotalUnderstandabilityScore = 0
    TotalMaintainabilityScore = 0
    TotalTestabilityScore = 0

    funcarr = []
    totalFunctionArray = []
    funcdict = {}
    filearr = []
    filedict = {}

    for child in root: # child = file
        numberOfFile += 1
        sumOfTheNumberOfFunctions += len(child[1])
        print("File Path : ", child[0].text) # 파일 경로 출력
        filedict['name'] = child[0].text

        # 파일 경로 + number of file
        cw.writerow(["\"" + child[0].text + "\"", "\"1." + str(numberOfFile) + "\""])

        print("Number of functions: ", len(child[1])) # function의 개수
        numberOfFunction = len(child[1])
        function_number = 0
        for child2 in child[1]: # 소스파일 단위로 for loop , child[1] = <functions>, child2 = <function>

            function_number += 1
            funcdict = {}
            cpntLenOfFunction = float(child2[5].text)

            totalCpntLenOfFunction += cpntLenOfFunction
            cw.writerow(["\"" + child2[0].text + "\"", "\"1." + str(numberOfFile) + "." + str(numberOfFunction) + "\""])

            # MARK : Complexity 계산 안되있음

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

            if function_number == 1:
                AverageComplexityOfFile = 0
                AverageStructurednessOfFile = 0
                AverageMaintainabilityOfFile = 0
                AverageTestabilityOfFile = 0
                AverageUnderstandabilityOfFile = 0

            tmpdict = {}
            for child3 in child2: # function 단위로 for loop, child3는 각 메트릭
                if(child3.tag == "name"):
                    funcdict['name'] = child3.text
                tmpdict[child3.tag] = child3.text
                if child3.tag == 'stmt_num':
                    if int(child3.text) > 80: # 80이하여야 한다.
                        UnderstandabilityScoreOfFunction -= 15
                        ComplexityScoreOfFunction -= 9

                if child3.tag == 'cyclomatic':
                    if int(child3.text) > 5:
                        StructurednessScoreOfFunction -= 20
                        TestabilityScoreOfFunction -= 25
                        ComplexityScoreOfFunction -= 9

                # 고유의 오퍼랜드 개수가 50개를 넘어가면 이해도가 감소할 것이다.
                if child3.tag == 'd_oprd':
                    if int(child3.text) > 50:
                        TestabilityScoreOfFunction -= 25
                        UnderstandabilityScoreOfFunction -= 15
                        ComplexityScoreOfFunction -= 9

                if child3.tag == 'd_optr':
                    if int(child3.text) > 35: # 제한은 35이다.
                        UnderstandabilityScoreOfFunction -= 15
                        ComplexityScoreOfFunction -= 9

                if child3.tag == 'cpnt_voca':
                    if int(child3.text) < 3 or int(child3.text) > 75:
                        UnderstandabilityScoreOfFunction -= 15
                        ComplexityScoreOfFunction -= 9

                if child3.tag == 'avg_stmt':
                    if float(child3.text) > 8:
                        UnderstandabilityScoreOfFunction -= 15
                        ComplexityScoreOfFunction -= 9

                if child3.tag == 'cpnt_len':
                    if int(child3.text) < 3 or int(child3.text) > 250:
                        UnderstandabilityScoreOfFunction -= 25
                        ComplexityScoreOfFunction -= 10
                # Number of Decision Statements의 총 개수는 9보다 작아야 한다.

                if child3.tag == 'dcs_stmt':
                    if int(child3.text) > 8:
                         TestabilityScoreOfFunction -= 25
                         ComplexityScoreOfFunction -= 9

                if child3.tag == 'entry_ptr':
                    if int(child3.text) != 1:
                        StructurednessScoreOfFunction -= 20

                if child3.tag == 'exit_pnt':
                    if int(child3.text) != 1:
                        StructurednessScoreOfFunction -= 20

                if child3.tag == 'strc_lv':
                    if int(child3.text) > 7:
                        StructurednessScoreOfFunction -= 20
                        ComplexityScoreOfFunction -= 9

                if child3.tag == 'uncond_num':
                    if int(child3.text) > 0:
                        StructurednessScoreOfFunction -= 20
                        TestabilityScoreOfFunction -= 25

                if child3.tag == 'ocr_oprd':
                    if int(child3.text) > 120:
                        ComplexityScoreOfFunction -= 9

                if child3.tag == 'ocr_optr':
                    if int(child3.text) > 140:
                        ComplexityScoreOfFunction -= 9

            MaintainabilityScoreOfFunction = 0.25 * ComplexityScoreOfFunction + 0.25 * StructurednessScoreOfFunction + 0.25 * TestabilityScoreOfFunction + 0.25 * UnderstandabilityScoreOfFunction
            TotalScore = (StructurednessScoreOfFunction + ComplexityScoreOfFunction + TestabilityScoreOfFunction + UnderstandabilityScoreOfFunction + MaintainabilityScoreOfFunction) / 5
            funcdict['ID'] = "1." + str(numberOfFile) + "." + str(function_number)
            funcdict['Structuredness'] = str(StructurednessScoreOfFunction)
            funcdict['Complexity'] = str(ComplexityScoreOfFunction)
            funcdict['Testability'] = str(TestabilityScoreOfFunction)
            funcdict['Understandabilty'] = str(UnderstandabilityScoreOfFunction)
            funcdict['Maintainability'] = str(MaintainabilityScoreOfFunction)
            funcdict['TotalScore'] = TotalScore
            funcdict['size'] = int(tmpdict['stmt_num'])*3
            # if(int(funcdict['TotalScore']) < 83):
            #     funcdict['color'] = "red"




            print(funcdict)
            id_ = funcdict['ID']
            for k, v in funcdict.items():
                if k == 'ID':
                    continue
                if k == 'Complexity' or k == 'Structuredness' or k == 'Testability' or k == 'Understandabilty' or k == 'Maintainability':
                    cw2.writerow(["\"" + id_ + "\"", "\"" + str(k) + "\"", "\"" + str(v) + "\""])

                print(k)
                print(v)


            funcarr.append(funcdict)
            funcdict = {}

            AverageComplexityOfFile += ComplexityScoreOfFunction
            # 마지막 function에서 그 파일의 평균 점수를 구한다.
            if function_number == numberOfFunction:
                AverageComplexityOfFile /= function_number
                TotalComplexityScore += AverageComplexityOfFile
                # totalFunctionArray 에 각 파일별로 점수를 저장한다.
                totalFunctionArray.append(funcarr)
                filedict['children'] = funcarr
                filearr.append(filedict)
                filedict = {}

            AverageTestabilityOfFile += TestabilityScoreOfFunction
            if function_number == numberOfFunction:
                funcarr = []
                AverageTestabilityOfFile /= function_number
                TotalTestabilityScore += AverageTestabilityOfFile

            AverageStructurednessOfFile += StructurednessScoreOfFunction
            if function_number == numberOfFunction:
                AverageStructurednessOfFile /= function_number
                TotalStructurednessScore += AverageStructurednessOfFile

            AverageMaintainabilityOfFile += MaintainabilityScoreOfFunction
            if function_number == numberOfFunction:
                AverageMaintainabilityOfFile /= function_number
                TotalMaintainabilityScore += AverageMaintainabilityOfFile

            AverageUnderstandabilityOfFile += UnderstandabilityScoreOfFunction
            if function_number == numberOfFunction:
                AverageUnderstandabilityOfFile /= function_number
                TotalUnderstandabilityScore += AverageUnderstandabilityOfFile

        averageCpntLenOfFile = totalCpntLenOfFunction / numberOfFunction
        totalCpntLenOfProject += averageCpntLenOfFile
        cpntLenOfFuntion = 0
        totalCpntLenOfFunction = 0

    # print("Average Cpnt length of each file in this project : ", totalCpntLenOfProject / numberOfFile)
    # print("Average Number of Function : ", sumOfTheNumberOfFunctions / numberOfFile)
    # print("Total File : ", numberOfFile) # 전체 파일 개수 출력
    # print("Average Complexity : ", TotalComplexityScore / numberOfFile)
    # print("Average Understandabilty : ", TotalUnderstandabilityScore / numberOfFile)
    # print("Average Testability : ", TotalTestabilityScore / numberOfFile)
    # print("Average Maintainability : ", TotalMaintainabilityScore / numberOfFile)
    # print("Average Structredness : ", TotalStructurednessScore / numberOfFile)

    context = {'complexity_score': TotalComplexityScore / numberOfFile,
               'understandability_score': TotalUnderstandabilityScore / numberOfFile,
               'testability_score': TotalTestabilityScore / numberOfFile,
               'maintainability_score': TotalMaintainabilityScore / numberOfFile,
               'structuredness_score': TotalStructurednessScore / numberOfFile,}

    # totalFunctionArray가 각 파일별 함수의 점수를 가지고 있다.
    # getAbnormal(totalFunctionArray)
    jsondict['children'] = filearr
    with open('Metrics.json', 'w') as outfile:
        json.dump(jsondict, outfile, sort_keys=False, indent=4,
                  ensure_ascii=False)
    print(totalFunctionArray[0])

    return render(request, 'dashboard.html', context)

def visualize(request):
    return render(request, 'analyze/visualize.html')

def getAbnormal(array):
    # array 는 각 파일의 함수를 담고있는 배열의 배열이다. 배열의 크기는 프로젝트의 파일 개수가 된다.
    fileInfoDictionary = {}
    result = []

    for index, file in enumerate(array): # file은 function 1개 이상 가지고 있는 파일이다.
        print(index+1) # 0번 부터 시작
        print("This file`s function length: ", len(file))

        for function in file:
            lv = getFunctionLevel(function)
            print(lv)

        for function in file:
            print(function)

        # 레벨로 표시 5단계 메트릭
        # normal : 0
        # lv5 : 1~3
        # lv4 : 4~6
        # lv3 : 7~9
        # lv2 : 10~12
        # lv1 : 13~

    # for child in bigArray:
    #     print(child[1])

def getFunctionLevel(function):

    badMetric = countBadMetric(function)

    if badMetric == 0:
        return "normal"

    elif badMetric < 3:
        return "lv5"

    elif badMetric < 6:
        return "lv4"

    elif badMetric < 9:
        return "lv3"

    elif badMetric < 12:
        return "lv2"

    else:
        return "lv1"

# 14개 메트릭 검사
def countBadMetric(function):
    badMetric = 0

    # average statement size가 8이상이면 복잡하다.
    if float(function["avg_stmt"]) > 7:
        badMetric += 1

    if float(function["cpnt_len"]) < 3 or float(function["cpnt_len"]) > 250:
        badMetric += 1

    # 공식으로 cyclomatic complexity를 계산해서 그 값이 15를 넘지 않아야 한다.(수정)
    if float(function["cyclomatic"]) > 15:
        badMetric += 1

    if float(function["stmt_num"]) > 80:
        badMetric += 1

    if float(function["d_oprd"]) > 50:
        badMetric += 1

    if float(function["d_optr"]) > 35:
        badMetric += 1

    if float(function["ocr_oprd"]) > 120:
        badMetric += 1

    if float(function["ocr_optr"]) > 140:
        badMetric += 1

    if float(function["cpnt_voca"]) < 3 or float(function["cpnt_voca"]) > 250:
        badMetric += 1

    if float(function["dcs_stmt"]) > 8:
        badMetric += 1

    if float(function["strc_lv"]) > 6:
        badMetric += 1

    if float(function["entry_ptr"]) != 1:
        badMetric += 1

    if float(function["exit_pnt"]) != 1:
        badMetric += 1

    if float(function["uncond_num"]) != 0:
        badMetric += 1


    return badMetric

def save(request):
    # xml 파싱
    data = ET.parse("analyze/crulechk.0.xml")
    root = data.getroot()

    # 진행률을 나타내기 위한 부분 초기화
    numoffunction = 0
    totaloffunction = len(root)
    for c in root:
        totaloffunction += len(c[1])

    # 끝

    # 프로젝트 초기화
    project = Project()
    project.name = "default"
    project.save()

    # ID값을 위한 파일 넘버 초기화
    numberOfFile = 0

    # child = File
    for child in root:
        numberOfFile += 1

        file = File(
            project = project,
            path = child[0].text,
            name = child[0].text.replace('/', "\\").split("\\")[-1],
            numberoffunctions = len(child[1]),
        )

        # 5가지 점수를 for문을 통하여 입력
        for x in child[2]:
            # worst_function은 입력받지않음
            if x.tag == 'worst_functions':
                continue
            exec("file." + x.tag + "=" + str(x.text))

        # file모델 객체를 저장
        file.save()

        # 진행률 +1 한 후 표시
        numoffunction += 1
        print("(", str(int(numoffunction / totaloffunction * 100)), "%) saving file <", file.name, "> ...")

        # ID값 생성을 위한 함수 넘버
        numberOfFunction = 0

        # child2 = function
        for child2 in child[1]:  # 소스파일을 함수 단위로 for loop

            # 함수 넘버 +1
            numberOfFunction += 1

            # 해당 File에 속하는 Function 객체 생성
            function = Function(
                file = file,
            )

            # function안에 모든 메트릭을 저장하는 for문
            for child3 in child2:
                # name은 문자열이므로 ""를 붙여준다.
                if child3.tag == 'name':
                    exec("function." + child3.tag + "=\"" + str(child3.text) + "\"")
                else:
                    exec("function." + child3.tag + "=" + str(child3.text))


            # 함수에 ID값 저장
            function.function_id = "1." + str(numberOfFile) + "." + str(numberOfFunction)

            # 함수 저장
            function.save()

            # 진행률 +1
            numoffunction += 1

            # 진행률 표시
            print("(", str(int(numoffunction / totaloffunction * 100)), "%) saving function <", function.name, "> of", file.name, "...")

    # 완료 메시지
    print("( 100 %) Done !")

    return HttpResponse("Done...")


def convert(request):
    # 초기 사전
    jsondict = {"name": "Project"}
    filearr = []
    filedict = {}
    funarr = []
    fundict = {}

    csv_file = open('home/static/data/IDofParents.csv', "w")
    cw = csv.writer(csv_file, delimiter=',', quotechar='|')
    cw.writerow(["\"name\"", "\"ID\""])
    cw.writerow(["\"project\"", "\"\""])
    cw.writerow(["\"directory\"", "\"1\""])

    csv_file2 = open('home/static/data/Metrics for each Function.csv', "w")
    cw2 = csv.writer(csv_file2, delimiter=',', quotechar='|')
    cw2.writerow(["\"ID\"", "\"age\"", "\"value\""])

    numberOfFile = 0
    numoffunction = 0
    totaloffunction = len(File.objects.all()) + len(Function.objects.all())

    project = Project.objects.first()
    # for file in project.file_set.all():
    # File별 loop
    for file in File.objects.all():
        filedict = {}

        filedict['name'] = file.name
        numberOfFile+=1
        numberOfFunction = 0
        cw.writerow(["\"" + file.name + "\"", "\"1." + str(numberOfFile) + "\""])
        funarr = []
        fundict = {}

        numoffunction += 1
        print("(", str(int(numoffunction / totaloffunction * 100)), "%) converting file <", file.name, "> ...")

        # Function별 loop
        for function in file.function_set.all():  # 소스파일 단위로 for loop
            fundict = {}
            numberOfFunction += 1
            cw.writerow(["\"" + function.name + "\"", "\"1." + str(numberOfFile) + "." + str(numberOfFunction) + "\""])

            # Metric별 loop
            for f in Function._meta.get_all_field_names():
                if f == 'file':
                    continue
                fundict[f] = getattr(function, str(f), None)

            fundict['ID'] = "1." + str(numberOfFile) + "." + str(numberOfFunction)
            funarr.append(fundict)

            numoffunction += 1
            print("(", str(int(numoffunction / totaloffunction * 100)), "%) converting function <", function.name, "> of",
                  file.name, "...")

        filedict['children'] = funarr
        filearr.append(filedict)

    jsondict['children'] = filearr

    # print(jsondict)

    with open('home/static/data/Metrics.json', 'w') as outfile:
        json.dump(jsondict, outfile, sort_keys=False, indent=4,
                  ensure_ascii=False)

    print("( 100 %) Done !")
    return HttpResponse("Done !...")

def visual(request):

    return render(request, 'visualTest.html')
