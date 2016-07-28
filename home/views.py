from django.shortcuts import render, HttpResponse
import xml.etree.ElementTree as ET
import json
import csv
import re

import locale
locale.setlocale(locale.LC_ALL, '')

import statistics


# import cElementTree as ElementTree

# Create your views here.

def index(request):
    return render(request, 'index.html')

def forms(request):
    return render(request, 'forms.html')

def dashboard(request):
    return render(request, 'dashboard.html')

def forgot_password(request):
    return render(request, 'forgot_password.html')

def tables(request):
    return render(request, 'tables.html')

def visual(request):
    return render(request, 'visualTest.html')

def d3test(request):
    tree = ET.parse("home/static/data/crulechk.0.xml")
    root = tree.getroot()

    complexity = 0
    maintainability = 0
    structuredness = 0
    testability = 0

    numOfFunctions = 0
    complexity_list = []
    aveComplexity = 0

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


    for child in root:
        #print("File Path : ", child[0].text)  # 파일 경로 출력
        numOfFunctions += len(child[1])
        numberOfFile += 1
        sumOfTheNumberOfFunctions += len(child[1])
        #print("File Path : ", child[0].text) # 파일 경로 출력
        #ßprint("Number of functions: ", len(child[1])) # function의 개수
        numberOfFunction = len(child[1])
        function_number = 0
        for child2 in child[1]:  # 소스파일 단위로 for loop
            # 컴플렉시티 계산
            complexity = cal_complexity(child2)
            complexity_list.append(complexity)
            aveComplexity = ave_complexity(complexity_list, numOfFunctions)

            #대근이가 쓴거
            function_number += 1
            funcdict = {}
            cpntLenOfFunction = float(child2[5].text)
            totalCpntLenOfFunction += cpntLenOfFunction

            # MARK : Check

            MaintainabilityScoreOfFunction = 100
            ComplexityScoreOfFunction = 100  # 메트릭이 범위를 벗어나면 그 메트릭의 비율만큼 감점
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

            for child3 in child2:  # function 단위로 for loop
                if child3.tag == 'stmt_num':
                    if int(child3.text) > 80:  # 80이하여야 한다.
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
                    if int(child3.text) > 35:  # 제한은 35이다.
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

            MaintainabilityScoreOfFunction = 0.25 * ComplexityScoreOfFunction + 0.25 * StructurednessScoreOfFunction + 0.25 * TestabilityScoreOfFunction + 0.25 * UnderstandabilityScoreOfFunction

            funcdict['ID'] = "1." + str(numberOfFile) + "." + str(function_number)
            funcdict['Structuredness'] = str(StructurednessScoreOfFunction)
            funcdict['Complexity'] = str(ComplexityScoreOfFunction)
            funcdict['Testability'] = str(TestabilityScoreOfFunction)
            funcdict['Understandabilty'] = str(UnderstandabilityScoreOfFunction)
            funcdict['Maintainability'] = str(MaintainabilityScoreOfFunction)
            funcarr.append(funcdict)
            funcdict = {}

            AverageComplexityOfFile += ComplexityScoreOfFunction
            # 마지막 function에서 그 파일의 평균 점수를 구한다.
            if function_number == numberOfFunction:
                AverageComplexityOfFile /= function_number
                TotalComplexityScore += AverageComplexityOfFile

            AverageTestabilityOfFile += TestabilityScoreOfFunction
            if function_number == numberOfFunction:
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


    #표준화변수 출력 테스트 - 'Understandability'
    print("표준편차 standardDeviation(funcarr)",standardDeviation(funcarr, "Understandabilty"))
    print("평균: ", getAverage(funcarr, "Understandabilty"))

    #표준화변수 html 출력용 변수
    #평균
    average = getAverage(funcarr, "Understandabilty")
    #표준편차
    stdDeviation = standardDeviation(funcarr, "Understandabilty")
    #표준화변수
    stdDevVar = []
    for x in funcarr:
        stdDevVar.append(getStandardizationVar(float(x["Understandabilty"]), average, stdDeviation, x["ID"]))

    print(getMinimum(stdDevVar,'stdVar'))
    minimumVar = getMinimum(stdDevVar,'stdVar')

    #프로젝트 최종 점수 계산
    aveStructure = TotalMaintainabilityScore / numberOfFile
    aveUnderstand = TotalUnderstandabilityScore / numberOfFile
    aveTestability = TotalTestabilityScore / numberOfFile
    aveMaintainability = TotalMaintainabilityScore / numberOfFile
    projectScore = cal_projectScore(aveComplexity,aveStructure, aveTestability, aveMaintainability, aveUnderstand )

    return render(request, 'd3_test.html', {
                                            'aveComplexity': aveComplexity,
                                            'structuredness': aveStructure,
                                            'testability': aveTestability,
                                            'understandability': aveUnderstand,
                                            'maintainability':  aveMaintainability,
                                            'projectScore': projectScore,
                                            'minimumStdVarID': minimumVar['ID']})

