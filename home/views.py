from django.shortcuts import render, HttpResponse
import xml.etree.ElementTree as ET
import json
import csv

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

    for child in root:
        #print("File Path : ", child[0].text)  # 파일 경로 출력
        numOfFunctions += len(child[1])
        for child2 in child[1]:  # 소스파일 단위로 for loop
            complexity = cal_complexity(child2)
            complexity_list.append(complexity)
            aveComplexity = ave_complexity(complexity_list,numOfFunctions)


            rest_result = []
            rest_result = cal_rest(child2) # structure, test, understand 값이 리스트로 담김
            maintainability = cal_maintainability(aveComplexity, rest_result[0], rest_result[1], rest_result[2])

    return render(request, 'd3_test.html', {'complexity_list': complexity_list ,
                                            'aveComplexity': aveComplexity,
                                            'structuredness': rest_result[0],
                                            'testability': rest_result[1],
                                            'understandability': rest_result[2],
                                            'maintainability': maintainability})

def cal_maintainability(comp, stru, test, under):
    return comp*0.25 + stru * 0.25 + test * 0.25 + under * 0.25


def cal_rest(child2):
    structurednessScoreOfFunction = 100
    testabilityScoreOfFunction = 100
    understandabilityScoreOfFunction = 100

    result = []

    for child3 in child2:  # function 단위로 for loop
        if child3.tag == 'stmt_num':
            if int(child3.text) > 80:  # 80이하여야 한다.
                understandabilityScoreOfFunction -= 15

        if child3.tag == 'cyclomatic':
            if int(child3.text) > 5:
                structurednessScoreOfFunction -= 20
                testabilityScoreOfFunction -= 25

        # 고유의 오퍼랜드 개수가 50개를 넘어가면 이해도가 감소할 것이다.
        if child3.tag == 'd_oprd':
            if int(child3.text) > 50:
                testabilityScoreOfFunction -= 25
                understandabilityScoreOfFunction -= 15

        if child3.tag == 'd_optr':
            if int(child3.text) > 35:  # 제한은 35이다.
                understandabilityScoreOfFunction -= 15

        if child3.tag == 'cpnt_voca':
            if int(child3.text) < 3 or int(child3.text) > 75:
                understandabilityScoreOfFunction -= 15

        if child3.tag == 'avg_stmt':
            if float(child3.text) > 8:
                understandabilityScoreOfFunction -= 15

        if child3.tag == 'cpnt_len':
            if int(child3.text) < 3 or int(child3.text) > 250:
                understandabilityScoreOfFunction -= 25
        # Number of Decision Statements의 총 개수는 9보다 작아야 한다.
        if child3.tag == 'dcs_stmt':
            if int(child3.text) > 8:
                testabilityScoreOfFunction -= 25

        if child3.tag == 'entry_ptr':
            if int(child3.text) != 1:
                structurednessScoreOfFunction -= 20

        if child3.tag == 'exit_pnt':
            if int(child3.text) != 1:
                structurednessScoreOfFunction -= 20

        if child3.tag == 'strc_lv':
            if int(child3.text) > 7:
                structurednessScoreOfFunction -= 20

        if child3.tag == 'uncond_num':
            if int(child3.text) > 0:
                structurednessScoreOfFunction -= 20
                testabilityScoreOfFunction -= 25
        result.append(structurednessScoreOfFunction)
        result.append(testabilityScoreOfFunction)
        result.append(understandabilityScoreOfFunction)
        print("result: ", result[0], result[1], result[2])
        return result

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
            fundict['name'] = child2[0].text
            fundict['size'] = str(int(child2[5].text) * 3)
            fundict['ID'] = "1." + str(numberOfFile) + "." + str(numberOfFunction)
            funarr.append(fundict)

            for child3 in child2:
                if child3.tag == 'name':
                    continue
                cw2.writerow([str("\"1." + str(numberOfFile) + "." + str(numberOfFunction) + "\""), str("\"" + child3.tag + "\""), str("\"" + child3.text + "\"")])


        filedict['children'] = funarr

        filearr.append(filedict)

        averageCpntLenOfFile = totalCpntLenOfFunction / sumOfnumberOfFunction
        totalCpntLenOfProject += averageCpntLenOfFile
        cpntLenOfFuntion = 0
        totalCpntLenOfFunction = 0

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
