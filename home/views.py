from django.shortcuts import render, HttpResponse
import xml.etree.ElementTree as ET
import json
import csv

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




    #표준편차 출력
    print("standardDeviation(funcarr)",standardDeviation(funcarr))
    print(get1(funcarr))

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
                                            'projectScore': projectScore})

def getIntegerParts(data):
    return int(data)

def getFractionalParts(data):
    return data - int(data)

#딕셔너리 리스트로 받아서 표준편차 계산 표준편차값 리턴함
def standardDeviation(data):
    temp = []
    for i in data:
        print(i["Understandabilty"])
        temp.append(float(i["Understandabilty"]))
    return statistics.variance(temp)

#1사분위수
def get1(data):
    temp = []
    for i in data:
        temp.append(float(i["Understandabilty"]))

    dataLength = len(temp)
    print("data length = ",dataLength)
    order = float(dataLength + 1.0)/4.0

    intPart = getIntegerParts(order)
    fractionalPart = getFractionalParts(order)

    leftWeight = 1 - fractionalPart
    rightWeight = fractionalPart

    target1 = temp[intPart - 1]
    target2 = temp[intPart]

    return target1*leftWeight + target2+rightWeight


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



def convert(request):

    # with open('data.txt', 'w') as f:
    #     json.dump(data, f, ensure_ascii=False)

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
    cw3.writerow(["Category", "Level1", "Level2", "Level3", "Level4", "Federal", "GovXFer", "State", "Local"])



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
        # tmp = []
        # tmp = child[0].text
        # # if(child[0].text[0] == '\\'):
        # #     tmp = tmp.split('\\testcode\c\\')
        # # else:
        # #     tmp = tmp.split('/testcode/c/')
        # # print(tmp[1])
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
            fundict['name'] = child2[0].text
            fundict['size'] = str(int(child2[5].text) * 3)
            fundict['ID'] = "1." + str(numberOfFile) + "." + str(numberOfFunction)
            funarr.append(fundict)

            s = ","
            s = locale.format_string('%s', s, True).replace(",", "")
            for child3 in child2:
                if child3.tag == 'name':
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

    # print(json.dumps(jsondict, sort_keys=True, indent=4))

    # with open('data.txt', 'w') as f:
    #     json.dumps(jsondict, sort_keys=True, indent=4)

    # with open('data.txt', 'w') as outfile:
    #     json.dump(jsondict, outfile)

    with open('Metrics.json', 'w') as outfile:
        json.dump(jsondict, outfile, sort_keys=True, indent=4,
                  ensure_ascii=False)

    # with open('data.txt', 'w') as f:
    #     json.dump(data, f, ensure_ascii=False)

    # xmldict = XmlDictConfig(root)

    # data = ET.parse("analyze/crulechk.0.xml")
    # print(data)
    # print(data.get("metric"))
    # note = data.getroot()
    # print(len(note))
    # print(note.keys())
    # print(note.items())
    # print(note.get("metric"))
    # print(xmldict)
    # print(json.dumps(data, sort_keys=True, indent=4))
    # print(xmldict.get('metric'))
    # print(xmldict['metric'])
    # print(type(xmldict))
    # # print(dict(xmldict))
    # # print(type(dict(xmldict)))



    # xmldict = dict(xmldict)
    # xmldict = xmldict['file']

    # print(xmldict)
    # for k in xmldict.keys():
    #     print(k)

    # for k, v in xmldict.items():
    #     print(k,v)
    #     print("\n")
    #     for k2, v2 in v.items():
    #         print(k2, v2)
    #         print("\n")



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
