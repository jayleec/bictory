from django.shortcuts import render, HttpResponse
import xml.etree.ElementTree as ET
import sys, getopt
import json
import csv
import re
from analyze.models import *

import locale
locale.setlocale(locale.LC_ALL, '')

import statistics
import math

# UPLOAD FILE
from .forms import GitFileForm
import git
from datetime import datetime
from .models import Upload
from .forms import UploadFileForm
from django.shortcuts import render_to_response
from django.http import HttpResponseRedirect
from django.template import RequestContext
from django.core.urlresolvers import reverse

# import cElementTree as ElementTree

# Create your views here.

def test(request):
    # data = Function.objects.all()
    # for f in data:
    #     f.test = f.check_all()
    # return render_to_response('function_table.html', {'functions': data})
    # q = request.GET.get('q', '')
    # f = open("home/static/c/" + q, 'r')
    # return HttpResponse(f, content_type='text/plain')
    # f.close()
    return render_to_response('test.html')

def code(request):
    q = request.GET.get('q', 'API05.c')
    f = open("home/static/c/" + q, 'r')
    return HttpResponse(f, content_type='text/plain')

def functiontable(request):
    data = Function.objects.all()
    for f in data:
        f.test = f.check_all()
        # print("f.test", f.test)
        if findMetric(f.test, 'cpnt_len'):
            f.test2 = f.function_id
    return render_to_response('function_table.html', {'functions': data})

# cpnt_len가 초과하는 function의 경우 true 리턴
def findMetric(function, metric):
    for f in function:
        if f == metric:
            return True



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


#git file loader
def gitLoader(request):
    if request.method == 'GET':
        #form generated
        form_git = GitFileForm(request.GET, request.FILES)
        if form_git.is_valid():
            gitUrl = form_git.cleaned_data['gitFile']
            dirname = datetime.now().strftime('%Y-%m-%d-%H-%M')
            g = git.Repo.clone_from(gitUrl, dirname)

            # Redirect to the document list after POST
            return HttpResponseRedirect(reverse("home.views.gitLoader"))

    if request.method == 'POST':
        form = UploadFileForm(request.POST, request.FILES)
        if form.is_valid():
            newdoc = Upload(Lddfile=request.FILES['Lddfile'])
            newdoc.save()

            # Redirect to the document list after POST
            return HttpResponseRedirect(reverse("home.views.gitLoader"))

    else:
        form_git = GitFileForm()  # A empty, unbound form
        form = UploadFileForm()
        files = Upload.objects.all()
    return render_to_response(
            'torch/index.html',
            {'files': files, 'form': form, 'form_git': form_git},
            context_instance=RequestContext(request)
    )

# cpnt_len초과 하는 애들 ID


#/visualTest.html/
def visual(request):
    result = d3test()
    outlierlist = result[6]

    # cpnt_len 초과 function id 뽑기
    cpntlenlist = []
    # exit_pnt 초과 리스트 뽑기
    exit_pnts = []
    # exit_pnt 초과 리스트 뽑기
    cpnt_voca_list = []

    data = Function.objects.all()
    for f in data:
        f.test = f.check_all()
        if findMetric(f.test, 'cpnt_len'):
            cpntlenlist.append(f.function_id)
        if findMetric(f.test, 'exit_pnt'):
            exit_pnts.append(f.function_id)
        if findMetric(f.test, 'cpnt_voca'):
            cpnt_voca_list.append(f.function_id)
    # print("cpntlenlist:", cpntlenlist)
    return render(request, 'visualTest.html', {'outlierId': outlierlist,
                                               'cpnt_len_id_list': cpntlenlist,
                                               'exit_pnts': exit_pnts,
                                               'cpnt_voca_list': cpnt_voca_list})

def showScore(request):
    result = d3test()
    aveComplexity = round(result[0],1)
    aveStructure = round(result[1],1)
    aveTestability = round(result[2],1)
    aveUnderstand = round(result[3],1)
    aveMaintainability = round(result[4],1)
    projectScore = round(result[5],1)
    testID = result[6]

    return render(request, 'd3_test.html', {
                                            'aveComplexity': aveComplexity,
                                            'structuredness': aveStructure,
                                            'testability': aveTestability,
                                            'understandability': aveUnderstand,
                                            'maintainability':  aveMaintainability,
                                            'projectScore': projectScore,
                                            'minimumStdVarID': testID,
                                            })