#표준화변수 구하기
#(data -  평균) / 표준편차
def getStandardizationVar(data, average, stdDeviation, id):
    result = {} #{ 표준화변수,  'ID'}
    result['stdVar'] = (data - average)/stdDeviation
    result['ID'] = id
    return result

#평균 구하기
def getAverage(data, category):
    temp = []
    for i in data:
        temp.append(float(i[category]))
    return statistics.mean(temp)

#표준편차
#딕셔너리 리스트로 받아서 표준편차 계산 표준편차값 리턴함
def standardDeviation(data, category):
    temp = []
    for i in data:
        temp.append(float(i[category]))
    return statistics.stdev(temp)

#딕셔너리 리스트 중에 특정 카테고리 가장 작은값 리턴
def getMinimum(list, category):
    return min(list, key=lambda x: x[category])



def cal_projectScore(comp, stru, text, under, main):
    return (comp + stru + text + under + main)/5


def cal_maintainability(comp, stru, test, under):
    return comp*0.25 + stru * 0.25 + test * 0.25 + under * 0.25


def cal_complexity(child2):
    sumofcom = 0
    # number of statements less 9 = 0
    if float(child2[15].text) < 9:
        sumofcom += 9
    if float(child2[2].text) < 50:
        sumofcom += 9
    if float(child2[1].text) < 35:
        sumofcom += 9
    if float(child2[4].text) < 120:
        sumofcom += 9
    if float(child2[3].text) < 140:
        sumofcom += 9
    if 3 <= float(child2[7].text) <= 75:
        sumofcom += 9
    if 3 <= float(child2[5].text) <= 250:
        sumofcom += 10
    if float(child2[20].text) < 8:
        sumofcom += 9
    if float(child2[25].text) < 15:
        sumofcom += 9
    if float(child2[19].text) < 9:
        sumofcom += 9
    if float(child2[16].text) < 7:
        sumofcom += 9
    return sumofcom

def ave_complexity(complexity_list, numOfFunctions):
    sumtemp = 0
    for c in complexity_list:
        sumtemp += c

    return sumtemp/numOfFunctions




def report(request):
    return render(request, 'report.html')

def test(request):
    data = ET.parse("analyze/crulechk.0.xml")
    root = data.getroot()

    for child in root:
        words = child[0].text
        word = words.replace('/', "\\").split("\\")
        print(word)

    return HttpResponse("Testing...")
<<<<<<< HEAD

=======
>>>>>>> f95e20643cf5a422f1e12e1f5e1283d025ab7aae