def d3test():
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
    # totalscore 리스트로 넣음
    totalscoreList = []

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
            # function 별 total 점수
            totalScoreOfFunction = (StructurednessScoreOfFunction + ComplexityScoreOfFunction + TestabilityScoreOfFunction +
            UnderstandabilityScoreOfFunction + MaintainabilityScoreOfFunction )/5

            funcdict['ID'] = "1." + str(numberOfFile) + "." + str(function_number)
            funcdict['Structuredness'] = str(StructurednessScoreOfFunction)
            funcdict['Complexity'] = str(ComplexityScoreOfFunction)
            funcdict['Testability'] = str(TestabilityScoreOfFunction)
            funcdict['Understandabilty'] = str(UnderstandabilityScoreOfFunction)
            funcdict['Maintainability'] = str(MaintainabilityScoreOfFunction)
            funcdict['totalScore'] = totalScoreOfFunction

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

    # 함수별 score를 리스트에 넣음
    tempScoreList = []
    for x in funcarr:
        tempScoreList.append(x['totalScore'])
    ave = statistics.mean(tempScoreList)
    stdDeviation = statistics.stdev(tempScoreList)
    print("stdDeviation:", stdDeviation)

    # dictionary에 각 편차를 추가함
    for x in funcarr:
        x.update({'deviation': abs(stdDeviation - math.sqrt(pow(x['totalScore']-ave,2)))})
        # print("test print:", abs(stdDeviation - math.sqrt(pow(x['totalScore']-ave,2))))

    #     deviation중에서 가장 큰 수의 ID를 리턴
    tempList = []
    for x in funcarr:
        # print("print test:", x['deviation'])
        if(x['deviation']>10):
            tempList.append(x)

    outlierList = []
    for y in tempList:
        outlierList.append(y['ID'])
    # return index of highest value in devationlist


    #프로젝트 최종 점수 계산
    aveStructure = TotalMaintainabilityScore / numberOfFile
    aveUnderstand = TotalUnderstandabilityScore / numberOfFile
    aveTestability = TotalTestabilityScore / numberOfFile
    aveMaintainability = TotalMaintainabilityScore / numberOfFile
    projectScore = cal_projectScore(aveComplexity,aveStructure, aveTestability, aveMaintainability, aveUnderstand )

    return aveComplexity, aveStructure, aveTestability, aveUnderstand, aveMaintainability, projectScore, outlierList

    #
    # return render(request, 'd3_test.html', {
    #                                         'aveComplexity': aveComplexity,
    #                                         'structuredness': aveStructure,
    #                                         'testability': aveTestability,
    #                                         'understandability': aveUnderstand,
    #                                         'maintainability':  aveMaintainability,
    #                                         'projectScore': projectScore,
    #                                         'minimumStdVarID': minimumVar['ID'],
    #                                         })



# TODO: 모든 함수 표준편차 리스트 리턴 함수 쓰기

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


def sign_up(request):
    if request.method == 'POST':
        form = SignUpForm(request.POST)

        if form.is_valid():
            u = User(
                email=cleaned_data['email'],
                password=cleaned_data['password'],
            )
            u.save()
            return HttpResponseRedirect('/')
    else:
        form = SignUpForm()

    return render(request, 'sign_up.html')



    return HttpResponse("Testing...")

def report(request):
    return render(request, 'report.html')



# convert ganwon.csv to json
def read_csv(request):
    file = 'home/static/data/gangwon.csv'
    csv_rows = []
    with open(file) as csvfile:
        reader = csv.DictReader(csvfile)
        title = reader.fieldnames
        for row in reader:
                csv_rows.extend([{title[i]:row[title[i]] for i in range(len(title))}])
        csvToCsv(csv_rows)
        csvToJson(csv_rows)
        return HttpResponse("CSV to JSON ...")

def csvToJson(data):
    jsonDict = {"name" : "Industry"}
    level1Arr = []
    jsonDict_level2 = {"name" : "Gangwon"}
    level1Arr.append(jsonDict_level2)
    fileArr = []
    cnt = 1
    for n in data:
        fileDict = {}
        fileDict['name'] = n['산업']
        fileDict['male'] = n['남']
        fileDict['female'] = n['여']
        fileDict['ID'] = "1.1." + str(cnt)
        fileArr.append(fileDict)
        cnt += 1
    jsonDict_level2['children'] = fileArr
    jsonDict['children'] = level1Arr

    with open('home/static/data/industry.json', 'w') as outfile:
        json.dump(jsonDict, outfile, sort_keys=False, indent=4,
                  ensure_ascii=False)

def csvToCsv(data):
    csv1 = open('home/static/data/industryByGender.csv', 'w')
    cw1 = csv.writer(csv1, delimiter=',',quotechar='|')
    cw1.writerow(["\"ID\"", "\"age\"", "\"value\""])

    csv2 = open('home/static/data/IDofParentLevel_industry.csv', 'w')
    cw2 = csv.writer(csv2, delimiter=',', quotechar='|')
    cw2.writerow(["\"name\"", "\"ID\""])
    cw2.writerow(["\"Gangwon\"", "\"\""])
    cw2.writerow(["\"industry\"", "\"1\""])
    cw2.writerow(["\"industry - dir\"", "\"1.1\""])

    cnt = 1

    del data[0:2]
    # print(data)

    for row in data:
        cw1.writerow(["\"1.1." + str(cnt) + "\"", "\"남자\"", "\"1\""])
        cw1.writerow(["\"1.1." + str(cnt) + "\"", "\"여자\"", "\"1\""])

        cw2.writerow(["\"" + row['산업'] + "\"", "\"1.1." + str(cnt) + "\""])
        cnt += 1