def convert(request):
    # 초기 사전
    jsondict = {"name": "Project"}

    filearr = []
    filedict = {}
    funarr = []
    fundict = {}


    data = ET.parse("analyze/crulechk.0.xml")
    root = data.getroot()
    print(len(root))

    csv_file = open('IDofParents.csv', "w")
    cw = csv.writer(csv_file, delimiter=',', quotechar='|')
    cw.writerow(["\"name\"", "\"ID\""])
    cw.writerow(["\"project\"", "\"\""])
    cw.writerow(["\"directory\"", "\"1\""])


    csv_file2 = open('Metrics for each Function.csv', "w")
    cw2 = csv.writer(csv_file2, delimiter=',', quotechar='|')
    cw2.writerow(["\"ID\"", "\"age\"", "\"value\""])

    csv_file3 = open('Wtree_test.csv', "w")
    cw3 = csv.writer(csv_file3, delimiter=',', quotechar=',')
    cw3.writerow(["Level1", "Level2", "Level3", "Federal", "GovXFer", "State", "Local"])

    # 메트릭 개수는 항상 27개
    # 전체 파일 개수
    sumOfTheNumberOfFunctions = 0
    numberOfFile = 0
    totalCpntLenOfFunction = 0
    averageCpntLenOfFile = 0
    cpntLenOfFunction = 0
    numberOfFunction = 0
    totalCpntLenOfProject = 0

    # child = File
    for child in root:
        filedict = {}

        filedict['name'] = child[0].text

        numberOfFile += 1
        sumOfTheNumberOfFunctions += len(child[1])
        print("File Path : ", child[0].text)  # 파일 경로 출력
        print("Number of functions: ", len(child[1]))  # function의 개수
        sumOfnumberOfFunction = len(child[1])

        numberOfFunction = 0

        cw.writerow(["\"" + child[0].text + "\"", "\"1." + str(numberOfFile) + "\""])

        funarr = []
        fundict = {}
        # child2 = function
        for child2 in child[1]:  # 소스파일 단위로 for loop
            fundict = {}
            numberOfFunction += 1

            cw.writerow(["\"" + child2[0].text + "\"", "\"1." + str(numberOfFile) + "." + str(numberOfFunction) + "\""])

            print(child2[5].text)  # component length 출력
            cpntLenOfFunction = float(child2[5].text)
            totalCpntLenOfFunction += cpntLenOfFunction

            fundict['size'] = int(child2[5].text) * 3
            fundict['ID'] = "1." + str(numberOfFile) + "." + str(numberOfFunction)
            fundict['name'] = child2[0].text

            funarr.append(fundict)

            s = ","
            s = locale.format_string('%s', s, True).replace(",", "")
            for child3 in child2:
                if child3.tag == 'name':
                    cw3.writerow([child[0].text, child2[0].text, child3.tag + ":" + child3.text, "1." + str(numberOfFile) + str(numberOfFunction), "b", s,s,s, "1." + str(numberOfFile) + str(numberOfFunction)])
                    continue
                cw2.writerow([str("\"1." + str(numberOfFile) + "." + str(numberOfFunction) + "\""), str("\"" + child3.tag + "\""), str("\"" + child3.text + "\"")])
                cw3.writerow([child[0].text, child2[0].text, child3.tag + ":" + child3.text, "1." + str(numberOfFile) + str(numberOfFunction), "b", s,s,s, "1." + str(numberOfFile) + str(numberOfFunction)])


        filedict['children'] = funarr

        filearr.append(filedict)

        averageCpntLenOfFile = totalCpntLenOfFunction / sumOfnumberOfFunction
        totalCpntLenOfProject += averageCpntLenOfFile
        cpntLenOfFuntion = 0
        totalCpntLenOfFunction = 0

    cw3.writerow([", , Level2, Level3, Level4,, , , , ,"])
    jsondict['children'] = filearr

    print("Average Cpnt length of each file in this project : ", totalCpntLenOfProject / numberOfFile)
    print("Average Number of Function : ", sumOfTheNumberOfFunctions / numberOfFile)
    print("Total File : ", numberOfFile)  # 전체 파일 개수 출력

    print("\n")

    with open('Metrics.json', 'w') as outfile:
        json.dump(jsondict, outfile, sort_keys=False, indent=4,
                  ensure_ascii=False)

    return HttpResponse("Converting...")

class XmlListConfig(list):
    def __init__(self, aList):
        for element in aList:
            if element:
                # treat like dict
                if len(element) == 1 or element[0].tag != element[1].tag:
                    self.append(XmlDictConfig(element))
                # treat like list
                elif element[0].tag == element[1].tag:
                    self.append(XmlListConfig(element))
            elif element.text:
                text = element.text.strip()
                if text:
                    self.append(text)


class XmlDictConfig(dict):
    '''
    Example usage:

    # >>> tree = ElementTree.parse('your_file.xml')
    # >>> root = tree.getroot()
    # >>> xmldict = XmlDictConfig(root)

    Or, if you want to use an XML string:

    # >>> root = ElementTree.XML(xml_string)
    # >>> xmldict = XmlDictConfig(root)

    And then use xmldict for what it is... a dict.
    '''
    def __init__(self, parent_element):
        if parent_element.items():
            self.update(dict(parent_element.items()))
        for element in parent_element:
            if element:
                # treat like dict - we assume that if the first two tags
                # in a series are different, then they are all different.
                if len(element) == 1 or element[0].tag != element[1].tag:
                    aDict = XmlDictConfig(element)
                # treat like list - we assume that if the first two tags
                # in a series are the same, then the rest are the same.
                else:
                    # here, we put the list in dictionary; the key is the
                    # tag name the list elements all share in common, and
                    # the value is the list itself
                    aDict = {element[0].tag: XmlListConfig(element)}
                # if the tag has attributes, add those to the dict
                if element.items():
                    aDict.update(dict(element.items()))
                self.update({element.tag: aDict})
            # this assumes that if you've got an attribute in a tag,
            # you won't be having any text. This may or may not be a
            # good idea -- time will tell. It works for the way we are
            # currently doing XML configuration files...
            elif element.items():
                self.update({element.tag: dict(element.items())})
            # finally, if there are no child tags and no attributes, extract
            # the text
            else:
                self.update({element.tag: element.text})

def Wtree_test(request):
    return render(request, 'Wtree_test.html')