def convert(request):
    # 초기 사전
    jsondict = {"name": "Project"}

    filearr = []
    filedict = {}
    funarr = []
    fundict = {}
    s = ","
    s = locale.format_string('%s', s, True).replace(",", "")

    data = ET.parse("analyze/crulechk.0.xml")
    root = data.getroot()
    print(len(root))

    csv_file = open('IDofParents2.csv', "w")
    cw = csv.writer(csv_file, delimiter=',', quotechar='|')
    cw.writerow(["\"name\"", "\"ID\""])
    cw.writerow(["\"project\"", "\"\""])
    cw.writerow(["\"directory\"", "\"1\""])


    csv_file2 = open('Metrics for each Function.csv', "w")
    cw2 = csv.writer(csv_file2, delimiter=',', quotechar='|')
    cw2.writerow(["\"ID\"", "\"age\"", "\"value\""])

    csv_file3 = open('Wtree_test.csv', "w")
    cw3 = csv.writer(csv_file3, delimiter=',', quotechar=',')
    cw3.writerow(["Category", "Level1", "Level2", "Level3", "Level4", "Federal",s,"GovXFer", "State", "Local"])

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


            tmparr = []
            dirname = {}
            if(child[0].text[0] == '/'):
                tmparr = child[0].text.split("/c/")
                dirname = child[0].text.split("/util/")
                dirname = dirname[1].split("/c/")
            else:
                tmparr = child[0].text.split("\\c\\")
                dirname = child[0].text.split("\\util\\")
                dirname = dirname[1].split("\\c\\")
            print(tmparr[1])
            print(dirname[0])

            s = ","
            s = locale.format_string('%s', s, True).replace(",", "")

            # 새로 넣을 이름
            newMetricName = changeMetricName()
            # print("newName = ", newName)
            i = 0

            for child3 in child2:
                child3.tag = newMetricName[i]
                i += 1
                # weighted tree 사용
                if child3.tag == 'name':
                    cw3.writerow([child[0].text, child2[0].text, child3.tag + ":" + child3.text, "1." + str(numberOfFile) + str(numberOfFunction), "b", s,s,s, str(numberOfFile) + str(numberOfFunction)])
                    continue
                # #     일부 불필요한 메트릭은 사용하지 않음
                if (child3.tag == 'Component Volume' or child3.tag == 'Program Level' or
                    child3.tag == 'Program Differences' or child3.tag == 'Effeciency' or
                    child3.tag == 'Bug' or child3.tag == 'Number of Exit Points' or
                    child3.tag == 'Language Scope' or child3.tag == 'Program Time' or
                    child3.tag == 'Itergration'):
                    print("if child.tag = ", child3.tag)
                else:
                    cw2.writerow([str("\"1." + str(numberOfFile) + "." + str(numberOfFunction) + "\""), str("\"" + child3.tag + "\""), str("\"" + child3.text + "\"")])
                    cw3.writerow([tmparr[1], dirname[0], tmparr[1], child2[0].text, child3.tag + ":" + child3.text,
                                  str(numberOfFile) + str(numberOfFunction), "b", s, s, s,
                                  str(numberOfFile) + str(numberOfFunction)])



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

# 메트릭 이름이 출력시에는 원래 이름대로 나오게
# 리스트로 이름을 받아서 리스트로 반환
def changeMetricName():
    metricName = ["name",
                  "Number of Distinct Operators",
                  "Number of Distinct Operands",
                  "Number of Operator Occurrences",
                  "Number of Operand Occurrences",
                  "Component Length",
                  "Component Volume",
                  "Vocabulary Size",
                  "Program Level",
                  "Program Differences",
                  "Effeciency",
                  "Program Time",
                  "Itergration",
                  "Bug",
                  "Number of Exit Points",
                  "Number of Statements",
                  "Number of Structuring Levels",
                  "Number of Unconditional Jumps",
                  "Number of Go to Statements",
                  "Number of Decision Statements",
                  "Average Statement Size",
                  "Language Scope",
                  "Number of Function Parameters",
                  "Number of Calling Functions",
                  "Number of Called Functions",
                  "Cyclomatic Complexity",
                  "Number of Entry Points"]

    return metricName





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

#매트릭 계산기
class Calculator(dict):
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
        'cylomatic' : [0, 15],
    }

    def __init__(self, elt):
        self.dict = elt

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