<<<<<<< HEAD
class metric_controller():
=======
def convert2(request):
    data = ET.parse("analyze/crulechk.0.xml")
    root = data.getroot()
    metrics = MetricController()

    # child = File
    for child in root:
        print("File Path : ", child[0].text)  # 파일 경로 출력
        print("Number of functions: ", len(child[1]))  # function의 개수

        # child2 = function
        for child2 in child[1]:  # 소스파일 단위로 for loop
            tmpdict = {}
            # function안에 모든 메트릭을 Dictionary타입으로 변환하여 저장하는 for문
            for child3 in child2:
                if child3.tag == 'name':
                    tmpdict['name'] = child3.text
                    continue
                tmpdict[child3.tag] = int(child3.text)

            # 메트릭 컨트롤러에 저장
            metrics.append(tmpdict)
            print("Metrics : ", metrics.array)
            cal = Calculator(tmpdict)
            print("Complexity : ", cal.complexity())



    return HttpResponse("Testing...")

class MetricController():
>>>>>>> f95e20643cf5a422f1e12e1f5e1283d025ab7aae
    def __init__(self):
        self.num = 0
        self.array = []

    def append(self, dict):
        self.array.append(dict)
        self.num += 1

    def find(self, id):
        for elt in self.array:
            if elt['id'] == id:
                return elt
<<<<<<< HEAD


#매트릭 계산기
class calculator(dict):
=======
        return false


#매트릭 계산기
class Calculator(dict):
>>>>>>> f95e20643cf5a422f1e12e1f5e1283d025ab7aae
    # 매트릭의 기준 표
    # 각 매트릭의 기준 (최소치, 최대치)
    table = {
        'avg_stmt' : [0, 7],
        'cpnt_len' : [3, 250],
        'stmt_num' : [0, 80],
        'd_optr' : [0, 35],
        'd_oprd' : [0, 50],
        'ocr_optr' : [0, 140],
        'ocr_oprd' : [0, 120],
        'cpnt_voca' : [3, 75],
        'voca_size' : [3, 75],
        'dcs_stmt' : [0, 9],
        'strc_lv' : [0, 7],
        'entry_ptr' : [1, 1],
        'exit_pnt' : [1, 1],
        'uncond_num' : [0, 0],
<<<<<<< HEAD
=======
        'cylomatic' : [0, 15],
>>>>>>> f95e20643cf5a422f1e12e1f5e1283d025ab7aae
    }

    def __init__(self, elt):
        self.dict = elt


<<<<<<< HEAD
    # def return_score(self, name):
    #     # if table[name]
    #     # 최소치 이상 일 경우
    #     if table[name][0] <= self.dict[name]:
    #         # 최대치 이하일 경우
    #         if table[name][1] >= self.dict[name]:
    #             return 100  # 100점
    #         # 최소치 이상 최대치 이상
    #         else:
    #             # 2배를 넘지 않으면 점수 계산
    #             if self.dict[name] - table[name][1] >= 0:
    #                 return 100 - ((self.dict[name] - table[name][1]) / table[name][1] * 100)
    #             # 2배를 넘으면 0점
    #             else:
    #                 return 0
    #     #최소치 이하일 경우
    #     else:
    #         # 0점
    #         return 0
    #
    # def complexity(self):
    #     score['statement'] = 9
=======
    def return_score(self, name):
        # if table[name]
        # 최소치 이상 일 경우
        if self.table[name][0] <= self.dict[name]:
            # 최대치 이하일 경우
            if self.table[name][1] >= self.dict[name]:
                return 100  # 100점
            # 최소치 이상 최대치 이상
            else:
                # 2배를 넘지 않으면 점수 계산
                if self.dict[name] - self.table[name][1] >= 0:
                    return 100 - ((self.dict[name] - self.table[name][1]) / self.table[name][1] * 100)
                # 2배를 넘으면 0점
                else:
                    return 0
        #최소치 이하일 경우
        else:
            # 0점
            return 0

    def complexity(self):
        scores = {
            'stmt_num' : 9,
            'd_oprd' : 9,
            'd_optr' : 9,
            'ocr_oprd' : 9,
            'ocr_optr' : 9,
            'cpnt_voca' : 9,
            'cpnt_len' : 10,
            'avg_stmt' : 9,
            'cyclomatic' : 9,
            'dcs_stmt' : 9,
            'strc_lv' : 9,
        }
        names = ['stmt_num', 'd_oprd', 'd_optr', 'ocr_oprd', 'ocr_optr', 'cpnt_voca', 'cpnt_len', 'avg_stmt', 'cyclomatic', 'dcs_stmt', 'strc_lv']
        score = 0
        for x in names:
            print("x : ", x)
            score += self.return_score(x) * scores[x]
        return score / 1000
>>>>>>> f95e20643cf5a422f1e12e1f5e1283d025ab7aae




